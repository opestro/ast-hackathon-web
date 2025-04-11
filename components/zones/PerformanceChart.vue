<template>
  <div class="bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5">
    <h2 class="text-base font-medium mb-5 text-gray-800 dark:text-white flex items-center">
      <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-indigo-500 dark:text-indigo-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
        <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 19v-6a2 2 0 00-2-2H5a2 2 0 00-2 2v6a2 2 0 002 2h2a2 2 0 002-2zm0 0V9a2 2 0 012-2h2a2 2 0 012 2v10m-6 0a2 2 0 002 2h2a2 2 0 002-2m0 0V5a2 2 0 012-2h2a2 2 0 012 2v14a2 2 0 01-2 2h-2a2 2 0 01-2-2z" />
      </svg>
      Performance Metrics
    </h2>
    
    <!-- Chart Tabs -->
    <div class="flex border-b border-gray-200 dark:border-gray-700 mb-4">
      <button 
        v-for="(tab, index) in tabs" 
        :key="index" 
        @click="activeTab = tab.id"
        :class="`px-4 py-2 text-sm font-medium ${activeTab === tab.id ? 'text-blue-500 dark:text-blue-400 border-b-2 border-blue-500 dark:border-blue-400' : 'text-gray-500 dark:text-gray-400 hover:text-gray-700 dark:hover:text-gray-300'}`"
      >
        {{ tab.name }}
      </button>
    </div>
    
    <!-- Chart Area -->
    <div class="h-64 w-full relative">
      <!-- Mock chart - This would be replaced with a real chart library implementation -->
      <div class="absolute inset-0 flex items-end">
        <!-- Simulated line chart -->
        <div v-for="(value, index) in chartData" :key="index" class="w-full h-full flex items-end justify-center">
          <div 
            :style="`height: ${value}%;`" 
            :class="`w-4 rounded-t-md transition-all duration-500 ${activeTab === 'throughput' ? 'bg-blue-500/70' : activeTab === 'efficiency' ? 'bg-green-500/70' : 'bg-purple-500/70'}`">
          </div>
        </div>
      </div>
      
      <!-- Chart labels -->
      <div class="absolute bottom-0 left-0 right-0 flex justify-between px-4 border-t border-gray-200 dark:border-gray-700 pt-2 text-xs text-gray-500 dark:text-gray-400">
        <span>Mon</span>
        <span>Tue</span>
        <span>Wed</span>
        <span>Thu</span>
        <span>Fri</span>
        <span>Sat</span>
        <span>Sun</span>
      </div>
      
      <!-- Y-axis labels -->
      <div class="absolute top-0 left-0 bottom-6 flex flex-col justify-between items-start text-xs text-gray-500 dark:text-gray-400">
        <span>100%</span>
        <span>75%</span>
        <span>50%</span>
        <span>25%</span>
        <span>0%</span>
      </div>
    </div>
    
    <!-- Key metrics summary -->
    <div class="mt-6 grid grid-cols-3 gap-3">
      <div class="bg-gray-50/80 dark:bg-gray-900/40 rounded-lg p-3 text-center">
        <p class="text-xs text-gray-500 dark:text-gray-400">Avg {{ activeTabName }}</p>
        <p class="text-lg font-medium text-gray-800 dark:text-white">{{ average }}{{ activeTab === 'efficiency' ? '%' : '' }}</p>
      </div>
      <div class="bg-gray-50/80 dark:bg-gray-900/40 rounded-lg p-3 text-center">
        <p class="text-xs text-gray-500 dark:text-gray-400">Peak</p>
        <p class="text-lg font-medium text-gray-800 dark:text-white">{{ peak }}{{ activeTab === 'efficiency' ? '%' : '' }}</p>
      </div>
      <div :class="`bg-gray-50/80 dark:bg-gray-900/40 rounded-lg p-3 text-center ${trend > 0 ? 'text-green-500' : trend < 0 ? 'text-red-500' : 'text-gray-500'}`">
        <p class="text-xs">Trend</p>
        <p class="text-lg font-medium flex items-center justify-center">
          <svg v-if="trend > 0" xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-1" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M5 15l7-7 7 7" />
          </svg>
          <svg v-else-if="trend < 0" xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-1" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M19 9l-7 7-7-7" />
          </svg>
          {{ trend > 0 ? '+' : '' }}{{ trend }}%
        </p>
      </div>
    </div>
  </div>
</template>

<script setup>
import { ref, computed } from 'vue';

const props = defineProps({
  throughputData: {
    type: Array,
    default: () => [65, 59, 80, 81, 56, 55, 70]
  },
  efficiencyData: {
    type: Array,
    default: () => [92, 88, 90, 91, 84, 86, 95]
  },
  robotUtilizationData: {
    type: Array,
    default: () => [78, 82, 75, 77, 80, 72, 85]
  }
});

const tabs = [
  { id: 'throughput', name: 'Throughput' },
  { id: 'efficiency', name: 'Efficiency' },
  { id: 'robotUtilization', name: 'Robot Utilization' }
];

const activeTab = ref('throughput');

const chartData = computed(() => {
  switch (activeTab.value) {
    case 'throughput':
      return props.throughputData;
    case 'efficiency':
      return props.efficiencyData;
    case 'robotUtilization':
      return props.robotUtilizationData;
    default:
      return props.throughputData;
  }
});

const activeTabName = computed(() => {
  return tabs.find(tab => tab.id === activeTab.value)?.name || '';
});

const average = computed(() => {
  const sum = chartData.value.reduce((acc, val) => acc + val, 0);
  return Math.round(sum / chartData.value.length);
});

const peak = computed(() => {
  return Math.max(...chartData.value);
});

const trend = computed(() => {
  const lastDay = chartData.value[chartData.value.length - 1];
  const prevDay = chartData.value[chartData.value.length - 2];
  return Math.round(((lastDay - prevDay) / prevDay) * 100);
});
</script> 