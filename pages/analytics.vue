<template>
  <div class="p-6 md:p-8">
    <!-- Header -->
    <div class="mb-8">
      <h1 class="text-2xl md:text-3xl font-light tracking-tight text-gray-900 dark:text-white">Performance <span class="font-bold">Analytics</span></h1>
      <p class="text-gray-500 dark:text-gray-400 mt-1 tracking-wide text-sm">Monitor robot performance and warehouse metrics</p>
    </div>
    
    <!-- Stats Overview -->
    <div class="grid grid-cols-2 md:grid-cols-4 gap-4 mb-8">
      <div class="bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5">
        <p class="text-gray-500 dark:text-gray-400 text-xs uppercase tracking-wider mb-1">Packages Today</p>
        <div class="flex items-center">
          <h3 class="text-2xl font-medium text-gray-800 dark:text-white">127</h3>
          <span class="ml-2 text-xs px-2 py-1 rounded-full bg-green-100 dark:bg-green-900/40 text-green-600 dark:text-green-400">+12%</span>
        </div>
      </div>
      
      <div class="bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5">
        <p class="text-gray-500 dark:text-gray-400 text-xs uppercase tracking-wider mb-1">Active Robots</p>
        <div class="flex items-center">
          <h3 class="text-2xl font-medium text-gray-800 dark:text-white">4</h3>
          <span class="ml-2 text-xs px-2 py-1 rounded-full bg-green-100 dark:bg-green-900/40 text-green-600 dark:text-green-400">All Online</span>
        </div>
      </div>
      
      <div class="bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5">
        <p class="text-gray-500 dark:text-gray-400 text-xs uppercase tracking-wider mb-1">Efficiency Rate</p>
        <div class="flex items-center">
          <h3 class="text-2xl font-medium text-gray-800 dark:text-white">92%</h3>
          <span class="ml-2 text-xs px-2 py-1 rounded-full bg-yellow-100 dark:bg-yellow-900/40 text-yellow-600 dark:text-yellow-400">-2%</span>
        </div>
      </div>
      
      <div class="bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5">
        <p class="text-gray-500 dark:text-gray-400 text-xs uppercase tracking-wider mb-1">System Uptime</p>
        <div class="flex items-center">
          <h3 class="text-2xl font-medium text-gray-800 dark:text-white">99.8%</h3>
          <span class="ml-2 text-xs px-2 py-1 rounded-full bg-green-100 dark:bg-green-900/40 text-green-600 dark:text-green-400">Stable</span>
        </div>
      </div>
    </div>
    
    <!-- Main Content Grid -->
    <div class="grid grid-cols-1 lg:grid-cols-3 gap-6 md:gap-8">
      <!-- Performance Chart -->
      <div class="lg:col-span-2 bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5">
        <div class="flex justify-between items-center mb-6">
          <h2 class="text-base font-medium text-gray-800 dark:text-white flex items-center">
            <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-blue-500 dark:text-blue-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
              <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 19v-6a2 2 0 00-2-2H5a2 2 0 00-2 2v6a2 2 0 002 2h2a2 2 0 002-2zm0 0V9a2 2 0 012-2h2a2 2 0 012 2v10m-6 0a2 2 0 002 2h2a2 2 0 002-2m0 0V5a2 2 0 012-2h2a2 2 0 012 2v14a2 2 0 01-2 2h-2a2 2 0 01-2-2z" />
            </svg>
            Packages Processed
          </h2>
          <div class="flex space-x-2">
            <button class="px-3 py-1 text-xs bg-blue-500/10 hover:bg-blue-500/20 text-blue-600 dark:text-blue-400 rounded-full">Day</button>
            <button class="px-3 py-1 text-xs bg-gray-100 dark:bg-gray-700 text-gray-600 dark:text-gray-300 rounded-full">Week</button>
            <button class="px-3 py-1 text-xs bg-gray-100 dark:bg-gray-700 text-gray-600 dark:text-gray-300 rounded-full">Month</button>
          </div>
        </div>
        
        <!-- Chart Placeholder -->
        <div class="h-72 relative">
          <!-- X Axis -->
          <div class="absolute bottom-0 left-0 right-0 h-px bg-gray-200 dark:bg-gray-700"></div>
          
          <!-- Y Axis -->
          <div class="absolute top-0 bottom-0 left-0 w-px bg-gray-200 dark:bg-gray-700"></div>
          
          <!-- Bars -->
          <div class="absolute bottom-4 left-[10%] h-[30%] w-6 bg-gradient-to-t from-blue-500 to-blue-400 rounded-t-md opacity-70"></div>
          <div class="absolute bottom-4 left-[20%] h-[45%] w-6 bg-gradient-to-t from-blue-500 to-blue-400 rounded-t-md opacity-70"></div>
          <div class="absolute bottom-4 left-[30%] h-[38%] w-6 bg-gradient-to-t from-blue-500 to-blue-400 rounded-t-md opacity-70"></div>
          <div class="absolute bottom-4 left-[40%] h-[60%] w-6 bg-gradient-to-t from-blue-500 to-blue-400 rounded-t-md opacity-70"></div>
          <div class="absolute bottom-4 left-[50%] h-[75%] w-6 bg-gradient-to-t from-blue-500 to-blue-400 rounded-t-md opacity-70"></div>
          <div class="absolute bottom-4 left-[60%] h-[55%] w-6 bg-gradient-to-t from-blue-500 to-blue-400 rounded-t-md opacity-70"></div>
          <div class="absolute bottom-4 left-[70%] h-[62%] w-6 bg-gradient-to-t from-blue-500 to-blue-400 rounded-t-md opacity-70"></div>
          <div class="absolute bottom-4 left-[80%] h-[80%] w-6 bg-gradient-to-t from-blue-500 to-blue-400 rounded-t-md opacity-70"></div>
          
          <!-- X Axis Labels -->
          <div class="absolute bottom-0 left-[10%] text-xs text-gray-500 dark:text-gray-400 -translate-x-1/2 translate-y-6">8AM</div>
          <div class="absolute bottom-0 left-[30%] text-xs text-gray-500 dark:text-gray-400 -translate-x-1/2 translate-y-6">10AM</div>
          <div class="absolute bottom-0 left-[50%] text-xs text-gray-500 dark:text-gray-400 -translate-x-1/2 translate-y-6">12PM</div>
          <div class="absolute bottom-0 left-[70%] text-xs text-gray-500 dark:text-gray-400 -translate-x-1/2 translate-y-6">2PM</div>
          
          <!-- Y Axis Labels -->
          <div class="absolute top-0 left-0 text-xs text-gray-500 dark:text-gray-400 -translate-y-3 -translate-x-6">100</div>
          <div class="absolute top-[25%] left-0 text-xs text-gray-500 dark:text-gray-400 -translate-y-1/2 -translate-x-6">75</div>
          <div class="absolute top-[50%] left-0 text-xs text-gray-500 dark:text-gray-400 -translate-y-1/2 -translate-x-6">50</div>
          <div class="absolute top-[75%] left-0 text-xs text-gray-500 dark:text-gray-400 -translate-y-1/2 -translate-x-6">25</div>
        </div>
      </div>
      
      <!-- Robot Status -->
      <div class="bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5">
        <h2 class="text-base font-medium mb-5 text-gray-800 dark:text-white flex items-center">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-green-500 dark:text-green-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M5 12h14M5 12a2 2 0 01-2-2V6a2 2 0 012-2h14a2 2 0 012 2v4a2 2 0 01-2 2M5 12a2 2 0 00-2 2v4a2 2 0 002 2h14a2 2 0 002-2v-4a2 2 0 00-2-2m-2-4h.01M17 16h.01" />
          </svg>
          Robot Fleet Status
        </h2>
        
        <div class="space-y-4">
          <div class="p-3 bg-gray-100/80 dark:bg-gray-900/60 rounded-lg flex items-center justify-between">
            <div class="flex items-center">
              <div class="h-2.5 w-2.5 bg-green-400 rounded-full mr-2"></div>
              <span class="text-gray-800 dark:text-white font-medium">RB-001</span>
            </div>
            <span class="text-xs bg-green-500/10 text-green-600 dark:text-green-400 px-2 py-1 rounded-full">Active</span>
          </div>
          
          <div class="p-3 bg-gray-100/80 dark:bg-gray-900/60 rounded-lg flex items-center justify-between">
            <div class="flex items-center">
              <div class="h-2.5 w-2.5 bg-green-400 rounded-full mr-2"></div>
              <span class="text-gray-800 dark:text-white font-medium">RB-002</span>
            </div>
            <span class="text-xs bg-green-500/10 text-green-600 dark:text-green-400 px-2 py-1 rounded-full">Active</span>
          </div>
          
          <div class="p-3 bg-gray-100/80 dark:bg-gray-900/60 rounded-lg flex items-center justify-between">
            <div class="flex items-center">
              <div class="h-2.5 w-2.5 bg-green-400 rounded-full mr-2"></div>
              <span class="text-gray-800 dark:text-white font-medium">RB-003</span>
            </div>
            <span class="text-xs bg-green-500/10 text-green-600 dark:text-green-400 px-2 py-1 rounded-full">Active</span>
          </div>
          
          <div class="p-3 bg-gray-100/80 dark:bg-gray-900/60 rounded-lg flex items-center justify-between">
            <div class="flex items-center">
              <div class="h-2.5 w-2.5 bg-yellow-400 rounded-full mr-2"></div>
              <span class="text-gray-800 dark:text-white font-medium">RB-004</span>
            </div>
            <span class="text-xs bg-yellow-500/10 text-yellow-600 dark:text-yellow-400 px-2 py-1 rounded-full">Charging</span>
          </div>
          
          <div class="p-3 bg-gray-100/80 dark:bg-gray-900/60 rounded-lg flex items-center justify-between">
            <div class="flex items-center">
              <div class="h-2.5 w-2.5 bg-red-400 rounded-full mr-2"></div>
              <span class="text-gray-800 dark:text-white font-medium">RB-005</span>
            </div>
            <span class="text-xs bg-red-500/10 text-red-600 dark:text-red-400 px-2 py-1 rounded-full">Maintenance</span>
          </div>
        </div>
      </div>
      
      <!-- Error Logs -->
      <div class="lg:col-span-2 bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5">
        <h2 class="text-base font-medium mb-5 text-gray-800 dark:text-white flex items-center">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-red-500 dark:text-red-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 9v2m0 4h.01m-6.938 4h13.856c1.54 0 2.502-1.667 1.732-3L13.732 4c-.77-1.333-2.694-1.333-3.464 0L3.34 16c-.77 1.333.192 3 1.732 3z" />
          </svg>
          System Alerts
        </h2>
        
        <div class="overflow-hidden">
          <table class="min-w-full">
            <thead>
              <tr>
                <th class="px-3 py-2 text-left text-xs font-medium text-gray-500 dark:text-gray-400 uppercase tracking-wider">Time</th>
                <th class="px-3 py-2 text-left text-xs font-medium text-gray-500 dark:text-gray-400 uppercase tracking-wider">Robot</th>
                <th class="px-3 py-2 text-left text-xs font-medium text-gray-500 dark:text-gray-400 uppercase tracking-wider">Alert</th>
                <th class="px-3 py-2 text-left text-xs font-medium text-gray-500 dark:text-gray-400 uppercase tracking-wider">Status</th>
              </tr>
            </thead>
            <tbody class="divide-y divide-gray-200 dark:divide-gray-700">
              <tr>
                <td class="px-3 py-2 text-xs text-gray-700 dark:text-gray-300">10:42 AM</td>
                <td class="px-3 py-2 text-xs text-gray-700 dark:text-gray-300">RB-004</td>
                <td class="px-3 py-2 text-xs text-gray-700 dark:text-gray-300">Low Battery Warning</td>
                <td class="px-3 py-2 text-xs">
                  <span class="px-2 py-0.5 rounded-full bg-yellow-100 dark:bg-yellow-900/40 text-yellow-600 dark:text-yellow-400">Charging</span>
                </td>
              </tr>
              <tr>
                <td class="px-3 py-2 text-xs text-gray-700 dark:text-gray-300">09:15 AM</td>
                <td class="px-3 py-2 text-xs text-gray-700 dark:text-gray-300">RB-005</td>
                <td class="px-3 py-2 text-xs text-gray-700 dark:text-gray-300">Motor Overheating</td>
                <td class="px-3 py-2 text-xs">
                  <span class="px-2 py-0.5 rounded-full bg-red-100 dark:bg-red-900/40 text-red-600 dark:text-red-400">Unresolved</span>
                </td>
              </tr>
              <tr>
                <td class="px-3 py-2 text-xs text-gray-700 dark:text-gray-300">Yesterday</td>
                <td class="px-3 py-2 text-xs text-gray-700 dark:text-gray-300">RB-002</td>
                <td class="px-3 py-2 text-xs text-gray-700 dark:text-gray-300">Obstacle Detection Error</td>
                <td class="px-3 py-2 text-xs">
                  <span class="px-2 py-0.5 rounded-full bg-green-100 dark:bg-green-900/40 text-green-600 dark:text-green-400">Resolved</span>
                </td>
              </tr>
              <tr>
                <td class="px-3 py-2 text-xs text-gray-700 dark:text-gray-300">Yesterday</td>
                <td class="px-3 py-2 text-xs text-gray-700 dark:text-gray-300">RB-001</td>
                <td class="px-3 py-2 text-xs text-gray-700 dark:text-gray-300">Navigation System Restart</td>
                <td class="px-3 py-2 text-xs">
                  <span class="px-2 py-0.5 rounded-full bg-green-100 dark:bg-green-900/40 text-green-600 dark:text-green-400">Resolved</span>
                </td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      
      <!-- Efficiency Metrics -->
      <div class="bg-white/80 dark:bg-gray-800/40 backdrop-blur-xl rounded-xl p-5 shadow-lg border border-gray-200/80 dark:border-white/5">
        <h2 class="text-base font-medium mb-5 text-gray-800 dark:text-white flex items-center">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4 mr-2 text-purple-500 dark:text-purple-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 12l2 2 4-4m5.618-4.016A11.955 11.955 0 0112 2.944a11.955 11.955 0 01-8.618 3.04A12.02 12.02 0 003 9c0 5.591 3.824 10.29 9 11.622 5.176-1.332 9-6.03 9-11.622 0-1.042-.133-2.052-.382-3.016z" />
          </svg>
          Performance Metrics
        </h2>
        
        <div class="space-y-4">
          <div>
            <div class="flex justify-between mb-1">
              <span class="text-xs text-gray-700 dark:text-gray-300">Battery Efficiency</span>
              <span class="text-xs text-gray-700 dark:text-gray-300">92%</span>
            </div>
            <div class="w-full h-2 bg-gray-200 dark:bg-gray-700 rounded-full">
              <div class="h-2 bg-gradient-to-r from-purple-500 to-purple-600 rounded-full" style="width: 92%"></div>
            </div>
          </div>
          
          <div>
            <div class="flex justify-between mb-1">
              <span class="text-xs text-gray-700 dark:text-gray-300">Path Optimization</span>
              <span class="text-xs text-gray-700 dark:text-gray-300">87%</span>
            </div>
            <div class="w-full h-2 bg-gray-200 dark:bg-gray-700 rounded-full">
              <div class="h-2 bg-gradient-to-r from-green-500 to-green-600 rounded-full" style="width: 87%"></div>
            </div>
          </div>
          
          <div>
            <div class="flex justify-between mb-1">
              <span class="text-xs text-gray-700 dark:text-gray-300">Package Accuracy</span>
              <span class="text-xs text-gray-700 dark:text-gray-300">99%</span>
            </div>
            <div class="w-full h-2 bg-gray-200 dark:bg-gray-700 rounded-full">
              <div class="h-2 bg-gradient-to-r from-blue-500 to-blue-600 rounded-full" style="width: 99%"></div>
            </div>
          </div>
          
          <div>
            <div class="flex justify-between mb-1">
              <span class="text-xs text-gray-700 dark:text-gray-300">Error Recovery</span>
              <span class="text-xs text-gray-700 dark:text-gray-300">78%</span>
            </div>
            <div class="w-full h-2 bg-gray-200 dark:bg-gray-700 rounded-full">
              <div class="h-2 bg-gradient-to-r from-yellow-500 to-yellow-600 rounded-full" style="width: 78%"></div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script setup>
// You can add reactive data and methods here if needed
</script> 