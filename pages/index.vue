<template>
  <div class="p-6 md:p-8">
    <!-- Header -->
    <div class="flex flex-col md:flex-row justify-between items-start md:items-center mb-8 gap-4">
      <div>
        <h1 class="text-2xl md:text-3xl font-light tracking-tight text-gray-900 dark:text-white">RoboStock <span class="font-bold">Control Center</span></h1>
        <p class="text-gray-500 dark:text-gray-400 mt-1 tracking-wide text-sm">Autonomous Warehouse Management</p>
      </div>
      
      <!-- Robot Status -->
      <div class="bg-white/80 dark:bg-gray-800/60 backdrop-blur-md rounded-xl px-5 py-3 flex items-center shadow-lg border border-gray-200/80 dark:border-white/5">
        <span class="text-gray-500 dark:text-gray-400 mr-3 text-sm">Status</span>
        <div class="flex items-center bg-gray-100/80 dark:bg-gray-900/60 rounded-full px-4 py-1.5">
          <div class="h-2 w-2 rounded-full bg-green-400 mr-2 animate-pulse"></div>
          <span class="text-gray-800 dark:text-white text-sm font-medium">Active • Line Following</span>
        </div>
      </div>
    </div>
    
    <!-- Main Grid -->
    <div class="grid grid-cols-1 lg:grid-cols-3 gap-6 md:gap-8">
      
      <!-- Left Column - Robot Controls & Stats -->
      <div class="space-y-6 md:space-y-8">
        <!-- Robot Stats -->
        <div class="bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5">
          <h2 class="text-base font-medium mb-5 text-gray-800 dark:text-white flex items-center">
            <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-green-500 dark:text-green-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
              <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M13 10V3L4 14h7v7l9-11h-7z" />
            </svg>
            System Status
          </h2>
          <div class="grid grid-cols-2 gap-4">
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
              <p class="text-xl font-medium text-gray-800 dark:text-white">24</p>
            </div>
            <div class="bg-gray-100/80 dark:bg-gray-900/60 rounded-xl p-4">
              <p class="text-gray-500 dark:text-gray-400 text-xs uppercase tracking-wider mb-2">Distance</p>
              <p class="text-xl font-medium text-gray-800 dark:text-white">1.2<span class="text-sm font-normal"> km</span></p>
            </div>
          </div>
        </div>
        
        <!-- Color Detection -->
        <div class="bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5">
          <h2 class="text-base font-medium mb-5 text-gray-800 dark:text-white flex items-center">
            <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-blue-500 dark:text-blue-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
              <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M7 21a4 4 0 01-4-4V5a2 2 0 012-2h4a2 2 0 012 2v12a4 4 0 01-4 4zm0 0h12a2 2 0 002-2v-4a2 2 0 00-2-2h-2.343M11 7.343l1.657-1.657a2 2 0 012.828 0l2.829 2.829a2 2 0 010 2.828l-8.486 8.485M7 17h.01" />
            </svg>
            Color Detection
          </h2>
          <div class="space-y-3">
            <div class="flex items-center justify-between bg-gray-100/80 dark:bg-gray-900/60 rounded-lg p-3">
              <div class="flex items-center">
                <div class="h-4 w-4 rounded-full bg-gradient-to-br from-red-400 to-red-600 mr-2 shadow-md shadow-red-500/20"></div>
                <span class="text-sm text-gray-800 dark:text-white">Red</span>
              </div>
              <span class="text-gray-500 dark:text-gray-400 text-xs px-2 py-1 rounded-full bg-gray-200/60 dark:bg-gray-800/60">4 packages</span>
            </div>
            <div class="flex items-center justify-between bg-gray-100/80 dark:bg-gray-900/60 rounded-lg p-3">
              <div class="flex items-center">
                <div class="h-4 w-4 rounded-full bg-gradient-to-br from-blue-400 to-blue-600 mr-2 shadow-md shadow-blue-500/20"></div>
                <span class="text-sm text-gray-800 dark:text-white">Blue</span>
              </div>
              <span class="text-gray-500 dark:text-gray-400 text-xs px-2 py-1 rounded-full bg-gray-200/60 dark:bg-gray-800/60">7 packages</span>
            </div>
            <div class="flex items-center justify-between bg-gray-100/80 dark:bg-gray-900/60 rounded-lg p-3">
              <div class="flex items-center">
                <div class="h-4 w-4 rounded-full bg-gradient-to-br from-yellow-400 to-yellow-600 mr-2 shadow-md shadow-yellow-500/20"></div>
                <span class="text-sm text-gray-800 dark:text-white">Yellow</span>
              </div>
              <span class="text-gray-500 dark:text-gray-400 text-xs px-2 py-1 rounded-full bg-gray-200/60 dark:bg-gray-800/60">5 packages</span>
            </div>
            <div class="flex items-center justify-between bg-gray-100/80 dark:bg-gray-900/60 rounded-lg p-3">
              <div class="flex items-center">
                <div class="h-4 w-4 rounded-full bg-gradient-to-br from-green-400 to-green-600 mr-2 shadow-md shadow-green-500/20"></div>
                <span class="text-sm text-gray-800 dark:text-white">Green</span>
              </div>
              <span class="text-gray-500 dark:text-gray-400 text-xs px-2 py-1 rounded-full bg-gray-200/60 dark:bg-gray-800/60">8 packages</span>
            </div>
          </div>
        </div>
        
        <!-- Manual Controls -->
        <div class="bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5">
          <h2 class="text-base font-medium mb-5 text-gray-800 dark:text-white flex items-center">
            <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-purple-500 dark:text-purple-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
              <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 19l9 2-9-18-9 18 9-2zm0 0v-8" />
            </svg>
            Manual Control
          </h2>
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
      </div>
      
      <!-- Middle Column - Map & Tracking -->
      <div class="lg:col-span-2 space-y-6 md:space-y-8">
        <!-- Tracking Map -->
        <div class="bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5 h-[400px]">
          <div class="flex justify-between items-center mb-5">
            <h2 class="text-base font-medium text-gray-800 dark:text-white flex items-center">
              <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-green-500 dark:text-green-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 20l-5.447-2.724A1 1 0 013 16.382V5.618a1 1 0 011.447-.894L9 7m0 13l6-3m-6 3V7m6 10l4.553 2.276A1 1 0 0021 18.382V7.618a1 1 0 00-.553-.894L15 4m0 13V4m0 0L9 7" />
              </svg>
              Warehouse Mapping
            </h2>
            <div class="flex space-x-2">
              <button class="bg-gray-100/80 dark:bg-gray-900/60 hover:bg-gray-200 dark:hover:bg-gray-900 p-2 rounded-lg transform hover:scale-105 transition-all shadow-md">
                <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 text-gray-600 dark:text-gray-300" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                  <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M15 12a3 3 0 11-6 0 3 3 0 016 0z" />
                  <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M2.458 12C3.732 7.943 7.523 5 12 5c4.478 0 8.268 2.943 9.542 7-1.274 4.057-5.064 7-9.542 7-4.477 0-8.268-2.943-9.542-7z" />
                </svg>
              </button>
              <button class="bg-gray-100/80 dark:bg-gray-900/60 hover:bg-gray-200 dark:hover:bg-gray-900 p-2 rounded-lg transform hover:scale-105 transition-all shadow-md">
                <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 text-gray-600 dark:text-gray-300" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                  <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M4 4v5h.582m15.356 2A8.001 8.001 0 004.582 9m0 0H9m11 11v-5h-.581m0 0a8.003 8.003 0 01-15.357-2m15.357 2H15" />
                </svg>
              </button>
            </div>
          </div>
          
          <!-- Warehouse Grid Map (Placeholder) -->
          <div class="h-[320px] bg-gray-100/60 dark:bg-gray-900/60 rounded-xl p-3 relative shadow-inner border border-gray-200/60 dark:border-white/5">
            <!-- Grid Lines (5x5) -->
            <div class="absolute inset-0 grid grid-cols-5 grid-rows-5">
              <template v-for="i in 25" :key="i">
                <div class="border border-gray-300/50 dark:border-gray-800/50"></div>
              </template>
            </div>
            
            <!-- Path Lines (Just visual placeholders) -->
            <div class="absolute h-0.5 w-20 bg-gray-400/80 dark:bg-black/80 transform rotate-90 left-[40px] top-[60px]"></div>
            <div class="absolute h-0.5 w-40 bg-gray-400/80 dark:bg-black/80 left-[40px] top-[60px]"></div>
            <div class="absolute h-0.5 w-20 bg-gray-400/80 dark:bg-black/80 transform rotate-90 left-[80px] top-[60px]"></div>
            <div class="absolute h-0.5 w-40 bg-gray-400/80 dark:bg-black/80 left-[80px] top-[80px]"></div>
            <div class="absolute h-0.5 w-60 bg-gray-400/80 dark:bg-black/80 transform rotate-90 left-[120px] top-[80px]"></div>
            <div class="absolute h-0.5 w-40 bg-gray-400/80 dark:bg-black/80 left-[120px] top-[140px]"></div>
            <div class="absolute h-0.5 w-40 bg-gray-400/80 dark:bg-black/80 transform rotate-90 left-[160px] top-[140px]"></div>
            <div class="absolute h-0.5 w-40 bg-gray-400/80 dark:bg-black/80 left-[160px] top-[180px]"></div>
            <div class="absolute h-0.5 w-40 bg-gray-400/80 dark:bg-black/80 transform rotate-90 left-[200px] top-[160px]"></div>
            <div class="absolute h-0.5 w-60 bg-gray-400/80 dark:bg-black/80 left-[200px] top-[160px]"></div>
            <div class="absolute h-0.5 w-40 bg-gray-400/80 dark:bg-black/80 transform rotate-90 left-[260px] top-[140px]"></div>
            
            <!-- Current robot's path -->
            <div class="absolute h-0.5 w-80 bg-green-400/50 left-[80px] top-[160px] shadow-sm shadow-green-400/20"></div>
            
            <!-- Storage Areas -->
            <div class="absolute top-[40px] left-[40px] h-10 w-10 rounded-lg border-2 border-red-500/70 flex items-center justify-center text-red-500 dark:text-red-400 text-xs backdrop-blur-sm bg-red-500/10 shadow-md shadow-red-500/10">R1</div>
            <div class="absolute top-[80px] left-[160px] h-10 w-10 rounded-lg border-2 border-blue-500/70 flex items-center justify-center text-blue-500 dark:text-blue-400 text-xs backdrop-blur-sm bg-blue-500/10 shadow-md shadow-blue-500/10">B2</div>
            <div class="absolute top-[180px] left-[220px] h-10 w-10 rounded-lg border-2 border-yellow-500/70 flex items-center justify-center text-yellow-500 dark:text-yellow-400 text-xs backdrop-blur-sm bg-yellow-500/10 shadow-md shadow-yellow-500/10">Y3</div>
            <div class="absolute top-[130px] left-[260px] h-10 w-10 rounded-lg border-2 border-green-500/70 flex items-center justify-center text-green-500 dark:text-green-400 text-xs backdrop-blur-sm bg-green-500/10 shadow-md shadow-green-500/10">G4</div>
            
            <!-- Robot Position -->
            <div class="absolute top-[160px] left-[170px] h-7 w-7 bg-gradient-to-br from-green-400 to-green-600 rounded-full shadow-lg shadow-green-500/30 flex items-center justify-center animate-pulse-slow">
              <span class="text-xs font-medium">R</span>
            </div>
            
            <!-- Position Pulse Animation -->
            <div class="absolute top-[160px] left-[170px] h-7 w-7 bg-green-500/20 rounded-full animate-ping-slow"></div>
          </div>
        </div>
        
        <!-- Current Mission & Tasks -->
        <div class="grid grid-cols-1 md:grid-cols-2 gap-6 md:gap-8">
          <!-- Current Task -->
          <div class="bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5">
            <h2 class="text-base font-medium mb-5 text-gray-800 dark:text-white flex items-center">
              <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-blue-500 dark:text-blue-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 5H7a2 2 0 00-2 2v12a2 2 0 002 2h10a2 2 0 002-2V7a2 2 0 00-2-2h-2M9 5a2 2 0 002 2h2a2 2 0 002-2M9 5a2 2 0 012-2h2a2 2 0 012 2" />
              </svg>
              Current Task
            </h2>
            <div class="bg-gray-100/80 dark:bg-gray-900/60 rounded-xl p-4 shadow-inner border border-gray-200/60 dark:border-white/5">
              <div class="flex justify-between items-center mb-3">
                <span class="text-gray-800 dark:text-white font-medium text-sm">Transport Blue Package</span>
                <span class="text-blue-500 dark:text-blue-400 text-xs bg-blue-100/50 dark:bg-blue-500/10 px-2 py-1 rounded-full">In Progress</span>
              </div>
              <p class="text-gray-500 dark:text-gray-400 text-sm mb-4">Move package from intake to blue storage area (B2)</p>
              <div class="flex space-x-2">
                <div class="bg-gray-200/80 dark:bg-gray-800/80 rounded-full px-3 py-1 text-xs text-gray-600 dark:text-gray-300 backdrop-blur-sm">
                  Color: Blue
                </div>
                <div class="bg-gray-200/80 dark:bg-gray-800/80 rounded-full px-3 py-1 text-xs text-gray-600 dark:text-gray-300 backdrop-blur-sm">
                  Weight: 0.5kg
                </div>
              </div>
            </div>
          </div>
          
          <!-- Landmark Detection -->
          <div class="bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5">
            <h2 class="text-base font-medium mb-5 text-gray-800 dark:text-white flex items-center">
              <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-yellow-500 dark:text-yellow-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M17.657 16.657L13.414 20.9a1.998 1.998 0 01-2.827 0l-4.244-4.243a8 8 0 1111.314 0z" />
                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M15 11a3 3 0 11-6 0 3 3 0 016 0z" />
              </svg>
              Landmark Detection
            </h2>
            <div class="space-y-2.5">
              <div class="flex items-center justify-between bg-gray-100/80 dark:bg-gray-900/60 p-3 rounded-xl shadow-inner border border-gray-200/60 dark:border-white/5">
                <div class="flex items-center">
                  <div class="w-2 h-2 rounded-full bg-gray-400 dark:bg-gray-500 mr-2"></div>
                  <span class="text-sm text-gray-700 dark:text-gray-300">Start Position</span>
                </div>
                <span class="text-gray-500 dark:text-gray-400 text-xs">Passed</span>
              </div>
              <div class="flex items-center justify-between bg-gray-100/80 dark:bg-gray-900/60 p-3 rounded-xl shadow-inner border border-gray-200/60 dark:border-white/5">
                <div class="flex items-center">
                  <div class="w-2 h-2 rounded-full bg-yellow-400 mr-2"></div>
                  <span class="text-sm text-gray-700 dark:text-gray-300">Junction 1</span>
                </div>
                <span class="text-gray-500 dark:text-gray-400 text-xs">Passed</span>
              </div>
              <div class="flex items-center justify-between bg-blue-100/40 dark:bg-blue-900/30 p-3 rounded-xl border border-blue-300/30 dark:border-blue-500/30 backdrop-blur-md">
                <div class="flex items-center">
                  <div class="w-2 h-2 rounded-full bg-blue-400 mr-2 animate-pulse"></div>
                  <span class="text-sm text-blue-700 dark:text-white">Blue Storage</span>
                </div>
                <span class="text-blue-500 dark:text-blue-300 text-xs font-medium">Current</span>
              </div>
              <div class="flex items-center justify-between bg-gray-100/80 dark:bg-gray-900/60 p-3 rounded-xl shadow-inner border border-gray-200/60 dark:border-white/5">
                <div class="flex items-center">
                  <div class="w-2 h-2 rounded-full bg-gray-400 dark:bg-gray-500 mr-2"></div>
                  <span class="text-sm text-gray-700 dark:text-gray-300">Return Path</span>
                </div>
                <span class="text-gray-500 dark:text-gray-400 text-xs">Next</span>
              </div>
            </div>
          </div>
        </div>
        
        <!-- Package Queue & Destination Settings -->
        <div class="grid grid-cols-1 md:grid-cols-2 gap-6 md:gap-8">
          <!-- Package Queue -->
          <div class="bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5">
            <h2 class="text-base font-medium mb-5 text-gray-800 dark:text-white flex items-center">
              <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-purple-500 dark:text-purple-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M19 11H5m14 0a2 2 0 012 2v6a2 2 0 01-2 2H5a2 2 0 01-2-2v-6a2 2 0 012-2m14 0V9a2 2 0 00-2-2M5 11V9a2 2 0 012-2m0 0V5a2 2 0 012-2h6a2 2 0 012 2v2M7 7h10" />
              </svg>
              Package Queue
            </h2>
            <div class="space-y-2.5">
              <div class="bg-gray-100/80 dark:bg-gray-900/60 p-3 rounded-xl flex justify-between items-center shadow-inner border border-gray-200/60 dark:border-white/5">
                <div class="flex items-center">
                  <div class="w-3 h-3 rounded-full bg-gradient-to-br from-yellow-400 to-yellow-600 mr-2 shadow-sm shadow-yellow-500/20"></div>
                  <span class="text-sm text-gray-800 dark:text-gray-200">Yellow Package</span>
                </div>
                <div class="text-gray-500 dark:text-gray-400 text-xs bg-gray-200/60 dark:bg-gray-800/80 px-2 py-1 rounded-full backdrop-blur-sm">Next</div>
              </div>
              <div class="bg-gray-100/80 dark:bg-gray-900/60 p-3 rounded-xl flex justify-between items-center shadow-inner border border-gray-200/60 dark:border-white/5">
                <div class="flex items-center">
                  <div class="w-3 h-3 rounded-full bg-gradient-to-br from-red-400 to-red-600 mr-2 shadow-sm shadow-red-500/20"></div>
                  <span class="text-sm text-gray-800 dark:text-gray-200">Red Package</span>
                </div>
                <div class="text-gray-500 dark:text-gray-400 text-xs bg-gray-200/60 dark:bg-gray-800/80 px-2 py-1 rounded-full backdrop-blur-sm">Pos 2</div>
              </div>
              <div class="bg-gray-100/80 dark:bg-gray-900/60 p-3 rounded-xl flex justify-between items-center shadow-inner border border-gray-200/60 dark:border-white/5">
                <div class="flex items-center">
                  <div class="w-3 h-3 rounded-full bg-gradient-to-br from-green-400 to-green-600 mr-2 shadow-sm shadow-green-500/20"></div>
                  <span class="text-sm text-gray-800 dark:text-gray-200">Green Package</span>
                </div>
                <div class="text-gray-500 dark:text-gray-400 text-xs bg-gray-200/60 dark:bg-gray-800/80 px-2 py-1 rounded-full backdrop-blur-sm">Pos 3</div>
              </div>
            </div>
            <div class="mt-4">
              <button class="bg-gray-100/80 dark:bg-gray-900/80 hover:bg-gray-200 dark:hover:bg-gray-900 text-gray-700 dark:text-white px-4 py-2 rounded-xl text-sm w-full shadow-inner border border-gray-200/60 dark:border-white/5 transition-all hover:scale-[1.02]">
                Add New Package
              </button>
            </div>
          </div>
          
          <!-- Destination Settings -->
          <div class="bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5">
            <h2 class="text-base font-medium mb-5 text-gray-800 dark:text-white flex items-center">
              <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-orange-500 dark:text-orange-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M8 7V3m8 4V3m-9 8h10M5 21h14a2 2 0 002-2V7a2 2 0 00-2-2H5a2 2 0 00-2 2v12a2 2 0 002 2z" />
              </svg>
              Destination Settings
            </h2>
            <div class="space-y-4">
              <div>
                <label class="block text-xs text-gray-500 dark:text-gray-400 mb-2 uppercase tracking-wider">Package Color</label>
                <select class="w-full bg-gray-100/80 dark:bg-gray-900/60 border border-gray-200/60 dark:border-white/5 rounded-xl px-3 py-2.5 text-gray-700 dark:text-white text-sm shadow-inner focus:outline-none focus:ring-2 focus:ring-green-500/30">
                  <option>Automatic Detection</option>
                  <option>Red</option>
                  <option>Blue</option>
                  <option>Yellow</option>
                  <option>Green</option>
                </select>
              </div>
              <div>
                <label class="block text-xs text-gray-500 dark:text-gray-400 mb-2 uppercase tracking-wider">Storage Location</label>
                <div class="grid grid-cols-2 gap-2">
                  <button class="bg-gray-100/80 dark:bg-gray-900/60 hover:bg-red-50 dark:hover:bg-red-900/20 hover:border-red-300/50 dark:hover:border-red-500/30 text-gray-700 dark:text-white py-2.5 rounded-xl text-sm flex items-center justify-center border border-gray-200/60 dark:border-white/5 transition-all">
                    <div class="w-2.5 h-2.5 rounded-full bg-gradient-to-br from-red-400 to-red-600 mr-2"></div>
                    Red Area
                  </button>
                  <button class="bg-gray-100/80 dark:bg-gray-900/60 hover:bg-blue-50 dark:hover:bg-blue-900/20 hover:border-blue-300/50 dark:hover:border-blue-500/30 text-gray-700 dark:text-white py-2.5 rounded-xl text-sm flex items-center justify-center border border-gray-200/60 dark:border-white/5 transition-all">
                    <div class="w-2.5 h-2.5 rounded-full bg-gradient-to-br from-blue-400 to-blue-600 mr-2"></div>
                    Blue Area
                  </button>
                  <button class="bg-gray-100/80 dark:bg-gray-900/60 hover:bg-yellow-50 dark:hover:bg-yellow-900/20 hover:border-yellow-300/50 dark:hover:border-yellow-500/30 text-gray-700 dark:text-white py-2.5 rounded-xl text-sm flex items-center justify-center border border-gray-200/60 dark:border-white/5 transition-all">
                    <div class="w-2.5 h-2.5 rounded-full bg-gradient-to-br from-yellow-400 to-yellow-600 mr-2"></div>
                    Yellow Area
                  </button>
                  <button class="bg-gray-100/80 dark:bg-gray-900/60 hover:bg-green-50 dark:hover:bg-green-900/20 hover:border-green-300/50 dark:hover:border-green-500/30 text-gray-700 dark:text-white py-2.5 rounded-xl text-sm flex items-center justify-center border border-gray-200/60 dark:border-white/5 transition-all">
                    <div class="w-2.5 h-2.5 rounded-full bg-gradient-to-br from-green-400 to-green-600 mr-2"></div>
                    Green Area
                  </button>
                </div>
              </div>
              <div>
                <button class="bg-gradient-to-r from-green-500 to-emerald-600 hover:from-green-600 hover:to-emerald-700 text-white px-4 py-2.5 rounded-xl text-sm w-full font-medium shadow-lg shadow-green-500/20 transition-all hover:scale-[1.02]">
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
import { onMounted } from 'vue';

// Only add animations when in browser environment
onMounted(() => {
  // This will only run on the client side
  const style = document.createElement('style');
  style.textContent = `
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
  `;
  document.head.appendChild(style);
});
</script>

