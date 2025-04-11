<template>
  <div class="flex flex-col md:flex-row justify-between items-start md:items-center mb-8 gap-4">
    <div>
      <h1 class="text-2xl md:text-3xl font-light tracking-tight text-gray-900 dark:text-white">Zone <span class="font-bold">Management</span></h1>
      <p class="text-gray-500 dark:text-gray-400 mt-1 tracking-wide text-sm">Monitor and manage warehouse zones and assigned robots</p>
    </div>
    
    <!-- Controls & Zone Selection Tabs -->
    <div class="flex flex-col sm:flex-row gap-3">
      <!-- Action buttons -->
      <div class="flex items-center space-x-2">
        <!-- Fullscreen toggle -->
        <button 
          @click="toggleFullscreen" 
          class="p-2 rounded-lg bg-white/80 dark:bg-gray-800/80 text-gray-600 dark:text-gray-300 hover:bg-gray-100 dark:hover:bg-gray-700 transition-colors shadow-md border border-gray-200/50 dark:border-white/5 backdrop-blur-md relative fullscreen-toggle"
          :class="{'active-fullscreen': isFullscreen}"
        >
          <svg v-if="!isFullscreen" xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M4 8V4m0 0h4M4 4l5 5m11-1V4m0 0h-4m4 0l-5 5M4 16v4m0 0h4m-4 0l5-5m11 5v-4m0 4h-4m4 0l-5-5" />
          </svg>
          <svg v-else xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M6 18L18 6M6 6l12 12" />
          </svg>
        </button>
        
        <!-- Notifications -->
        <div class="relative">
          <button @click="toggleNotifications" class="p-2 rounded-lg bg-white/80 dark:bg-gray-800/80 text-gray-600 dark:text-gray-300 hover:bg-gray-100 dark:hover:bg-gray-700 transition-colors shadow-md border border-gray-200/50 dark:border-white/5 backdrop-blur-md">
            <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
              <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M15 17h5l-1.405-1.405A2.032 2.032 0 0118 14.158V11a6.002 6.002 0 00-4-5.659V5a2 2 0 10-4 0v.341C7.67 6.165 6 8.388 6 11v3.159c0 .538-.214 1.055-.595 1.436L4 17h5m6 0v1a3 3 0 11-6 0v-1m6 0H9" />
            </svg>
            <span v-if="unreadNotifications > 0" class="absolute -top-1 -right-1 h-5 w-5 flex items-center justify-center text-xs bg-red-500 text-white rounded-full">{{ unreadNotifications }}</span>
          </button>
        </div>
      </div>
      
      <!-- Zone Selection Tabs -->
      <div class="bg-white/80 dark:bg-gray-800/60 backdrop-blur-md rounded-xl p-1 flex shadow-lg border border-gray-200/80 dark:border-white/5">
        <button 
          v-for="zone in zones" 
          :key="zone.id"
          @click="selectZone(zone)" 
          :class="`px-4 py-2 text-sm rounded-lg transition-all ${selectedZoneId === zone.id ? 'bg-gradient-to-br from-blue-500 to-blue-600 text-white font-medium' : 'text-gray-600 dark:text-gray-400 hover:bg-gray-100/80 dark:hover:bg-gray-700/60'}`"
        >
          {{ zone.name }}
          <span v-if="zone.alerts && zone.alerts > 0" class="ml-1 inline-flex items-center justify-center h-4 w-4 text-xs bg-red-500 text-white rounded-full">{{ zone.alerts }}</span>
        </button>
      </div>
    </div>
  </div>
</template>

<script setup>
import { defineProps, defineEmits } from 'vue';

const props = defineProps({
  zones: {
    type: Array,
    required: true
  },
  isFullscreen: {
    type: Boolean,
    default: false
  },
  selectedZoneId: {
    type: String,
    required: true
  },
  unreadNotifications: {
    type: Number,
    default: 0
  }
});

const emit = defineEmits(['toggle-fullscreen', 'toggle-notifications', 'select-zone']);

const toggleFullscreen = () => {
  console.log('Toggle fullscreen clicked, current state:', props.isFullscreen);
  emit('toggle-fullscreen');
};

const toggleNotifications = () => {
  emit('toggle-notifications');
};

const selectZone = (zone) => {
  emit('select-zone', zone);
};
</script>

<style scoped>
.fullscreen-toggle {
  transition: all 0.2s ease-in-out;
  position: relative;
  overflow: hidden;
}

.fullscreen-toggle:hover {
  transform: scale(1.05);
}

.fullscreen-toggle:active {
  transform: scale(0.95);
}

.active-fullscreen {
  background: linear-gradient(135deg, #3b82f6, #1d4ed8);
  color: white;
  border-color: #1d4ed8;
}

.active-fullscreen:hover {
  background: linear-gradient(135deg, #2563eb, #1e40af);
}
</style> 