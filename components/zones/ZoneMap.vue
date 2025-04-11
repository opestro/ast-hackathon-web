<template>
  <div class="lg:col-span-2 bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5">
    <h2 class="text-base font-medium mb-5 text-gray-800 dark:text-white flex items-center">
      <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-blue-500 dark:text-blue-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
        <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 20l-5.447-2.724A1 1 0 013 16.382V5.618a1 1 0 011.447-.894L9 7m0 13l6-3m-6 3V7m6 10l4.553 2.276A1 1 0 0021 18.382V7.618a1 1 0 00-.553-.894L15 4m0 13V4m0 0L9 7" />
      </svg>
      Zone Map
    </h2>
    
    <div class="h-96 bg-gray-100/80 dark:bg-gray-900/60 rounded-xl relative">
      <!-- Zone Grid -->
      <div class="absolute inset-0 grid grid-cols-8 grid-rows-6">
        <template v-for="i in 48" :key="i">
          <div class="border border-gray-300/40 dark:border-gray-700/40"></div>
        </template>
      </div>
      
      <!-- Zone Paths -->
      <div class="absolute left-[12.5%] top-0 h-[16.67%] w-1 bg-gray-400/80 dark:bg-gray-600/80"></div>
      <div class="absolute left-[12.5%] top-[16.67%] h-1 w-[25%] bg-gray-400/80 dark:bg-gray-600/80"></div>
      <div class="absolute left-[37.5%] top-[16.67%] h-[33.33%] w-1 bg-gray-400/80 dark:bg-gray-600/80"></div>
      <div class="absolute left-[37.5%] top-[50%] h-1 w-[25%] bg-gray-400/80 dark:bg-gray-600/80"></div>
      <div class="absolute left-[62.5%] top-[50%] h-[33.33%] w-1 bg-gray-400/80 dark:bg-gray-600/80"></div>
      <div class="absolute left-[62.5%] top-[83.33%] h-1 w-[25%] bg-gray-400/80 dark:bg-gray-600/80"></div>
      <div class="absolute left-[87.5%] top-[16.67%] h-[66.67%] w-1 bg-gray-400/80 dark:bg-gray-600/80"></div>
      
      <!-- Shelves/Storage Areas -->
      <div class="absolute left-[6.25%] top-[33.33%] h-[16.67%] w-[12.5%] bg-gray-300/80 dark:bg-gray-700/80 rounded-md flex items-center justify-center text-xs text-gray-600 dark:text-gray-300">S1</div>
      <div class="absolute left-[25%] top-[33.33%] h-[16.67%] w-[12.5%] bg-gray-300/80 dark:bg-gray-700/80 rounded-md flex items-center justify-center text-xs text-gray-600 dark:text-gray-300">S2</div>
      <div class="absolute left-[50%] top-[66.67%] h-[16.67%] w-[12.5%] bg-gray-300/80 dark:bg-gray-700/80 rounded-md flex items-center justify-center text-xs text-gray-600 dark:text-gray-300">S3</div>
      <div class="absolute left-[75%] top-[33.33%] h-[16.67%] w-[12.5%] bg-gray-300/80 dark:bg-gray-700/80 rounded-md flex items-center justify-center text-xs text-gray-600 dark:text-gray-300">S4</div>
      
      <!-- Robots (as dots) -->
      <div v-for="(robot, index) in robots" :key="robot.id" 
          :class="`absolute h-3 w-3 rounded-full ${robotColors[index % robotColors.length]} shadow-lg shadow-${robotColors[index % robotColors.length].split('-')[1]}-500/20 animate-pulse`"
          :style="`left: ${robot.position.x}%; top: ${robot.position.y}%;`"
          :title="robot.id">
      </div>
      
      <!-- Zone Label -->
      <div :class="`absolute top-2 right-2 px-2 py-1 rounded-md text-xs text-white ${zoneColor.replace('from-', 'bg-').split(' ')[0]}`">
        {{ zoneName }}
      </div>
    </div>
  </div>
</template>

<script setup>
import { defineProps } from 'vue';

const props = defineProps({
  robots: {
    type: Array,
    required: true
  },
  zoneName: {
    type: String,
    required: true
  },
  zoneColor: {
    type: String,
    required: true
  }
});

const robotColors = [
  'bg-red-500',
  'bg-blue-500',
  'bg-green-500',
  'bg-yellow-500',
  'bg-purple-500',
  'bg-pink-500',
  'bg-indigo-500',
  'bg-cyan-500'
];
</script> 