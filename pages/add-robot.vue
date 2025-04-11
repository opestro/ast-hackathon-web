<template>
  <div class="p-6 md:p-8">
    <!-- Header -->
    <div class="mb-8">
      <h1 class="text-2xl md:text-3xl font-light tracking-tight text-gray-900 dark:text-white">Add <span class="font-bold">Robot</span></h1>
      <p class="text-gray-500 dark:text-gray-400 mt-1 tracking-wide text-sm">Configure and deploy a new robot to your warehouse</p>
    </div>
    
    <!-- Form Container -->
    <div class="bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-6 shadow-lg border border-gray-200/80 dark:border-white/5">
      <form @submit.prevent="submitForm">
        <!-- Basic Information -->
        <div class="mb-8">
          <h2 class="text-base font-medium mb-4 text-gray-800 dark:text-white flex items-center">
            <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-blue-500 dark:text-blue-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
              <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M5 12h14M5 12a2 2 0 01-2-2V6a2 2 0 012-2h14a2 2 0 012 2v4a2 2 0 01-2 2M5 12a2 2 0 00-2 2v4a2 2 0 002 2h14a2 2 0 002-2v-4a2 2 0 00-2-2m-2-4h.01M17 16h.01" />
            </svg>
            Basic Information
          </h2>
          
          <div class="grid grid-cols-1 md:grid-cols-2 gap-6">
            <div>
              <label class="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">Robot ID</label>
              <input 
                type="text"
                v-model="robotData.id"
                placeholder="RB-006"
                class="w-full px-4 py-2.5 bg-gray-50/80 dark:bg-gray-900/50 border border-gray-200 dark:border-gray-700 rounded-lg focus:ring-2 focus:ring-blue-500/30 dark:focus:ring-blue-500/40 focus:border-blue-500 dark:focus:border-blue-500/40 outline-none transition-all text-gray-700 dark:text-gray-200"
              />
            </div>
            
            <div>
              <label class="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">Model Name</label>
              <input 
                type="text"
                v-model="robotData.model"
                placeholder="LineFollower Pro"
                class="w-full px-4 py-2.5 bg-gray-50/80 dark:bg-gray-900/50 border border-gray-200 dark:border-gray-700 rounded-lg focus:ring-2 focus:ring-blue-500/30 dark:focus:ring-blue-500/40 focus:border-blue-500 dark:focus:border-blue-500/40 outline-none transition-all text-gray-700 dark:text-gray-200"
              />
            </div>
            
            <div>
              <label class="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">Type</label>
              <select
                v-model="robotData.type"
                class="w-full px-4 py-2.5 bg-gray-50/80 dark:bg-gray-900/50 border border-gray-200 dark:border-gray-700 rounded-lg focus:ring-2 focus:ring-blue-500/30 dark:focus:ring-blue-500/40 focus:border-blue-500 dark:focus:border-blue-500/40 outline-none transition-all text-gray-700 dark:text-gray-200"
              >
                <option value="transport">Transport</option>
                <option value="scanner">Scanner</option>
                <option value="picker">Picker</option>
                <option value="sorter">Sorter</option>
              </select>
            </div>
            
            <div>
              <label class="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">Firmware Version</label>
              <input
                type="text"
                v-model="robotData.firmware"
                placeholder="v2.1.4"
                class="w-full px-4 py-2.5 bg-gray-50/80 dark:bg-gray-900/50 border border-gray-200 dark:border-gray-700 rounded-lg focus:ring-2 focus:ring-blue-500/30 dark:focus:ring-blue-500/40 focus:border-blue-500 dark:focus:border-blue-500/40 outline-none transition-all text-gray-700 dark:text-gray-200"
              />
            </div>
          </div>
        </div>
        
        <!-- Capabilities -->
        <div class="mb-8">
          <h2 class="text-base font-medium mb-4 text-gray-800 dark:text-white flex items-center">
            <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-green-500 dark:text-green-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
              <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 12l2 2 4-4m5.618-4.016A11.955 11.955 0 0112 2.944a11.955 11.955 0 01-8.618 3.04A12.02 12.02 0 003 9c0 5.591 3.824 10.29 9 11.622 5.176-1.332 9-6.03 9-11.622 0-1.042-.133-2.052-.382-3.016z" />
            </svg>
            Capabilities
          </h2>
          
          <div class="space-y-4">
            <div class="flex items-center p-3 bg-gray-50/80 dark:bg-gray-900/50 rounded-lg">
              <input
                type="checkbox"
                id="cap-color"
                v-model="robotData.capabilities.colorDetection"
                class="w-4 h-4 text-blue-600 bg-gray-100 border-gray-300 rounded focus:ring-blue-500 dark:focus:ring-blue-600 dark:ring-offset-gray-800 dark:bg-gray-700 dark:border-gray-600"
              />
              <label for="cap-color" class="ml-2 text-sm font-medium text-gray-700 dark:text-gray-300">Color Detection</label>
            </div>
            
            <div class="flex items-center p-3 bg-gray-50/80 dark:bg-gray-900/50 rounded-lg">
              <input
                type="checkbox"
                id="cap-auto"
                v-model="robotData.capabilities.autonomousNavigation"
                class="w-4 h-4 text-blue-600 bg-gray-100 border-gray-300 rounded focus:ring-blue-500 dark:focus:ring-blue-600 dark:ring-offset-gray-800 dark:bg-gray-700 dark:border-gray-600"
              />
              <label for="cap-auto" class="ml-2 text-sm font-medium text-gray-700 dark:text-gray-300">Autonomous Navigation</label>
            </div>
            
            <div class="flex items-center p-3 bg-gray-50/80 dark:bg-gray-900/50 rounded-lg">
              <input
                type="checkbox"
                id="cap-obs"
                v-model="robotData.capabilities.obstacleAvoidance"
                class="w-4 h-4 text-blue-600 bg-gray-100 border-gray-300 rounded focus:ring-blue-500 dark:focus:ring-blue-600 dark:ring-offset-gray-800 dark:bg-gray-700 dark:border-gray-600"
              />
              <label for="cap-obs" class="ml-2 text-sm font-medium text-gray-700 dark:text-gray-300">Obstacle Avoidance</label>
            </div>
            
            <div class="flex items-center p-3 bg-gray-50/80 dark:bg-gray-900/50 rounded-lg">
              <input
                type="checkbox"
                id="cap-load"
                v-model="robotData.capabilities.loadSensing"
                class="w-4 h-4 text-blue-600 bg-gray-100 border-gray-300 rounded focus:ring-blue-500 dark:focus:ring-blue-600 dark:ring-offset-gray-800 dark:bg-gray-700 dark:border-gray-600"
              />
              <label for="cap-load" class="ml-2 text-sm font-medium text-gray-700 dark:text-gray-300">Load Sensing</label>
            </div>
          </div>
        </div>
        
        <!-- Operating Parameters -->
        <div class="mb-8">
          <h2 class="text-base font-medium mb-4 text-gray-800 dark:text-white flex items-center">
            <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-purple-500 dark:text-purple-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
              <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M10.325 4.317c.426-1.756 2.924-1.756 3.35 0a1.724 1.724 0 002.573 1.066c1.543-.94 3.31.826 2.37 2.37a1.724 1.724 0 001.065 2.572c1.756.426 1.756 2.924 0 3.35a1.724 1.724 0 00-1.066 2.573c.94 1.543-.826 3.31-2.37 2.37a1.724 1.724 0 00-2.572 1.065c-.426 1.756-2.924 1.756-3.35 0a1.724 1.724 0 00-2.573-1.066c-1.543.94-3.31-.826-2.37-2.37a1.724 1.724 0 00-1.065-2.572c-1.756-.426-1.756-2.924 0-3.35a1.724 1.724 0 001.066-2.573c-.94-1.543.826-3.31 2.37-2.37.996.608 2.296.07 2.572-1.065z" />
              <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M15 12a3 3 0 11-6 0 3 3 0 016 0z" />
            </svg>
            Operating Parameters
          </h2>
          
          <div class="grid grid-cols-1 md:grid-cols-2 gap-6">
            <div>
              <label class="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">Max Speed (m/s)</label>
              <input
                type="number"
                v-model="robotData.parameters.maxSpeed"
                step="0.1"
                min="0"
                max="5"
                class="w-full px-4 py-2.5 bg-gray-50/80 dark:bg-gray-900/50 border border-gray-200 dark:border-gray-700 rounded-lg focus:ring-2 focus:ring-blue-500/30 dark:focus:ring-blue-500/40 focus:border-blue-500 dark:focus:border-blue-500/40 outline-none transition-all text-gray-700 dark:text-gray-200"
              />
            </div>
            
            <div>
              <label class="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">Max Load (kg)</label>
              <input
                type="number"
                v-model="robotData.parameters.maxLoad"
                step="1"
                min="0"
                max="200"
                class="w-full px-4 py-2.5 bg-gray-50/80 dark:bg-gray-900/50 border border-gray-200 dark:border-gray-700 rounded-lg focus:ring-2 focus:ring-blue-500/30 dark:focus:ring-blue-500/40 focus:border-blue-500 dark:focus:border-blue-500/40 outline-none transition-all text-gray-700 dark:text-gray-200"
              />
            </div>
            
            <div>
              <label class="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">Battery Life (hours)</label>
              <input
                type="number"
                v-model="robotData.parameters.batteryLife"
                step="0.5"
                min="1"
                max="24"
                class="w-full px-4 py-2.5 bg-gray-50/80 dark:bg-gray-900/50 border border-gray-200 dark:border-gray-700 rounded-lg focus:ring-2 focus:ring-blue-500/30 dark:focus:ring-blue-500/40 focus:border-blue-500 dark:focus:border-blue-500/40 outline-none transition-all text-gray-700 dark:text-gray-200"
              />
            </div>
            
            <div>
              <label class="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">Operating Zone</label>
              <select
                v-model="robotData.parameters.zone"
                class="w-full px-4 py-2.5 bg-gray-50/80 dark:bg-gray-900/50 border border-gray-200 dark:border-gray-700 rounded-lg focus:ring-2 focus:ring-blue-500/30 dark:focus:ring-blue-500/40 focus:border-blue-500 dark:focus:border-blue-500/40 outline-none transition-all text-gray-700 dark:text-gray-200"
              >
                <option value="zone-a">Zone A - Storage</option>
                <option value="zone-b">Zone B - Sorting</option>
                <option value="zone-c">Zone C - Packing</option>
                <option value="zone-d">Zone D - Loading</option>
                <option value="all">All Zones</option>
              </select>
            </div>
          </div>
        </div>
        
        <!-- Notes -->
        <div class="mb-8">
          <label class="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">Additional Notes</label>
          <textarea
            v-model="robotData.notes"
            rows="3"
            class="w-full px-4 py-2.5 bg-gray-50/80 dark:bg-gray-900/50 border border-gray-200 dark:border-gray-700 rounded-lg focus:ring-2 focus:ring-blue-500/30 dark:focus:ring-blue-500/40 focus:border-blue-500 dark:focus:border-blue-500/40 outline-none transition-all text-gray-700 dark:text-gray-200"
            placeholder="Any additional details about this robot..."
          ></textarea>
        </div>
        
        <!-- Submit Buttons -->
        <div class="flex justify-end space-x-4">
          <button
            type="button"
            class="px-5 py-2.5 bg-gray-100 dark:bg-gray-800 hover:bg-gray-200 dark:hover:bg-gray-700 text-gray-700 dark:text-gray-300 rounded-lg transition-colors"
          >
            Cancel
          </button>
          <button
            type="submit"
            class="px-5 py-2.5 bg-gradient-to-br from-green-500 to-green-600 hover:from-green-600 hover:to-green-700 text-white rounded-lg shadow-md shadow-green-500/20 transition-all"
          >
            Add Robot
          </button>
        </div>
      </form>
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue';

// Robot data model
const robotData = ref({
  id: '',
  model: '',
  type: 'transport',
  firmware: 'v2.1.4',
  capabilities: {
    colorDetection: true,
    autonomousNavigation: true,
    obstacleAvoidance: true,
    loadSensing: false
  },
  parameters: {
    maxSpeed: 1.5,
    maxLoad: 50,
    batteryLife: 8,
    zone: 'all'
  },
  notes: ''
});

// Form submission handler
const submitForm = () => {
  // In a real application, you would send this data to your backend
  console.log('Submitting robot data:', robotData.value);
  
  // Show success message (in a real app, you'd wait for API response)
  alert('Robot added successfully!');
  
  // Reset form (optional)
  resetForm();
};

// Reset form to default values
const resetForm = () => {
  robotData.value = {
    id: '',
    model: '',
    type: 'transport',
    firmware: 'v2.1.4',
    capabilities: {
      colorDetection: true,
      autonomousNavigation: true,
      obstacleAvoidance: true,
      loadSensing: false
    },
    parameters: {
      maxSpeed: 1.5,
      maxLoad: 50,
      batteryLife: 8,
      zone: 'all'
    },
    notes: ''
  };
};
</script> 