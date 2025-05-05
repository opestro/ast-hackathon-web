#include <ESPAsyncWebServer.h>
#include <ESP32Servo.h>
#include <SPI.h>
#include <MFRC522.h>
#include <WiFi.h>
#include <WebSocketsServer.h>
#include <SPIFFS.h>
#include <HTTPClient.h>

#define SS_PIN 5
#define RST_PIN 22
#define OUTPUT_PIN 4

const char* ssid = "OPPO A78";
const char* password = "123456789";
const char* webhookUrl = "https://robotstock.cscclub.space/api/rfid-webhook";

// HTML content
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Robot Control Dashboard</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://fonts.googleapis.com/css2?family=Orbitron:wght@400;700&display=swap" rel="stylesheet">
    <style>
        :root {
            --primary-color: #2196F3;
            --secondary-color: #673AB7;
            --accent-color: #00BCD4;
            --background-dark: #ffffff;
            --background-light: #f5f5f5;
            --text-color: #333333;
            --card-bg: rgba(255, 255, 255, 0.9);
        }

        body {
            font-family: 'Orbitron', sans-serif;
            background: linear-gradient(135deg, var(--background-dark), var(--background-light));
            color: var(--text-color);
            margin: 0;
            padding: 20px;
            min-height: 100vh;
            background-attachment: fixed;
        }

        .container {
            max-width: 1400px;
            margin: 0 auto;
        }

        .header {
            display: flex;
            justify-content: space-between;
            align-items: center;
            margin-bottom: 30px;
            padding: 20px;
            background: var(--card-bg);
            border-radius: 20px;
            border: 2px solid var(--primary-color);
            box-shadow: 0 0 30px rgba(33, 150, 243, 0.2);
        }

        .status {
            display: flex;
            align-items: center;
            gap: 15px;
            padding: 15px;
            background: rgba(245, 245, 245, 0.9);
            border-radius: 12px;
            border: 1px solid var(--accent-color);
        }

        .status-dot {
            width: 15px;
            height: 15px;
            border-radius: 50%;
            background: #f44336;
        }

        .controls {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
            gap: 25px;
            margin-top: 30px;
        }

        .control-group {
            background: var(--card-bg);
            padding: 25px;
            border-radius: 20px;
            border: 2px solid var(--secondary-color);
            box-shadow: 0 0 20px rgba(103, 58, 183, 0.1);
        }

        button {
            background: linear-gradient(45deg, var(--primary-color), var(--secondary-color));
            color: white;
            border: none;
            padding: 15px 30px;
            border-radius: 12px;
            cursor: pointer;
            margin: 8px;
            font-family: 'Orbitron', sans-serif;
            font-weight: bold;
            transition: all 0.3s ease;
            text-transform: uppercase;
            letter-spacing: 1px;
        }

        button:hover {
            transform: scale(1.05);
            box-shadow: 0 0 20px rgba(33, 150, 243, 0.4);
        }

        .slider-container {
            margin: 25px 0;
        }

        input[type="range"] {
            width: 100%;
            height: 10px;
            background: var(--background-light);
            border-radius: 5px;
            outline: none;
            -webkit-appearance: none;
            border: 1px solid var(--accent-color);
        }

        input[type="range"]::-webkit-slider-thumb {
            -webkit-appearance: none;
            width: 25px;
            height: 25px;
            background: var(--accent-color);
            border-radius: 50%;
            cursor: pointer;
        }

        .rfid-section {
            background: var(--card-bg);
            padding: 25px;
            border-radius: 20px;
            border: 2px solid var(--accent-color);
            margin-top: 30px;
        }

        .rfid-display {
            font-size: 1.2em;
            padding: 20px;
            background: rgba(245, 245, 245, 0.9);
            border-radius: 12px;
            margin-top: 15px;
            border: 1px solid var(--accent-color);
        }

        h1, h2 {
            color: var(--primary-color);
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>Robot Control Dashboard</h1>
            <div class="status">
                <div class="status-dot" id="connection-status"></div>
                <span id="status-text">Disconnected</span>
            </div>
        </div>

        <div class="controls">
            <div class="control-group">
                <h2>Gripper Control</h2>
                <button onclick="sendCommand('gripper_open')">Open Gripper</button>
                <button onclick="sendCommand('gripper_close')">Close Gripper</button>
            </div>

            <div class="control-group">
                <h2>Arm Control</h2>
                <button onclick="sendCommand('arm_up')">Arm Up</button>
                <button onclick="sendCommand('arm_down')">Arm Down</button>
            </div>

            <div class="control-group">
                <h2>Speed Control</h2>
                <div class="slider-container">
                    <input type="range" min="0" max="255" value="50" id="speed-slider">
                    <span id="speed-value">50</span>
                </div>
            </div>
        </div>

        <div class="rfid-section">
            <h2>RFID Scanner</h2>
            <div class="rfid-display" id="rfid-display">
                Waiting for card...
            </div>
        </div>
    </div>

    <script>
        let ws;
        let reconnectAttempts = 0;
        const maxReconnectAttempts = 5;
        const reconnectDelay = 2000; // 2 secondes

        function connectWebSocket() {
            console.log('Attempting to connect to WebSocket...');
            ws = new WebSocket('ws://' + window.location.hostname + ':81/');
            
            ws.onopen = function() {
                console.log('WebSocket Connected');
                document.getElementById('connection-status').style.background = '#4CAF50';
                document.getElementById('status-text').textContent = 'Connected';
                reconnectAttempts = 0;
            };

            ws.onclose = function() {
                console.log('WebSocket Disconnected');
                document.getElementById('connection-status').style.background = '#f44336';
                document.getElementById('status-text').textContent = 'Disconnected';
                
                // Tentative de reconnexion
                if (reconnectAttempts < maxReconnectAttempts) {
                    reconnectAttempts++;
                    console.log('Reconnection attempt ' + reconnectAttempts + ' of ' + maxReconnectAttempts);
                    setTimeout(connectWebSocket, reconnectDelay);
                }
            };

            ws.onerror = function(error) {
                console.error('WebSocket Error:', error);
            };

            ws.onmessage = function(event) {
                console.log('Received message:', event.data);
                const data = event.data;
                if (data.startsWith('RFID:')) {
                    const rfidData = data.substring(5);
                    document.getElementById('rfid-display').textContent = `Card detected: ${rfidData}`;
                }
            };
        }

        // Initialiser la connexion WebSocket au chargement de la page
        window.onload = function() {
            console.log('Page loaded, connecting to WebSocket...');
            connectWebSocket();
        };

        function sendCommand(command) {
            if (ws && ws.readyState === WebSocket.OPEN) {
                console.log('Sending command:', command);
                ws.send(command);
            } else {
                console.log('WebSocket not connected, attempting to reconnect...');
                connectWebSocket();
            }
        }

        document.getElementById('speed-slider').addEventListener('input', function(e) {
            document.getElementById('speed-value').textContent = e.target.value;
            sendCommand('speed:' + e.target.value);
        });
    </script>
</body>
</html>
)rawliteral";

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo monServo1;
Servo monServo2;
WebSocketsServer webSocket = WebSocketsServer(81);
AsyncWebServer server(80);

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
    switch(type) {
        case WStype_DISCONNECTED:
            Serial.printf("[%u] Disconnected!\n", num);
            break;
        case WStype_CONNECTED:
            {
                IPAddress ip = webSocket.remoteIP(num);
                Serial.printf("[%u] Connected from %d.%d.%d.%d\n", num, ip[0], ip[1], ip[2], ip[3]);
                // Envoyer un message de confirmation de connexion
                webSocket.sendTXT(num, "connected");
            }
            break;
        case WStype_TEXT:
            String command = String((char*)payload);
            Serial.printf("[%u] Received text: %s\n", num, command);
            
            if (command == "gripper_open") {
                monServo1.write(0);
            } else if (command == "gripper_close") {
                monServo1.write(120);
            } else if (command == "arm_up") {
                monServo2.write(120);
            } else if (command == "arm_down") {
                monServo2.write(0);
            } else if (command.startsWith("speed:")) {
                int speed = command.substring(6).toInt();
                // Implémenter le contrôle de vitesse ici
            }
            break;
    }
}

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
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send_P(200, "text/html", index_html);
    });

    server.on("/command", HTTP_GET, [](AsyncWebServerRequest *request){
        String cmd = request->getParam("cmd")->value();
        if (cmd == "gripper_open") {
            monServo1.write(0);
        } else if (cmd == "gripper_close") {
            monServo1.write(120);
        } else if (cmd == "arm_up") {
            monServo2.write(120);
        } else if (cmd == "arm_down") {
            monServo2.write(0);
        }
        request->send(200, "text/plain", "Command received");
    });

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

    webSocket.begin();
    webSocket.onEvent(webSocketEvent);
    Serial.println("WebSocket server started");
}

void sendRfidDataToWebhook(String rfidData, String cardType) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        
        // Format the JSON payload
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
    // This is a placeholder function - in a real application, you'd have a database
    // or some logic to determine the card type based on its ID
    // For now, we'll use a simple algorithm based on the first byte
    
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
    webSocket.loop();
    
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
    }
}
 