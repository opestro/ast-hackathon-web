<template>
  <div class="p-6 md:p-8">
    <!-- Monitor Header -->
    <div class="flex flex-col md:flex-row justify-between items-start md:items-center mb-6">
      <div>
        <h1 class="text-2xl md:text-3xl font-bold text-gray-900 dark:text-white">Robot Monitor</h1>
        <p class="text-gray-600 dark:text-gray-400 mt-1">Hardware diagnostics and system logs</p>
      </div>
      <div class="flex space-x-3 mt-4 md:mt-0">
        <button class="px-4 py-2 bg-green-500 hover:bg-green-600 text-white rounded-lg shadow-md flex items-center space-x-2 transition-colors">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M4 4v5h.582m15.356 2A8.001 8.001 0 004.582 9m0 0H9m11 11v-5h-.581m0 0a8.003 8.003 0 01-15.357-2m15.357 2H15" />
          </svg>
          <span>Refresh</span>
        </button>
        <button class="px-4 py-2 bg-gray-200 dark:bg-gray-700 hover:bg-gray-300 dark:hover:bg-gray-600 text-gray-800 dark:text-white rounded-lg shadow-md flex items-center space-x-2 transition-colors">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M12 6v6m0 0v6m0-6h6m-6 0H6" />
          </svg>
          <span>Export</span>
        </button>
      </div>
    </div>

    <!-- Main Content -->
    <div class="grid grid-cols-1 lg:grid-cols-3 gap-6">
      <!-- Blueprint and Hardware Visualization Panel -->
      <div class="lg:col-span-2 bg-white dark:bg-gray-800 rounded-xl shadow-md overflow-hidden border border-gray-200 dark:border-gray-700">
        <div class="p-4 border-b border-gray-200 dark:border-gray-700 bg-gray-50 dark:bg-gray-900/50 flex justify-between items-center">
          <h2 class="font-semibold text-gray-900 dark:text-white">Hardware Blueprint</h2>
          <div class="flex space-x-2">
            <button class="p-1.5 rounded bg-gray-200 dark:bg-gray-700 text-gray-700 dark:text-gray-300 hover:bg-gray-300 dark:hover:bg-gray-600 transition-colors">
              <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M21 21l-6-6m2-5a7 7 0 11-14 0 7 7 0 0114 0z" />
              </svg>
            </button>
            <button class="p-1.5 rounded bg-gray-200 dark:bg-gray-700 text-gray-700 dark:text-gray-300 hover:bg-gray-300 dark:hover:bg-gray-600 transition-colors">
              <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M4 8V4m0 0h4M4 4l5 5m11-1V4m0 0h-4m4 0l-5 5M4 16v4m0 0h4m-4 0l5-5m11 5l-5-5m5 5v-4m0 4h-4" />
              </svg>
            </button>
          </div>
        </div>
        
        <!-- Blueprint SVG Visualization -->
        <div class="p-4 h-[500px] relative bg-gray-50 dark:bg-gray-900/30 overflow-auto" ref="blueprintContainer">
          <!-- This is a placeholder for the SVG blueprint, will be managed by the component -->
          <svg width="100%" height="100%" viewBox="0 0 800 600" class="blueprint-svg">
            <!-- ESP32 Board -->
            <g class="board-component">
              <rect x="300" y="200" width="200" height="150" rx="5" fill="#2c3e50" stroke="#34495e" stroke-width="2"/>
              <text x="400" y="185" text-anchor="middle" fill="currentColor" class="text-sm font-medium">ESP32 Microcontroller</text>
              
              <!-- GPIO Pins -->
              <g class="pin-group">
                <!-- Input Pins - Left Side -->
                <g v-for="(pin, index) in pins.filter(p => p.side === 'left')" :key="`left-${index}`" 
                   :class="['pin', getStatusClass(pin.status)]">
                  <rect :x="290" :y="220 + index * 15" width="10" height="10" :fill="getStatusColor(pin.status)" 
                        stroke="#555" stroke-width="1"/>
                  <text :x="285" :y="225 + index * 15" text-anchor="end" fill="currentColor" 
                        class="text-xs">{{ pin.label }}</text>
                </g>
                
                <!-- Output Pins - Right Side -->
                <g v-for="(pin, index) in pins.filter(p => p.side === 'right')" :key="`right-${index}`" 
                   :class="['pin', getStatusClass(pin.status)]">
                  <rect :x="500" :y="220 + index * 15" width="10" height="10" :fill="getStatusColor(pin.status)" 
                        stroke="#555" stroke-width="1"/>
                  <text :x="515" :y="225 + index * 15" text-anchor="start" fill="currentColor" 
                        class="text-xs">{{ pin.label }}</text>
                </g>
              </g>
            </g>
            
            <!-- Servo Motors -->
            <g class="component servo-1">
              <rect x="150" y="150" width="80" height="60" rx="5" fill="#3498db" stroke="#2980b9" stroke-width="2"/>
              <text x="190" y="185" text-anchor="middle" fill="white" class="text-sm font-medium">Servo 1</text>
              
              <!-- Connection Point -->
              <circle cx="230" cy="180" r="5" fill="white" stroke="#2980b9" stroke-width="1"/>
            </g>
            
            <g class="component servo-2">
              <rect x="150" y="300" width="80" height="60" rx="5" fill="#3498db" stroke="#2980b9" stroke-width="2"/>
              <text x="190" y="335" text-anchor="middle" fill="white" class="text-sm font-medium">Servo 2</text>
              
              <!-- Connection Point -->
              <circle cx="230" cy="330" r="5" fill="white" stroke="#2980b9" stroke-width="1"/>
            </g>
            
            <!-- IR Color Sensor -->
            <g class="component color-sensor">
              <rect x="600" y="230" width="100" height="70" rx="5" fill="#9b59b6" stroke="#8e44ad" stroke-width="2"/>
              <text x="650" y="265" text-anchor="middle" fill="white" class="text-sm font-medium">Color IR Sensor</text>
              
              <!-- Connection Points -->
              <circle cx="600" cy="250" r="5" fill="white" stroke="#8e44ad" stroke-width="1"/>
              <circle cx="600" cy="270" r="5" fill="white" stroke="#8e44ad" stroke-width="1"/>
            </g>
            
            <!-- Connection Wires -->
            <!-- Servo 1 to ESP32 -->
            <path d="M230,180 C260,180 280,180 290,220" :stroke="getWireColor('servo1')" stroke-width="3" fill="none"/>
            
            <!-- Servo 2 to ESP32 -->
            <path d="M230,330 C260,330 280,300 290,235" :stroke="getWireColor('servo2')" stroke-width="3" fill="none"/>
            
            <!-- ESP32 to Color Sensor (Data) -->
            <path d="M510,235 C550,235 570,250 600,250" :stroke="getWireColor('irSensorData')" stroke-width="3" fill="none"/>
            
            <!-- ESP32 to Color Sensor (Power) -->
            <path d="M510,265 C550,265 570,270 600,270" :stroke="getWireColor('irSensorPower')" stroke-width="3" fill="none"/>
          </svg>
        </div>

        <!-- Component Status Legend -->
        <div class="p-4 bg-white dark:bg-gray-800 border-t border-gray-200 dark:border-gray-700 flex flex-wrap gap-4">
          <div class="flex items-center">
            <div class="w-4 h-4 rounded-full bg-green-500 mr-2"></div>
            <span class="text-sm text-gray-600 dark:text-gray-400">Connected</span>
          </div>
          <div class="flex items-center">
            <div class="w-4 h-4 rounded-full bg-red-500 mr-2"></div>
            <span class="text-sm text-gray-600 dark:text-gray-400">Error/Disconnected</span>
          </div>
          <div class="flex items-center">
            <div class="w-4 h-4 rounded-full bg-gray-400 mr-2"></div>
            <span class="text-sm text-gray-600 dark:text-gray-400">Unused</span>
          </div>
          <div class="flex items-center">
            <div class="w-4 h-4 rounded-full bg-yellow-500 mr-2"></div>
            <span class="text-sm text-gray-600 dark:text-gray-400">Warning</span>
          </div>
        </div>
      </div>

      <!-- System Logs Panel -->
      <div class="bg-white dark:bg-gray-800 rounded-xl shadow-md overflow-hidden border border-gray-200 dark:border-gray-700">
        <div class="p-4 border-b border-gray-200 dark:border-gray-700 bg-gray-50 dark:bg-gray-900/50 flex justify-between items-center">
          <h2 class="font-semibold text-gray-900 dark:text-white">System Logs</h2>
          <div class="flex space-x-2">
            <button class="p-1.5 rounded bg-gray-200 dark:bg-gray-700 text-gray-700 dark:text-gray-300 hover:bg-gray-300 dark:hover:bg-gray-600 transition-colors">
              <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M3 4h13M3 8h9m-9 4h6m4 0l4-4m0 0l4 4m-4-4v12" />
              </svg>
            </button>
            <button class="p-1.5 rounded bg-gray-200 dark:bg-gray-700 text-gray-700 dark:text-gray-300 hover:bg-gray-300 dark:hover:bg-gray-600 transition-colors">
              <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M19 14l-7 7m0 0l-7-7m7 7V3" />
              </svg>
            </button>
          </div>
        </div>
        
        <div class="overflow-y-auto h-[500px]">
          <ul class="divide-y divide-gray-200 dark:divide-gray-700">
            <li v-for="(log, index) in systemLogs" :key="index" 
                :class="['p-3 hover:bg-gray-50 dark:hover:bg-gray-700/30', 
                         log.level === 'error' ? 'border-l-4 border-red-500' : 
                         log.level === 'warning' ? 'border-l-4 border-yellow-500' : 
                         log.level === 'success' ? 'border-l-4 border-green-500' : '']">
              <div class="flex items-start">
                <div :class="['rounded-full w-2 h-2 mt-1.5 mr-2', 
                             log.level === 'error' ? 'bg-red-500' : 
                             log.level === 'warning' ? 'bg-yellow-500' : 
                             log.level === 'success' ? 'bg-green-500' : 'bg-blue-500']"></div>
                <div class="flex-1">
                  <p class="text-sm font-medium text-gray-900 dark:text-white">{{ log.message }}</p>
                  <div class="flex items-center mt-1">
                    <span class="text-xs text-gray-500 dark:text-gray-400">{{ log.timestamp }}</span>
                    <span class="mx-1 text-gray-400 dark:text-gray-600">•</span>
                    <span class="text-xs text-gray-500 dark:text-gray-400">{{ log.component }}</span>
                  </div>
                </div>
              </div>
            </li>
          </ul>
        </div>
      </div>
    </div>

    <!-- Hardware Stats -->
    <div class="grid grid-cols-1 md:grid-cols-3 gap-6 mt-6">
      <div class="bg-white dark:bg-gray-800 rounded-xl shadow-md p-4 border border-gray-200 dark:border-gray-700">
        <div class="flex items-center">
          <div class="w-10 h-10 rounded-full bg-blue-100 dark:bg-blue-900/30 flex items-center justify-center mr-3">
            <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6 text-blue-500" fill="none" viewBox="0 0 24 24" stroke="currentColor">
              <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M9 3v2m6-2v2M9 19v2m6-2v2M5 9H3m2 6H3m18-6h-2m2 6h-2M7 19h10a2 2 0 002-2V7a2 2 0 00-2-2H7a2 2 0 00-2 2v10a2 2 0 002 2zM9 9h6v6H9V9z" />
            </svg>
          </div>
          <div>
            <p class="text-sm text-gray-500 dark:text-gray-400">CPU Usage</p>
            <div class="flex items-center">
              <p class="text-xl font-bold text-gray-900 dark:text-white">32%</p>
              <span class="ml-2 text-green-500 text-sm">Normal</span>
            </div>
          </div>
        </div>
        <div class="mt-4 h-2 bg-gray-200 dark:bg-gray-700 rounded-full overflow-hidden">
          <div class="h-full bg-blue-500 rounded-full" style="width: 32%"></div>
        </div>
      </div>

      <div class="bg-white dark:bg-gray-800 rounded-xl shadow-md p-4 border border-gray-200 dark:border-gray-700">
        <div class="flex items-center">
          <div class="w-10 h-10 rounded-full bg-green-100 dark:bg-green-900/30 flex items-center justify-center mr-3">
            <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6 text-green-500" fill="none" viewBox="0 0 24 24" stroke="currentColor">
              <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M9 17V7m0 10a2 2 0 01-2 2H5a2 2 0 01-2-2V7a2 2 0 012-2h2a2 2 0 012 2m0 10a2 2 0 002 2h2a2 2 0 002-2M9 7a2 2 0 012-2h2a2 2 0 012 2m0 10V7m0 10a2 2 0 002 2h2a2 2 0 002-2V7a2 2 0 00-2-2h-2a2 2 0 00-2 2" />
            </svg>
          </div>
          <div>
            <p class="text-sm text-gray-500 dark:text-gray-400">Memory Usage</p>
            <div class="flex items-center">
              <p class="text-xl font-bold text-gray-900 dark:text-white">1.2GB</p>
              <span class="ml-2 text-green-500 text-sm">60%</span>
            </div>
          </div>
        </div>
        <div class="mt-4 h-2 bg-gray-200 dark:bg-gray-700 rounded-full overflow-hidden">
          <div class="h-full bg-green-500 rounded-full" style="width: 60%"></div>
        </div>
      </div>

      <div class="bg-white dark:bg-gray-800 rounded-xl shadow-md p-4 border border-gray-200 dark:border-gray-700">
        <div class="flex items-center">
          <div class="w-10 h-10 rounded-full bg-yellow-100 dark:bg-yellow-900/30 flex items-center justify-center mr-3">
            <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6 text-yellow-500" fill="none" viewBox="0 0 24 24" stroke="currentColor">
              <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M13 10V3L4 14h7v7l9-11h-7z" />
            </svg>
          </div>
          <div>
            <p class="text-sm text-gray-500 dark:text-gray-400">Power</p>
            <div class="flex items-center">
              <p class="text-xl font-bold text-gray-900 dark:text-white">4.2V</p>
              <span class="ml-2 text-yellow-500 text-sm">85%</span>
            </div>
          </div>
        </div>
        <div class="mt-4 h-2 bg-gray-200 dark:bg-gray-700 rounded-full overflow-hidden">
          <div class="h-full bg-yellow-500 rounded-full" style="width: 85%"></div>
        </div>
      </div>
    </div>
  </div>
</template>

<script setup>
import { ref, onMounted, onUnmounted } from 'vue';

// Pin definitions with their statuses
const pins = ref([
  // Left side pins
  { label: 'GPIO 1', side: 'left', status: 'active', function: 'Servo 1 Control' },
  { label: 'GPIO 2', side: 'left', status: 'active', function: 'Servo 2 Control' },
  { label: 'GPIO 3', side: 'left', status: 'unused', function: 'Unused' },
  { label: 'GPIO 4', side: 'left', status: 'unused', function: 'Unused' },
  { label: 'GPIO 5', side: 'left', status: 'error', function: 'Error - Check connection' },
  { label: '3.3V', side: 'left', status: 'active', function: 'Power' },
  { label: 'GND', side: 'left', status: 'active', function: 'Ground' },
  { label: 'GPIO 6', side: 'left', status: 'unused', function: 'Unused' },
  
  // Right side pins
  { label: 'GPIO 21', side: 'right', status: 'active', function: 'IR Sensor Data' },
  { label: 'GPIO 22', side: 'right', status: 'active', function: 'IR Sensor Clock' },
  { label: 'GPIO 23', side: 'right', status: 'unused', function: 'Unused' },
  { label: '5V', side: 'right', status: 'active', function: 'Power' },
  { label: 'GND', side: 'right', status: 'active', function: 'Ground' },
  { label: 'GPIO 24', side: 'right', status: 'warning', function: 'Irregular signal' },
  { label: 'GPIO 25', side: 'right', status: 'unused', function: 'Unused' },
  { label: 'GPIO 26', side: 'right', status: 'unused', function: 'Unused' },
]);

// Connection status for wires
const connections = ref({
  servo1: 'active',
  servo2: 'active',
  irSensorData: 'active',
  irSensorPower: 'warning'
});

// System logs
const systemLogs = ref([
  { level: 'info', message: 'System initialized', timestamp: '2023-08-11 09:34:21', component: 'System' },
  { level: 'success', message: 'Servo 1 connected', timestamp: '2023-08-11 09:34:22', component: 'Hardware' },
  { level: 'success', message: 'Servo 2 connected', timestamp: '2023-08-11 09:34:22', component: 'Hardware' },
  { level: 'success', message: 'IR sensor connected', timestamp: '2023-08-11 09:34:23', component: 'Hardware' },
  { level: 'warning', message: 'IR sensor power fluctuation detected', timestamp: '2023-08-11 09:35:17', component: 'Power' },
  { level: 'error', message: 'GPIO 5 connection failed', timestamp: '2023-08-11 09:36:05', component: 'Hardware' },
  { level: 'info', message: 'Starting calibration sequence', timestamp: '2023-08-11 09:36:30', component: 'Calibration' },
  { level: 'info', message: 'Servo 1 calibrated', timestamp: '2023-08-11 09:36:45', component: 'Calibration' },
  { level: 'info', message: 'Servo 2 calibrated', timestamp: '2023-08-11 09:36:59', component: 'Calibration' },
  { level: 'info', message: 'IR sensor calibrated', timestamp: '2023-08-11 09:37:21', component: 'Calibration' },
  { level: 'info', message: 'Entering operational mode', timestamp: '2023-08-11 09:37:30', component: 'System' },
  { level: 'info', message: 'Sensor readings: R:255 G:120 B:0', timestamp: '2023-08-11 09:38:12', component: 'Sensor' },
  { level: 'warning', message: 'GPIO 24 reporting irregular signal pattern', timestamp: '2023-08-11 09:38:45', component: 'Hardware' },
  { level: 'info', message: 'Servo 1 position updated to 90°', timestamp: '2023-08-11 09:39:10', component: 'Servo' },
  { level: 'info', message: 'Servo 2 position updated to 45°', timestamp: '2023-08-11 09:39:15', component: 'Servo' }
]);

// Helper functions
const getStatusColor = (status) => {
  switch(status) {
    case 'active': return '#10b981'; // green
    case 'warning': return '#f59e0b'; // yellow
    case 'error': return '#ef4444'; // red
    case 'unused': return '#9ca3af'; // gray
    default: return '#9ca3af';
  }
};

const getStatusClass = (status) => {
  return `status-${status}`;
};

const getWireColor = (connectionId) => {
  const status = connections.value[connectionId] || 'unused';
  return getStatusColor(status);
};

// Mock system log update interval
let logInterval;

onMounted(() => {
  // Add real-time log updates
  logInterval = setInterval(() => {
    if (Math.random() > 0.7) {
      const components = ['System', 'Hardware', 'Sensor', 'Servo', 'Power', 'Calibration'];
      const levels = ['info', 'success', 'warning', 'error'];
      const levelWeights = [0.7, 0.1, 0.15, 0.05]; // More info, less errors
      
      // Weight random selection for levels
      let rand = Math.random();
      let level = levels[0];
      let sum = 0;
      for (let i = 0; i < levelWeights.length; i++) {
        sum += levelWeights[i];
        if (rand <= sum) {
          level = levels[i];
          break;
        }
      }
      
      const component = components[Math.floor(Math.random() * components.length)];
      let message = '';
      
      // Generate a message based on the component and level
      if (component === 'System') {
        message = level === 'error' ? 'System error detected' : 
                  level === 'warning' ? 'System warning: resource usage high' :
                  level === 'success' ? 'System check passed' : 'System update completed';
      } else if (component === 'Hardware') {
        message = level === 'error' ? 'Hardware connection lost' : 
                  level === 'warning' ? 'Hardware response delayed' :
                  level === 'success' ? 'Hardware check passed' : 'Hardware status nominal';
      } else if (component === 'Sensor') {
        const r = Math.floor(Math.random() * 256);
        const g = Math.floor(Math.random() * 256);
        const b = Math.floor(Math.random() * 256);
        message = `Sensor readings: R:${r} G:${g} B:${b}`;
      } else if (component === 'Servo') {
        const servoNum = Math.random() > 0.5 ? 1 : 2;
        const angle = Math.floor(Math.random() * 180);
        message = `Servo ${servoNum} position updated to ${angle}°`;
      }
      
      // Add timestamp
      const now = new Date();
      const timestamp = now.toISOString().replace('T', ' ').substring(0, 19);
      
      // Add to logs
      systemLogs.value.unshift({
        level,
        message,
        timestamp,
        component
      });
    }
  }, 3000);
});

onUnmounted(() => {
  clearInterval(logInterval);
});
</script>

<style scoped>
.blueprint-svg {
  user-select: none;
}

/* Pin Status Styles */
.pin.status-active circle,
.pin.status-active rect {
  filter: drop-shadow(0 0 2px rgba(16, 185, 129, 0.5));
}

.pin.status-error circle,
.pin.status-error rect {
  filter: drop-shadow(0 0 2px rgba(239, 68, 68, 0.5));
}

.pin.status-warning circle,
.pin.status-warning rect {
  filter: drop-shadow(0 0 2px rgba(245, 158, 11, 0.5));
}

/* Wire path animations */
path {
  transition: stroke 0.3s ease;
}

.blueprint-container {
  overflow: auto;
  position: relative;
}
</style> 