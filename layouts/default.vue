<template>
  <div class="min-h-screen bg-gray-900 text-white flex">
    <!-- Sidebar -->
    <div class="w-16 md:w-64 bg-gray-800 border-r border-gray-700 flex flex-col">
      <!-- Logo -->
      <div class="h-16 flex items-center justify-center md:justify-start p-4 border-b border-gray-700">
        <div class="h-8 w-8 rounded-md bg-green-500 flex items-center justify-center text-white font-bold">R</div>
        <span class="ml-3 text-lg font-bold hidden md:block">RoboStock</span>
      </div>
      
      <!-- Nav Items -->
      <div class="flex flex-col flex-1 py-4">
        <a href="#" class="flex items-center p-2 md:px-4 text-green-400 border-l-2 border-green-500">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M4 6a2 2 0 012-2h2a2 2 0 012 2v2a2 2 0 01-2 2H6a2 2 0 01-2-2V6z" />
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M14 6a2 2 0 012-2h2a2 2 0 012 2v2a2 2 0 01-2 2h-2a2 2 0 01-2-2V6z" />
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M4 16a2 2 0 012-2h2a2 2 0 012 2v2a2 2 0 01-2 2H6a2 2 0 01-2-2v-2z" />
          </svg>
          <span class="ml-3 hidden md:block">Dashboard</span>
        </a>
        <a href="#" class="flex items-center p-2 md:px-4 text-gray-400 hover:text-green-400 mt-2">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 19v-6a2 2 0 00-2-2H5a2 2 0 00-2 2v6a2 2 0 002 2h2a2 2 0 002-2zm0 0V9a2 2 0 012-2h2a2 2 0 012 2v10m-6 0a2 2 0 002 2h2a2 2 0 002-2m0 0V5a2 2 0 012-2h2a2 2 0 012 2v14a2 2 0 01-2 2h-2a2 2 0 01-2-2z" />
          </svg>
          <span class="ml-3 hidden md:block">Analytics</span>
        </a>
        <a href="#" class="flex items-center p-2 md:px-4 text-gray-400 hover:text-green-400 mt-2">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 6V4m0 2a2 2 0 100 4m0-4a2 2 0 110 4m-6 8a2 2 0 100-4m0 4a2 2 0 110-4m0 4v2m0-6V4m6 6v10m6-2a2 2 0 100-4m0 4a2 2 0 110-4m0 4v2m0-6V4" />
          </svg>
          <span class="ml-3 hidden md:block">Settings</span>
        </a>
        <a href="#" class="flex items-center p-2 md:px-4 text-gray-400 hover:text-green-400 mt-2">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 8v4l3 3m6-3a9 9 0 11-18 0 9 9 0 0118 0z" />
          </svg>
          <span class="ml-3 hidden md:block">History</span>
        </a>
        <a href="#" class="flex items-center p-2 md:px-4 text-gray-400 hover:text-green-400 mt-2">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 9v3m0 0v3m0-3h3m-3 0H9m12 0a9 9 0 11-18 0 9 9 0 0118 0z" />
          </svg>
          <span class="ml-3 hidden md:block">Add Robot</span>
        </a>
      </div>
      
      <!-- Status Indicator -->
      <div class="p-4 border-t border-gray-700">
        <div class="flex items-center">
          <div class="h-3 w-3 bg-green-500 rounded-full"></div>
          <span class="ml-2 text-sm hidden md:block">Online</span>
        </div>
      </div>
    </div>
    
    <!-- Main Content -->
    <div class="flex-1 overflow-auto">
      <NuxtPage />
    </div>
  </div>
</template>

<script setup>
// You can add your layout logic here
</script>
