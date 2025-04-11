<template>
  <div class="bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5">
    <h2 class="text-base font-medium mb-5 text-gray-800 dark:text-white flex items-center">
      <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-yellow-500 dark:text-yellow-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
        <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 8v4l3 3m6-3a9 9 0 11-18 0 9 9 0 0118 0z" />
      </svg>
      Recent Activities
    </h2>
    
    <div class="space-y-4">
      <div v-for="activity in activities" :key="activity.id" class="relative pl-6 pb-5 last:pb-0">
        <!-- Timeline dot & line -->
        <div class="absolute left-0 top-0 bottom-0 flex items-start justify-center">
          <div :class="`h-3 w-3 rounded-full ${activity.type === 'package' ? 'bg-blue-400' : activity.type === 'robot' ? 'bg-purple-400' : 'bg-green-400'} z-10`"></div>
          <div class="absolute top-3 bottom-0 w-px bg-gray-200 dark:bg-gray-700"></div>
        </div>
        
        <div class="space-y-1">
          <p class="text-sm text-gray-800 dark:text-white">{{ activity.message }}</p>
          <p class="text-xs text-gray-500 dark:text-gray-400">{{ activity.time }}</p>
        </div>
      </div>
    </div>
  </div>
</template>

<script setup>
import { defineProps } from 'vue';

const props = defineProps({
  activities: {
    type: Array,
    required: true
  }
});
</script> 