<template>
  <div class="min-h-screen bg-gradient-to-br from-gray-100 to-gray-200 dark:from-gray-950 dark:to-gray-900 text-gray-800 dark:text-white flex font-sans transition-colors duration-300">
    <!-- Sidebar -->
    <div class="w-16 md:w-64 bg-white/80 dark:bg-gray-900/80 backdrop-blur-lg border-r border-gray-200 dark:border-white/5 flex flex-col shadow-xl">
      <!-- Logo -->
      <div class="h-20 flex items-center justify-center md:justify-start p-4 border-b border-gray-200 dark:border-white/5">
        <div class="h-10 w-10 rounded-xl bg-gradient-to-br from-green-400 to-green-600 flex items-center justify-center text-white font-bold shadow-lg shadow-green-500/20">R</div>
        <span class="ml-3 text-lg font-medium tracking-tight hidden md:block">RoboStock</span>
      </div>
      
      <!-- Nav Items -->
      <div class="flex flex-col flex-1 py-6 space-y-1">
        <a href="#" class="flex items-center p-2 md:px-4 text-gray-900 dark:text-white border-l-2 border-green-500 bg-gray-200/60 dark:bg-white/5 backdrop-blur-lg">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M4 6a2 2 0 012-2h2a2 2 0 012 2v2a2 2 0 01-2 2H6a2 2 0 01-2-2V6z" />
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M14 6a2 2 0 012-2h2a2 2 0 012 2v2a2 2 0 01-2 2h-2a2 2 0 01-2-2V6z" />
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M4 16a2 2 0 012-2h2a2 2 0 012 2v2a2 2 0 01-2 2H6a2 2 0 01-2-2v-2z" />
          </svg>
          <span class="ml-3 hidden md:block text-sm font-medium">Dashboard</span>
        </a>
        <a href="#" class="flex items-center p-2 md:px-4 text-gray-600 dark:text-gray-400 hover:text-gray-900 dark:hover:text-white hover:bg-gray-200/60 dark:hover:bg-white/5 rounded-r-full transition-all duration-200">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M9 19v-6a2 2 0 00-2-2H5a2 2 0 00-2 2v6a2 2 0 002 2h2a2 2 0 002-2zm0 0V9a2 2 0 012-2h2a2 2 0 012 2v10m-6 0a2 2 0 002 2h2a2 2 0 002-2m0 0V5a2 2 0 012-2h2a2 2 0 012 2v14a2 2 0 01-2 2h-2a2 2 0 01-2-2z" />
          </svg>
          <span class="ml-3 hidden md:block text-sm font-medium">Analytics</span>
        </a>
        <a href="#" class="flex items-center p-2 md:px-4 text-gray-600 dark:text-gray-400 hover:text-gray-900 dark:hover:text-white hover:bg-gray-200/60 dark:hover:bg-white/5 rounded-r-full transition-all duration-200">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M12 6V4m0 2a2 2 0 100 4m0-4a2 2 0 110 4m-6 8a2 2 0 100-4m0 4a2 2 0 110-4m0 4v2m0-6V4m6 6v10m6-2a2 2 0 100-4m0 4a2 2 0 110-4m0 4v2m0-6V4" />
          </svg>
          <span class="ml-3 hidden md:block text-sm font-medium">Settings</span>
        </a>
        <a href="#" class="flex items-center p-2 md:px-4 text-gray-600 dark:text-gray-400 hover:text-gray-900 dark:hover:text-white hover:bg-gray-200/60 dark:hover:bg-white/5 rounded-r-full transition-all duration-200">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M12 8v4l3 3m6-3a9 9 0 11-18 0 9 9 0 0118 0z" />
          </svg>
          <span class="ml-3 hidden md:block text-sm font-medium">History</span>
        </a>
        <a href="#" class="flex items-center p-2 md:px-4 text-gray-600 dark:text-gray-400 hover:text-gray-900 dark:hover:text-white hover:bg-gray-200/60 dark:hover:bg-white/5 rounded-r-full transition-all duration-200">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M12 9v3m0 0v3m0-3h3m-3 0H9m12 0a9 9 0 11-18 0 9 9 0 0118 0z" />
          </svg>
          <span class="ml-3 hidden md:block text-sm font-medium">Add Robot</span>
        </a>
      </div>
      
      <!-- Theme Toggle & Status Indicator -->
      <div class="p-5 border-t border-gray-200 dark:border-white/5 bg-gray-100/50 dark:bg-white/5 backdrop-blur-sm mt-4">
        <div class="flex items-center justify-between mb-4">
          <div class="flex items-center">
            <div class="h-2.5 w-2.5 bg-green-400 rounded-full ring-2 ring-green-500/30 ring-offset-2 ring-offset-white dark:ring-offset-gray-900"></div>
            <span class="ml-3 text-sm text-gray-700 dark:text-white/80 hidden md:block">System Online</span>
          </div>
          <button @click="toggleTheme" class="p-1.5 rounded-full bg-gray-200 dark:bg-gray-700 text-gray-700 dark:text-gray-200 hover:bg-gray-300 dark:hover:bg-gray-600 transition-colors">
            <svg v-if="isDark" xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
              <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M12 3v1m0 16v1m9-9h-1M4 12H3m15.364 6.364l-.707-.707M6.343 6.343l-.707-.707m12.728 0l-.707.707M6.343 17.657l-.707.707M16 12a4 4 0 11-8 0 4 4 0 018 0z" />
            </svg>
            <svg v-else xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
              <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M20.354 15.354A9 9 0 018.646 3.646 9.003 9.003 0 0012 21a9.003 9.003 0 008.354-5.646z" />
            </svg>
          </button>
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
import { useTheme } from '~/composables/useTheme';

// Use the theme composable
const { isDark, toggleTheme } = useTheme();
</script>

<style>
/* Ensure Tailwind's dark mode works properly */
.dark {
  color-scheme: dark;
}
</style>
