<!-- Robot Detail Side Panel -->
<template>
  <div class="fixed top-0 right-0 h-full w-96 bg-white/90 dark:bg-gray-800/90 backdrop-blur-xl shadow-xl transform transition-all duration-300 ease-in-out z-50 border-l border-gray-200/50 dark:border-white/5 overflow-y-auto"
    :class="[robot ? 'translate-x-0' : 'translate-x-full']">
    <div class="p-5">
      <div v-if="robot" class="h-full">
        <!-- Robot Header -->
        <div class="flex justify-between items-center mb-5">
          <div>
            <h2 class="text-lg font-medium text-gray-800 dark:text-white">{{ robot.id }}</h2>
            <p class="text-sm text-gray-500 dark:text-gray-400">{{ robot.model }}</p>
          </div>
          <div class="flex items-center">
            <div class="flex items-center bg-gray-100/80 dark:bg-gray-900/60 rounded-full px-4 py-1.5 mr-2">
              <div class="h-2 w-2 rounded-full bg-green-400 mr-2 animate-pulse"></div>
              <span class="text-gray-800 dark:text-white text-sm font-medium">{{ robot.status }}</span>
            </div>
            <button @click="closePanel" class="p-1 rounded-lg hover:bg-gray-100 dark:hover:bg-gray-700 text-gray-500 dark:text-gray-400">
              <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M6 18L18 6M6 6l12 12" />
              </svg>
            </button>
          </div>
        </div>
        
        <!-- Robot Stats -->
        <div class="grid grid-cols-2 gap-4 mb-6">
          <div class="bg-gray-100/80 dark:bg-gray-900/60 rounded-xl p-4">
            <p class="text-gray-500 dark:text-gray-400 text-xs uppercase tracking-wider mb-2">Battery</p>
            <div class="flex items-center">
              <div class="w-full bg-gray-200/80 dark:bg-gray-700/60 rounded-full h-1.5 mr-2">
                <div class="bg-gradient-to-r from-green-400 to-green-600 h-1.5 rounded-full" style="width: 78%"></div>
              </div>
              <span class="text-gray-800 dark:text-white font-medium">78<span class="text-xs">%</span></span>
            </div>
          </div>
          <div class="bg-gray-100/80 dark:bg-gray-900/60 rounded-xl p-4">
            <p class="text-gray-500 dark:text-gray-400 text-xs uppercase tracking-wider mb-2">Signal</p>
            <div class="flex items-center">
              <div class="w-full bg-gray-200/80 dark:bg-gray-700/60 rounded-full h-1.5 mr-2">
                <div class="bg-gradient-to-r from-blue-400 to-blue-600 h-1.5 rounded-full" style="width: 92%"></div>
              </div>
              <span class="text-gray-800 dark:text-white font-medium">92<span class="text-xs">%</span></span>
            </div>
          </div>
          <div class="bg-gray-100/80 dark:bg-gray-900/60 rounded-xl p-4">
            <p class="text-gray-500 dark:text-gray-400 text-xs uppercase tracking-wider mb-2">Packages</p>
            <p class="text-xl font-medium text-gray-800 dark:text-white">12</p>
          </div>
          <div class="bg-gray-100/80 dark:bg-gray-900/60 rounded-xl p-4">
            <p class="text-gray-500 dark:text-gray-400 text-xs uppercase tracking-wider mb-2">Distance</p>
            <p class="text-xl font-medium text-gray-800 dark:text-white">0.8<span class="text-sm font-normal"> km</span></p>
          </div>
        </div>
        
        <!-- Current Task -->
        <div class="bg-gray-100/80 dark:bg-gray-900/60 rounded-xl p-4 mb-6">
          <div class="flex justify-between items-center mb-3">
            <span class="text-gray-800 dark:text-white font-medium text-sm">Transport Blue Package</span>
            <span class="text-blue-500 dark:text-blue-400 text-xs bg-blue-100/50 dark:bg-blue-500/10 px-2 py-1 rounded-full">In Progress</span>
          </div>
          <p class="text-gray-500 dark:text-gray-400 text-sm mb-4">Move package from intake to blue storage area (B2)</p>
          <div class="flex space-x-2">
            <div class="bg-gray-200/80 dark:bg-gray-800/80 rounded-full px-3 py-1 text-xs text-gray-600 dark:text-gray-300 backdrop-blur-sm">
              Position: {{ robot.position.x.toFixed(1) }}, {{ robot.position.y.toFixed(1) }}
            </div>
            <div class="bg-gray-200/80 dark:bg-gray-800/80 rounded-full px-3 py-1 text-xs text-gray-600 dark:text-gray-300 backdrop-blur-sm">
              ETA: 5 min
            </div>
          </div>
        </div>
        
        <!-- Control Tabs -->
        <div class="mb-4">
          <div class="flex border-b border-gray-200 dark:border-gray-700">
            <button @click="controlTab = 'auto'" class="py-2 px-4 text-sm font-medium" 
              :class="controlTab === 'auto' ? 'text-green-500 dark:text-green-400 border-b-2 border-green-500 dark:border-green-400' : 'text-gray-500 dark:text-gray-400'">
              Automatic
            </button>
            <button @click="controlTab = 'manual'" class="py-2 px-4 text-sm font-medium"
              :class="controlTab === 'manual' ? 'text-green-500 dark:text-green-400 border-b-2 border-green-500 dark:border-green-400' : 'text-gray-500 dark:text-gray-400'">
              Manual Control
            </button>
          </div>
        </div>
        
        <!-- Manual Controls -->
        <div v-if="controlTab === 'manual'" class="mb-6">
          <div class="flex flex-col items-center">
            <button class="w-12 h-12 bg-gray-100/80 dark:bg-gray-900/80 hover:bg-gray-200 dark:hover:bg-gray-800 rounded-xl flex items-center justify-center transform hover:scale-105 transition-all shadow-lg">
              <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5 text-gray-600 dark:text-gray-300" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M5 15l7-7 7 7" />
              </svg>
            </button>
            <div class="flex justify-between w-full my-3">
              <button class="w-12 h-12 bg-gray-100/80 dark:bg-gray-900/80 hover:bg-gray-200 dark:hover:bg-gray-800 rounded-xl flex items-center justify-center transform hover:scale-105 transition-all shadow-lg">
                <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5 text-gray-600 dark:text-gray-300" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                  <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M10 19l-7-7m0 0l7-7m-7 7h18" />
                </svg>
              </button>
              <button class="w-16 h-16 bg-red-600/90 hover:bg-red-700 rounded-full flex items-center justify-center transform hover:scale-105 transition-all shadow-lg shadow-red-500/20 border border-red-500/30">
                <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6 text-white" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                  <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M6 18L18 6M6 6l12 12" />
                </svg>
              </button>
              <button class="w-12 h-12 bg-gray-100/80 dark:bg-gray-900/80 hover:bg-gray-200 dark:hover:bg-gray-800 rounded-xl flex items-center justify-center transform hover:scale-105 transition-all shadow-lg">
                <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5 text-gray-600 dark:text-gray-300" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                  <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M14 5l7 7m0 0l-7 7m7-7H3" />
                </svg>
              </button>
            </div>
            <button class="w-12 h-12 bg-gray-100/80 dark:bg-gray-900/80 hover:bg-gray-200 dark:hover:bg-gray-800 rounded-xl flex items-center justify-center transform hover:scale-105 transition-all shadow-lg">
              <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5 text-gray-600 dark:text-gray-300" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M19 9l-7 7-7-7" />
              </svg>
            </button>
          </div>
        </div>
        
        <!-- Automatic Controls -->
        <div v-if="controlTab === 'auto'" class="mb-6 space-y-4">
          <button @click="sendToChargingStation" class="bg-gray-100/80 dark:bg-gray-900/80 hover:bg-green-50 dark:hover:bg-green-900/20 hover:border-green-300/50 dark:hover:border-green-500/30 w-full p-3 rounded-xl text-gray-700 dark:text-white flex items-center justify-between border border-gray-200/60 dark:border-white/5 transition-all">
            <span class="flex items-center">
              <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-green-500" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M13 10V3L4 14h7v7l9-11h-7z" />
              </svg>
              Send to charging station
            </span>
            <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 text-gray-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
              <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 5l7 7-7 7" />
            </svg>
          </button>
          
          <button @click="assignNewTask" class="bg-gray-100/80 dark:bg-gray-900/80 hover:bg-blue-50 dark:hover:bg-blue-900/20 hover:border-blue-300/50 dark:hover:border-blue-500/30 w-full p-3 rounded-xl text-gray-700 dark:text-white flex items-center justify-between border border-gray-200/60 dark:border-white/5 transition-all">
            <span class="flex items-center">
              <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-blue-500" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 5H7a2 2 0 00-2 2v12a2 2 0 002 2h10a2 2 0 002-2V7a2 2 0 00-2-2h-2M9 5a2 2 0 002 2h2a2 2 0 002-2M9 5a2 2 0 012-2h2a2 2 0 012 2" />
              </svg>
              Assign new task
            </span>
            <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 text-gray-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
              <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 5l7 7-7 7" />
            </svg>
          </button>
          
          <button @click="changeZone" class="bg-gray-100/80 dark:bg-gray-900/80 hover:bg-purple-50 dark:hover:bg-purple-900/20 hover:border-purple-300/50 dark:hover:border-purple-500/30 w-full p-3 rounded-xl text-gray-700 dark:text-white flex items-center justify-between border border-gray-200/60 dark:border-white/5 transition-all">
            <span class="flex items-center">
              <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-purple-500" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M17.657 16.657L13.414 20.9a1.998 1.998 0 01-2.827 0l-4.244-4.243a8 8 0 1111.314 0z" />
                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M15 11a3 3 0 11-6 0 3 3 0 016 0z" />
              </svg>
              Change zone assignment
            </span>
            <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 text-gray-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
              <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 5l7 7-7 7" />
            </svg>
          </button>
        </div>

        <!-- Action Buttons -->
        <div class="flex space-x-2 mt-6">
          <button @click="closePanel" class="bg-gray-100 dark:bg-gray-800 text-gray-600 dark:text-gray-300 px-4 py-2 rounded-lg text-sm flex-1">Close</button>
          <button class="bg-gradient-to-r from-green-500 to-emerald-600 hover:from-green-600 hover:to-emerald-700 text-white px-4 py-2 rounded-lg text-sm flex-1 shadow-lg shadow-green-500/20 transition-all">View Details</button>
        </div>
      </div>
      <div v-else class="h-full flex items-center justify-center text-gray-400 dark:text-gray-500">
        <p>Select a robot to view details</p>
      </div>
    </div>
  </div>
</template>

<script setup>
import { ref, defineProps, defineEmits } from 'vue';

const props = defineProps({
  robot: {
    type: Object,
    default: null
  }
});

const emit = defineEmits(['close', 'sendToChargingStation', 'assignNewTask', 'changeZone']);

const controlTab = ref('auto');

const closePanel = () => {
  emit('close');
};

const sendToChargingStation = () => {
  emit('sendToChargingStation', props.robot);
};

const assignNewTask = () => {
  emit('assignNewTask', props.robot);
};

const changeZone = () => {
  emit('changeZone', props.robot);
};
</script>

<style scoped>
@keyframes ping-slow {
  0% { transform: scale(1); opacity: 1; }
  75%, 100% { transform: scale(2); opacity: 0; }
}
@keyframes pulse-slow {
  0%, 100% { opacity: 1; }
  50% { opacity: 0.7; }
}
.animate-ping-slow {
  animation: ping-slow 2s cubic-bezier(0, 0, 0.2, 1) infinite;
}
.animate-pulse-slow {
  animation: pulse-slow 2s ease-in-out infinite;
}
</style> 