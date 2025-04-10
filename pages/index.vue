<template>
  <div class="p-6">
    <!-- Header -->
    <div class="flex justify-between items-center mb-6">
      <div>
        <h1 class="text-2xl font-bold">RoboStock Management System</h1>
        <p class="text-gray-400">Warehouse Automation Department</p>
      </div>
      
      <!-- Robot Status -->
      <div class="bg-gray-800 rounded-lg px-4 py-2 flex items-center">
        <span class="text-gray-400 mr-3">Robot Status:</span>
        <div class="flex items-center bg-gray-700 rounded-full px-3 py-1">
          <div class="h-2 w-2 rounded-full bg-green-500 mr-2"></div>
          <span class="text-green-400 text-sm font-medium">Active - Line Following</span>
        </div>
      </div>
    </div>
    
    <!-- Main Grid -->
    <div class="grid grid-cols-1 lg:grid-cols-3 gap-6">
      
      <!-- Left Column - Robot Controls & Stats -->
      <div class="space-y-6">
        <!-- Robot Stats -->
        <div class="bg-gray-800 rounded-lg p-4">
          <h2 class="text-lg font-medium mb-4 text-green-400">Robot Statistics</h2>
          <div class="grid grid-cols-2 gap-4">
            <div class="bg-gray-700 rounded-lg p-3">
              <p class="text-gray-400 text-sm">Battery Level</p>
              <div class="flex items-center mt-1">
                <div class="w-full bg-gray-600 rounded-full h-2.5">
                  <div class="bg-green-500 h-2.5 rounded-full" style="width: 78%"></div>
                </div>
                <span class="ml-2 text-green-400">78%</span>
              </div>
            </div>
            <div class="bg-gray-700 rounded-lg p-3">
              <p class="text-gray-400 text-sm">Signal Strength</p>
              <div class="flex items-center mt-1">
                <div class="w-full bg-gray-600 rounded-full h-2.5">
                  <div class="bg-blue-500 h-2.5 rounded-full" style="width: 92%"></div>
                </div>
                <span class="ml-2 text-blue-400">92%</span>
              </div>
            </div>
            <div class="bg-gray-700 rounded-lg p-3">
              <p class="text-gray-400 text-sm">Packages Handled</p>
              <p class="text-xl font-bold text-white">24</p>
            </div>
            <div class="bg-gray-700 rounded-lg p-3">
              <p class="text-gray-400 text-sm">Total Distance</p>
              <p class="text-xl font-bold text-white">1.2 km</p>
            </div>
          </div>
        </div>
        
        <!-- Color Detection -->
        <div class="bg-gray-800 rounded-lg p-4">
          <h2 class="text-lg font-medium mb-4 text-green-400">Color Detection</h2>
          <div class="space-y-3">
            <div class="flex items-center justify-between">
              <div class="flex items-center">
                <div class="h-4 w-4 rounded-full bg-red-500 mr-2"></div>
                <span>Red</span>
              </div>
              <span class="text-gray-400">4 packages</span>
            </div>
            <div class="flex items-center justify-between">
              <div class="flex items-center">
                <div class="h-4 w-4 rounded-full bg-blue-500 mr-2"></div>
                <span>Blue</span>
              </div>
              <span class="text-gray-400">7 packages</span>
            </div>
            <div class="flex items-center justify-between">
              <div class="flex items-center">
                <div class="h-4 w-4 rounded-full bg-yellow-500 mr-2"></div>
                <span>Yellow</span>
              </div>
              <span class="text-gray-400">5 packages</span>
            </div>
            <div class="flex items-center justify-between">
              <div class="flex items-center">
                <div class="h-4 w-4 rounded-full bg-green-500 mr-2"></div>
                <span>Green</span>
              </div>
              <span class="text-gray-400">8 packages</span>
            </div>
          </div>
        </div>
        
        <!-- Manual Controls -->
        <div class="bg-gray-800 rounded-lg p-4">
          <h2 class="text-lg font-medium mb-4 text-green-400">Manual Controls</h2>
          <div class="flex flex-col items-center">
            <button class="w-12 h-12 bg-gray-700 hover:bg-gray-600 rounded-lg flex items-center justify-center">
              <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M5 15l7-7 7 7" />
              </svg>
            </button>
            <div class="flex justify-between w-full my-2">
              <button class="w-12 h-12 bg-gray-700 hover:bg-gray-600 rounded-lg flex items-center justify-center">
                <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                  <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M10 19l-7-7m0 0l7-7m-7 7h18" />
                </svg>
              </button>
              <button class="w-12 h-12 bg-red-700 hover:bg-red-600 rounded-lg flex items-center justify-center">
                <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                  <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M6 18L18 6M6 6l12 12" />
                </svg>
              </button>
              <button class="w-12 h-12 bg-gray-700 hover:bg-gray-600 rounded-lg flex items-center justify-center">
                <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                  <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M14 5l7 7m0 0l-7 7m7-7H3" />
                </svg>
              </button>
            </div>
            <button class="w-12 h-12 bg-gray-700 hover:bg-gray-600 rounded-lg flex items-center justify-center">
              <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M19 9l-7 7-7-7" />
              </svg>
            </button>
          </div>
        </div>
      </div>
      
      <!-- Middle Column - Map & Tracking -->
      <div class="lg:col-span-2 space-y-6">
        <!-- Tracking Map -->
        <div class="bg-gray-800 rounded-lg p-4 h-[400px]">
          <div class="flex justify-between items-center mb-4">
            <h2 class="text-lg font-medium text-green-400">Warehouse Map & Tracking</h2>
            <div class="flex space-x-2">
              <button class="bg-gray-700 hover:bg-gray-600 p-2 rounded-lg">
                <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                  <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M15 12a3 3 0 11-6 0 3 3 0 016 0z" />
                  <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M2.458 12C3.732 7.943 7.523 5 12 5c4.478 0 8.268 2.943 9.542 7-1.274 4.057-5.064 7-9.542 7-4.477 0-8.268-2.943-9.542-7z" />
                </svg>
              </button>
              <button class="bg-gray-700 hover:bg-gray-600 p-2 rounded-lg">
                <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                  <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M4 4v5h.582m15.356 2A8.001 8.001 0 004.582 9m0 0H9m11 11v-5h-.581m0 0a8.003 8.003 0 01-15.357-2m15.357 2H15" />
                </svg>
              </button>
            </div>
          </div>
          
          <!-- Warehouse Grid Map (Placeholder) -->
          <div class="h-[320px] bg-gray-900 rounded-lg p-2 relative">
            <!-- Grid Lines (5x5) -->
            <div class="absolute inset-0 grid grid-cols-5 grid-rows-5">
              <template v-for="i in 25" :key="i">
                <div class="border border-gray-800"></div>
              </template>
            </div>
            
            <!-- Path Lines (Just visual placeholders) -->
            <div class="absolute h-1 w-20 bg-black transform rotate-90 left-[40px] top-[60px]"></div>
            <div class="absolute h-1 w-40 bg-black left-[40px] top-[60px]"></div>
            <div class="absolute h-1 w-20 bg-black transform rotate-90 left-[80px] top-[60px]"></div>
            <div class="absolute h-1 w-40 bg-black left-[80px] top-[80px]"></div>
            <div class="absolute h-1 w-60 bg-black transform rotate-90 left-[120px] top-[80px]"></div>
            <div class="absolute h-1 w-40 bg-black left-[120px] top-[140px]"></div>
            <div class="absolute h-1 w-40 bg-black transform rotate-90 left-[160px] top-[140px]"></div>
            <div class="absolute h-1 w-40 bg-black left-[160px] top-[180px]"></div>
            <div class="absolute h-1 w-40 bg-black transform rotate-90 left-[200px] top-[160px]"></div>
            <div class="absolute h-1 w-60 bg-black left-[200px] top-[160px]"></div>
            <div class="absolute h-1 w-40 bg-black transform rotate-90 left-[260px] top-[140px]"></div>
            
            <!-- Storage Areas -->
            <div class="absolute top-[40px] left-[40px] h-10 w-10 rounded border-2 border-red-500 flex items-center justify-center text-red-500 text-xs">R1</div>
            <div class="absolute top-[80px] left-[160px] h-10 w-10 rounded border-2 border-blue-500 flex items-center justify-center text-blue-500 text-xs">B2</div>
            <div class="absolute top-[180px] left-[220px] h-10 w-10 rounded border-2 border-yellow-500 flex items-center justify-center text-yellow-500 text-xs">Y3</div>
            <div class="absolute top-[130px] left-[260px] h-10 w-10 rounded border-2 border-green-500 flex items-center justify-center text-green-500 text-xs">G4</div>
            
            <!-- Robot Position -->
            <div class="absolute top-[160px] left-[180px] h-6 w-6 bg-green-500 rounded-full shadow-md flex items-center justify-center">
              <span class="text-xs font-bold">R</span>
            </div>
          </div>
        </div>
        
        <!-- Current Mission & Tasks -->
        <div class="grid grid-cols-1 md:grid-cols-2 gap-6">
          <!-- Current Task -->
          <div class="bg-gray-800 rounded-lg p-4">
            <h2 class="text-lg font-medium mb-4 text-green-400">Current Task</h2>
            <div class="bg-gray-700 rounded-lg p-3">
              <div class="flex justify-between items-center mb-2">
                <span class="text-white font-medium">Transport Blue Package</span>
                <span class="text-blue-400 text-sm">In Progress</span>
              </div>
              <p class="text-gray-400 text-sm mb-3">Move package from intake to blue storage area (B2)</p>
              <div class="flex space-x-2">
                <div class="bg-gray-600 rounded-full px-3 py-1 text-xs">
                  Color: Blue
                </div>
                <div class="bg-gray-600 rounded-full px-3 py-1 text-xs">
                  Weight: 0.5kg
                </div>
              </div>
            </div>
          </div>
          
          <!-- Landmark Detection -->
          <div class="bg-gray-800 rounded-lg p-4">
            <h2 class="text-lg font-medium mb-4 text-green-400">Landmark Detection</h2>
            <div class="space-y-3">
              <div class="flex items-center justify-between bg-gray-700 p-2 rounded-lg">
                <div class="flex items-center">
                  <div class="w-3 h-3 rounded-full bg-gray-500 mr-2"></div>
                  <span>Start Position</span>
                </div>
                <span class="text-gray-400 text-sm">Passed</span>
              </div>
              <div class="flex items-center justify-between bg-gray-700 p-2 rounded-lg">
                <div class="flex items-center">
                  <div class="w-3 h-3 rounded-full bg-yellow-500 mr-2"></div>
                  <span>Junction 1</span>
                </div>
                <span class="text-gray-400 text-sm">Passed</span>
              </div>
              <div class="flex items-center justify-between bg-blue-700 p-2 rounded-lg">
                <div class="flex items-center">
                  <div class="w-3 h-3 rounded-full bg-blue-500 mr-2"></div>
                  <span>Blue Storage</span>
                </div>
                <span class="text-white text-sm font-medium">Current</span>
              </div>
              <div class="flex items-center justify-between bg-gray-700 p-2 rounded-lg">
                <div class="flex items-center">
                  <div class="w-3 h-3 rounded-full bg-gray-500 mr-2"></div>
                  <span>Return Path</span>
                </div>
                <span class="text-gray-400 text-sm">Next</span>
              </div>
            </div>
          </div>
        </div>
        
        <!-- Package Queue & Destination Settings -->
        <div class="grid grid-cols-1 md:grid-cols-2 gap-6">
          <!-- Package Queue -->
          <div class="bg-gray-800 rounded-lg p-4">
            <h2 class="text-lg font-medium mb-4 text-green-400">Package Queue</h2>
            <div class="space-y-2">
              <div class="bg-gray-700 p-2 rounded-lg flex justify-between items-center">
                <div class="flex items-center">
                  <div class="w-4 h-4 rounded-full bg-yellow-500 mr-2"></div>
                  <span class="text-sm">Yellow Package</span>
                </div>
                <div class="text-gray-400 text-xs">Next in queue</div>
              </div>
              <div class="bg-gray-700 p-2 rounded-lg flex justify-between items-center">
                <div class="flex items-center">
                  <div class="w-4 h-4 rounded-full bg-red-500 mr-2"></div>
                  <span class="text-sm">Red Package</span>
                </div>
                <div class="text-gray-400 text-xs">Position 2</div>
              </div>
              <div class="bg-gray-700 p-2 rounded-lg flex justify-between items-center">
                <div class="flex items-center">
                  <div class="w-4 h-4 rounded-full bg-green-500 mr-2"></div>
                  <span class="text-sm">Green Package</span>
                </div>
                <div class="text-gray-400 text-xs">Position 3</div>
              </div>
            </div>
            <div class="mt-4">
              <button class="bg-gray-700 hover:bg-gray-600 text-white px-4 py-2 rounded-lg text-sm w-full">
                Add New Package
              </button>
            </div>
          </div>
          
          <!-- Destination Settings -->
          <div class="bg-gray-800 rounded-lg p-4">
            <h2 class="text-lg font-medium mb-4 text-green-400">Destination Settings</h2>
            <div class="space-y-3">
              <div>
                <label class="block text-sm text-gray-400 mb-1">Package Color</label>
                <select class="w-full bg-gray-700 border border-gray-600 rounded-lg px-3 py-2 text-white">
                  <option>Automatic Detection</option>
                  <option>Red</option>
                  <option>Blue</option>
                  <option>Yellow</option>
                  <option>Green</option>
                </select>
              </div>
              <div>
                <label class="block text-sm text-gray-400 mb-1">Storage Location</label>
                <div class="grid grid-cols-2 gap-2">
                  <button class="bg-gray-700 hover:bg-red-900 text-white p-2 rounded-lg text-sm flex items-center justify-center">
                    <div class="w-3 h-3 rounded-full bg-red-500 mr-2"></div>
                    Red Area
                  </button>
                  <button class="bg-gray-700 hover:bg-blue-900 text-white p-2 rounded-lg text-sm flex items-center justify-center">
                    <div class="w-3 h-3 rounded-full bg-blue-500 mr-2"></div>
                    Blue Area
                  </button>
                  <button class="bg-gray-700 hover:bg-yellow-900 text-white p-2 rounded-lg text-sm flex items-center justify-center">
                    <div class="w-3 h-3 rounded-full bg-yellow-500 mr-2"></div>
                    Yellow Area
                  </button>
                  <button class="bg-gray-700 hover:bg-green-900 text-white p-2 rounded-lg text-sm flex items-center justify-center">
                    <div class="w-3 h-3 rounded-full bg-green-500 mr-2"></div>
                    Green Area
                  </button>
                </div>
              </div>
              <div>
                <button class="bg-green-600 hover:bg-green-700 text-white px-4 py-2 rounded-lg text-sm w-full font-medium">
                  Apply Settings
                </button>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script setup>
// You can add component logic here
</script>

