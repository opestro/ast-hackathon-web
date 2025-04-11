<template>
  <div class="lg:col-span-2 bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5">
    <h2 class="text-lg font-medium mb-4 text-gray-800 dark:text-white">Active Zone: {{ zoneName }}</h2>
    
    <!-- Robot List -->
    <div class="space-y-3 mt-4">
      <div v-for="robot in robots" :key="robot.id" 
        @click="selectRobot(robot)"
        class="bg-gray-100/80 dark:bg-gray-900/60 rounded-xl p-4 cursor-pointer hover:bg-gray-200/80 dark:hover:bg-gray-800/60 transition-all border border-gray-200/60 dark:border-white/5 relative overflow-hidden"
        :class="{'border-green-400/50 dark:border-green-400/30 ring-2 ring-green-400/20': selectedRobotId === robot.id}">
        <div class="flex justify-between items-start">
          <div>
            <div class="flex items-center">
              <div class="h-2.5 w-2.5 rounded-full bg-green-400 mr-2 animate-pulse"></div>
              <h3 class="font-medium text-gray-800 dark:text-white">{{ robot.id }}</h3>
            </div>
            <p class="text-sm text-gray-500 dark:text-gray-400 mt-1">{{ robot.model }}</p>
          </div>
          <div class="bg-gray-200/60 dark:bg-gray-800/60 text-xs text-gray-600 dark:text-gray-300 rounded-lg px-2 py-1">
            {{ robot.status }}
          </div>
        </div>
        <div class="flex mt-3 space-x-2">
          <div class="bg-gray-200/60 dark:bg-gray-800/60 rounded-full px-2 py-1 text-xs text-gray-600 dark:text-gray-300">
            Position: {{ robot.position.x.toFixed(1) }}, {{ robot.position.y.toFixed(1) }}
          </div>
        </div>
        <!-- View Details Call to Action -->
        <div class="absolute bottom-4 right-4 text-xs text-green-600 dark:text-green-400 flex items-center">
          View Details
          <svg xmlns="http://www.w3.org/2000/svg" class="h-3 w-3 ml-1" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 5l7 7-7 7" />
          </svg>
        </div>
      </div>
    </div>
  </div>
</template>

<script setup>
import { defineProps, defineEmits } from 'vue';

const props = defineProps({
  robots: {
    type: Array,
    required: true
  },
  zoneName: {
    type: String,
    required: true
  },
  selectedRobotId: {
    type: String,
    default: null
  }
});

const emit = defineEmits(['select-robot']);

const selectRobot = (robot) => {
  emit('select-robot', robot);
};
</script> 