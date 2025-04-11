<template>
  <div class="bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-6 shadow-lg border border-gray-200/80 dark:border-white/5 mb-8">
    <div class="flex flex-col md:flex-row justify-between items-start md:items-center mb-6">
      <div class="flex items-center">
        <div :class="`h-12 w-12 rounded-xl bg-gradient-to-br ${zoneColor} flex items-center justify-center text-white font-bold shadow-lg`">
          {{ zoneId.split('-')[1] }}
        </div>
        <div class="ml-4">
          <h2 class="text-xl font-medium text-gray-800 dark:text-white">{{ zoneName }}</h2>
          <p class="text-gray-500 dark:text-gray-400 text-sm">{{ zoneDescription }}</p>
        </div>
      </div>
      
      <div class="mt-4 md:mt-0 flex items-center">
        <span :class="`inline-flex items-center px-3 py-1 rounded-full text-xs font-medium ${zoneStatus === 'Active' ? 'bg-green-100 dark:bg-green-900/40 text-green-800 dark:text-green-400' : 'bg-yellow-100 dark:bg-yellow-900/40 text-yellow-800 dark:text-yellow-400'}`">
          <span class="h-1.5 w-1.5 rounded-full mr-1.5" :class="zoneStatus === 'Active' ? 'bg-green-500' : 'bg-yellow-500'"></span>
          {{ zoneStatus }}
        </span>
        <button class="ml-4 p-2 text-gray-500 dark:text-gray-400 hover:text-gray-700 dark:hover:text-gray-200 bg-gray-100/80 dark:bg-gray-700/60 rounded-lg">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M10.325 4.317c.426-1.756 2.924-1.756 3.35 0a1.724 1.724 0 002.573 1.066c1.543-.94 3.31.826 2.37 2.37a1.724 1.724 0 001.065 2.572c1.756.426 1.756 2.924 0 3.35a1.724 1.724 0 00-1.066 2.573c.94 1.543-.826 3.31-2.37 2.37a1.724 1.724 0 00-2.572 1.065c-.426 1.756-2.924 1.756-3.35 0a1.724 1.724 0 00-2.573-1.066c-1.543.94-3.31-.826-2.37-2.37.996-.608 1.572-1.86 1.065-2.572-1.756-.426-1.756-2.924 0-3.35a1.724 1.724 0 001.066-2.573c-.94-1.543.826-3.31 2.37-2.37.608.996 1.86 1.572 2.572 1.065z" />
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M15 12a3 3 0 11-6 0 3 3 0 016 0z" />
          </svg>
        </button>
      </div>
    </div>
    
    <!-- Zone Stats -->
    <div class="grid grid-cols-2 md:grid-cols-4 gap-4">
      <div class="bg-gray-50/80 dark:bg-gray-900/40 rounded-lg p-4">
        <p class="text-xs font-medium text-gray-500 dark:text-gray-400 uppercase tracking-wide mb-1">Robots</p>
        <p class="text-xl font-semibold text-gray-800 dark:text-white">{{ robotCount }}</p>
      </div>
      
      <div class="bg-gray-50/80 dark:bg-gray-900/40 rounded-lg p-4">
        <p class="text-xs font-medium text-gray-500 dark:text-gray-400 uppercase tracking-wide mb-1">Packages</p>
        <p class="text-xl font-semibold text-gray-800 dark:text-white">{{ packageCount }}</p>
      </div>
      
      <div class="bg-gray-50/80 dark:bg-gray-900/40 rounded-lg p-4">
        <p class="text-xs font-medium text-gray-500 dark:text-gray-400 uppercase tracking-wide mb-1">Throughput</p>
        <p class="text-xl font-semibold text-gray-800 dark:text-white">{{ throughput }}<span class="text-sm font-normal">/hour</span></p>
      </div>
      
      <div class="bg-gray-50/80 dark:bg-gray-900/40 rounded-lg p-4">
        <p class="text-xs font-medium text-gray-500 dark:text-gray-400 uppercase tracking-wide mb-1">Efficiency</p>
        <p class="text-xl font-semibold text-gray-800 dark:text-white">{{ efficiency }}%</p>
      </div>
    </div>
  </div>
</template>

<script setup>
import { defineProps } from 'vue';

const props = defineProps({
  zoneId: {
    type: String,
    required: true
  },
  zoneName: {
    type: String,
    required: true
  },
  zoneDescription: {
    type: String,
    required: true
  },
  zoneStatus: {
    type: String,
    required: true
  },
  zoneColor: {
    type: String,
    required: true
  },
  robotCount: {
    type: Number,
    required: true
  },
  packageCount: {
    type: Number,
    required: true
  },
  throughput: {
    type: Number,
    required: true
  },
  efficiency: {
    type: Number,
    required: true
  }
});
</script> 