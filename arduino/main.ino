#include <WebServer.h>
#include <ESP32Servo.h>
#include <SPI.h>
#include <MFRC522.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <SPIFFS.h>

#define SS_PIN 5
#define RST_PIN 22
#define OUTPUT_PIN 4

const char* ssid = "OPPO A78";
const char* password = "123456789";
const char* webhookUrl = "https://robotstock.cscclub.space/api/rfid-webhook";

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo monServo1;
Servo monServo2;
WebServer server(80);

void setup() {
    Serial.begin(115200);
    Serial.println("Starting setup...");
    
    // Connexion WiFi
    WiFi.begin(ssid, password);
    Serial.println("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    // Configuration du serveur web
    server.on("/", HTTP_GET, handleRoot);
    server.on("/command", HTTP_GET, handleCommand);

    server.begin();
    Serial.println("HTTP server started");

    // Configuration SPI et RFID
    SPI.begin(18, 19, 23, 5); // SCK, MISO, MOSI, SS
    mfrc522.PCD_Init();
    Serial.println("Approchez votre carte RFID...");

    pinMode(OUTPUT_PIN, OUTPUT);
    digitalWrite(OUTPUT_PIN, LOW);

    monServo1.attach(25); // Gripper
    monServo2.attach(26); 
    delay(2000);
    monServo1.write(0);
    delay(2000);
    monServo1.write(120);
    delay(2000);
}

void handleRoot() {
    // Simplified HTML response without the full dashboard
    String html = "<html><head><title>Robot Control</title></head>";
    html += "<body style='font-family: Arial, sans-serif;'>";
    html += "<h1>Robot Control Interface</h1>";
    html += "<p>Robot is running. Visit <a href='https://robotstock.cscclub.space/'>https://robotstock.cscclub.space/</a> for the dashboard.</p>";
    html += "</body></html>";
    
    server.send(200, "text/html", html);
}

void handleCommand() {
    String cmd = server.arg("cmd");
    
    if (cmd == "gripper_open") {
        monServo1.write(0);
        server.send(200, "text/plain", "Gripper opened");
    } else if (cmd == "gripper_close") {
        monServo1.write(120);
        server.send(200, "text/plain", "Gripper closed");
    } else if (cmd == "arm_up") {
        monServo2.write(120);
        server.send(200, "text/plain", "Arm moved up");
    } else if (cmd == "arm_down") {
        monServo2.write(0);
        server.send(200, "text/plain", "Arm moved down");
    } else {
        server.send(400, "text/plain", "Unknown command");
    }
}

void sendRfidDataToWebhook(String rfidData, String cardType) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        
        // Format the JSON payload with a proper timestamp (milliseconds since 1970)
        // Note: ESP32 doesn't have a real-time clock by default, so this is uptime in ms
        // For a real application, you might want to add an RTC module or use NTP
        String jsonPayload = "{\"rfid\":\"" + rfidData + "\",\"type\":\"" + cardType + "\",\"timestamp\":" + String(millis()) + "}";
        
        http.begin(webhookUrl);
        http.addHeader("Content-Type", "application/json");
        
        int httpResponseCode = http.POST(jsonPayload);
        
        if (httpResponseCode > 0) {
            String response = http.getString();
            Serial.println("HTTP Response code: " + String(httpResponseCode));
            Serial.println(response);
        } else {
            Serial.print("Error on sending POST: ");
            Serial.println(httpResponseCode);
        }
        
        http.end();
    } else {
        Serial.println("WiFi not connected");
    }
}

String determineCardType(String rfidData) {
    // Extract first byte from the RFID data
    int firstByte = 0;
    if (rfidData.length() > 0) {
        // Convert hex string to integer
        String firstByteStr = rfidData.substring(0, 2);
        firstByte = strtol(firstByteStr.c_str(), NULL, 16);
    }
    
    // Determine card type based on the value
    if (firstByte < 64) {
        return "Red Card";
    } else if (firstByte < 128) {
        return "Blue Card";
    } else if (firstByte < 192) {
        return "Yellow Card";
    } else {
        return "Green Card";
    }
}

void loop() {
    // Handle HTTP requests
    server.handleClient();
    
    // Vérification RFID
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
        String rfidData = "";
        for (byte i = 0; i < mfrc522.uid.size; i++) {
            rfidData += String(mfrc522.uid.uidByte[i], HEX);
            if (i < mfrc522.uid.size - 1) rfidData += " ";
        }
        
        // Determine card type based on RFID data
        String cardType = determineCardType(rfidData);
        
        // Send the RFID data to the webhook
        sendRfidDataToWebhook(rfidData, cardType);
        
        digitalWrite(OUTPUT_PIN, HIGH);
        delay(1000);
        digitalWrite(OUTPUT_PIN, LOW);
        
        // Contrôle des servos
        monServo2.write(120);
        delay(2000);
        monServo2.write(0);
        delay(2000);
        monServo1.write(0);
        delay(2000);
        monServo1.write(120);
        delay(2000);
        monServo2.write(120);
        delay(2000);
        
        Serial.println("RFID: " + rfidData + " | Type: " + cardType);
    }
}
 