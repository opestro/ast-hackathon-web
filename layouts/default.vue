<template>
  <div class="min-h-screen bg-gradient-to-br from-gray-100 to-gray-200 dark:from-gray-950 dark:to-gray-900 text-gray-800 dark:text-white flex font-sans transition-colors duration-300">
    <!-- Mobile Header (visible only on small screens) -->
    <div class="fixed top-0 left-0 right-0 h-16 bg-white/90 dark:bg-gray-900/90 border-b border-gray-200 dark:border-white/5 z-20 flex items-center justify-between px-4 md:hidden backdrop-blur-lg">
      <div class="flex items-center">
        <div class="h-8 w-8 rounded-lg bg-gradient-to-br from-green-400 to-green-600 flex items-center justify-center text-white font-bold shadow-md shadow-green-500/20">R</div>
        <span class="ml-2 text-base font-medium tracking-tight">RoboStock</span>
      </div>
      <!-- Mobile menu button -->
      <button @click="toggleMobileMenu" class="p-2 rounded-lg bg-gray-200/80 dark:bg-gray-800/80 text-gray-600 dark:text-gray-300">
        <svg v-if="mobileMenuOpen" xmlns="http://www.w3.org/2000/svg" class="h-6 w-6" fill="none" viewBox="0 0 24 24" stroke="currentColor">
          <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M6 18L18 6M6 6l12 12" />
        </svg>
        <svg v-else xmlns="http://www.w3.org/2000/svg" class="h-6 w-6" fill="none" viewBox="0 0 24 24" stroke="currentColor">
          <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M4 6h16M4 12h16M4 18h16" />
        </svg>
      </button>
    </div>

    <!-- Overlay for mobile (when sidebar is open) -->
    <div v-if="mobileMenuOpen" @click="toggleMobileMenu" class="fixed inset-0 bg-black/20 dark:bg-black/50 z-10 md:hidden backdrop-blur-sm"></div>
    
    <!-- Fixed Sidebar -->
    <div :class="[
      'sidebar fixed left-0 top-0 bottom-0 backdrop-blur-lg border-r border-gray-200 dark:border-white/5 flex flex-col shadow-xl transition-all duration-300 z-30',
      isExpanded ? 'w-64 bg-white/80 dark:bg-gray-900/80' : 'w-16 bg-white/90 dark:bg-gray-900/90',
      // Mobile styles
      mobileMenuOpen ? 'translate-x-0' : '-translate-x-full md:translate-x-0'
    ]">
      <!-- Logo and Toggle (hidden on mobile) -->
      <div class="h-20 md:flex items-center justify-between p-4 border-b border-gray-200 dark:border-white/5 hidden">
        <div class="flex items-center">
          <div class="h-10 w-10 rounded-xl bg-gradient-to-br from-green-400 to-green-600 flex items-center justify-center text-white font-bold shadow-lg shadow-green-500/20">R</div>
          <span class="ml-3 text-lg font-medium tracking-tight" :class="isExpanded ? 'block' : 'hidden'">RoboStock</span>
        </div>
        <!-- Toggle button (desktop only) -->
        <button @click="toggleSidebar" class="p-1.5 rounded-full bg-gray-200/80 dark:bg-gray-800/80 text-gray-600 dark:text-gray-300 hover:bg-gray-300 dark:hover:bg-gray-700 transition-colors">
          <svg v-if="isExpanded" xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M11 19l-7-7 7-7m8 14l-7-7 7-7" />
          </svg>
          <svg v-else xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M13 5l7 7-7 7M5 5l7 7-7 7" />
          </svg>
        </button>
      </div>
      
      <!-- Mobile profile/user info -->
      <div class="flex items-center p-4 mt-16 md:hidden border-b border-gray-200 dark:border-white/5">
        <div class="h-10 w-10 rounded-full bg-gradient-to-br from-blue-400 to-blue-600 flex items-center justify-center text-white font-bold">U</div>
        <div class="ml-3">
          <p class="text-sm font-medium">User Name</p>
          <p class="text-xs text-gray-500 dark:text-gray-400">Admin</p>
        </div>
      </div>
      
      <!-- Nav Items -->
      <div class="flex flex-col flex-1 py-4 md:py-6 space-y-1 overflow-y-auto">
        <NuxtLink to="/" @click="onMobileNav" class="flex items-center p-3 md:p-2 md:px-4 text-gray-900 dark:text-white border-l-2 border-green-500 bg-gray-200/60 dark:bg-white/5 backdrop-blur-lg">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6 md:h-5 md:w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M4 6a2 2 0 012-2h2a2 2 0 012 2v2a2 2 0 01-2 2H6a2 2 0 01-2-2V6z" />
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M14 6a2 2 0 012-2h2a2 2 0 012 2v2a2 2 0 01-2 2h-2a2 2 0 01-2-2V6z" />
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M4 16a2 2 0 012-2h2a2 2 0 012 2v2a2 2 0 01-2 2H6a2 2 0 01-2-2v-2z" />
          </svg>
          <span class="ml-3 text-sm font-medium" :class="[isExpanded || mobileMenuOpen ? 'block' : 'hidden']">Dashboard</span>
        </NuxtLink>
        <NuxtLink to="/robot-monitor" @click="onMobileNav" class="flex items-center p-3 md:p-2 md:px-4 text-gray-600 dark:text-gray-400 hover:text-gray-900 dark:hover:text-white hover:bg-gray-200/60 dark:hover:bg-white/5 rounded-r-full transition-all duration-200">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6 md:h-5 md:w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M9 3v2m6-2v2M9 19v2m6-2v2M5 9H3m2 6H3m18-6h-2m2 6h-2M7 19h10a2 2 0 002-2V7a2 2 0 00-2-2H7a2 2 0 00-2 2v10a2 2 0 002 2zM9 9h6v6H9V9z" />
          </svg>
          <span class="ml-3 text-sm font-medium" :class="[isExpanded || mobileMenuOpen ? 'block' : 'hidden']">Robot Monitor</span>
        </NuxtLink>
        <NuxtLink to="/analytics" @click="onMobileNav" class="flex items-center p-3 md:p-2 md:px-4 text-gray-600 dark:text-gray-400 hover:text-gray-900 dark:hover:text-white hover:bg-gray-200/60 dark:hover:bg-white/5 rounded-r-full transition-all duration-200">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6 md:h-5 md:w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M9 19v-6a2 2 0 00-2-2H5a2 2 0 00-2 2v6a2 2 0 002 2h2a2 2 0 002-2zm0 0V9a2 2 0 012-2h2a2 2 0 012 2v10m-6 0a2 2 0 002 2h2a2 2 0 002-2m0 0V5a2 2 0 012-2h2a2 2 0 012 2v14a2 2 0 01-2 2h-2a2 2 0 01-2-2z" />
          </svg>
          <span class="ml-3 text-sm font-medium" :class="[isExpanded || mobileMenuOpen ? 'block' : 'hidden']">Analytics</span>
        </NuxtLink>
        <!-- <a href="#" @click="onMobileNav" class="flex items-center p-3 md:p-2 md:px-4 text-gray-600 dark:text-gray-400 hover:text-gray-900 dark:hover:text-white hover:bg-gray-200/60 dark:hover:bg-white/5 rounded-r-full transition-all duration-200">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6 md:h-5 md:w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M12 6V4m0 2a2 2 0 100 4m0-4a2 2 0 110 4m-6 8a2 2 0 100-4m0 4a2 2 0 110-4m0 4v2m0-6V4m6 6v10m6-2a2 2 0 100-4m0 4a2 2 0 110-4m0 4v2m0-6V4" />
          </svg>
          <span class="ml-3 text-sm font-medium" :class="[isExpanded || mobileMenuOpen ? 'block' : 'hidden']">Settings</span>
        </a> -->
        <NuxtLink to="/zones" @click="onMobileNav" class="flex items-center p-3 md:p-2 md:px-4 text-gray-600 dark:text-gray-400 hover:text-gray-900 dark:hover:text-white hover:bg-gray-200/60 dark:hover:bg-white/5 rounded-r-full transition-all duration-200">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6 md:h-5 md:w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M9 20l-5.447-2.724A1 1 0 013 16.382V5.618a1 1 0 011.447-.894L9 7m0 13l6-3m-6 3V7m6 10l4.553 2.276A1 1 0 0021 18.382V7.618a1 1 0 00-.553-.894L15 4m0 13V4m0 0L9 7" />
          </svg>
          <span class="ml-3 text-sm font-medium" :class="[isExpanded || mobileMenuOpen ? 'block' : 'hidden']">Zones</span>
        </NuxtLink>
        <!-- <a href="#" @click="onMobileNav" class="flex items-center p-3 md:p-2 md:px-4 text-gray-600 dark:text-gray-400 hover:text-gray-900 dark:hover:text-white hover:bg-gray-200/60 dark:hover:bg-white/5 rounded-r-full transition-all duration-200">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6 md:h-5 md:w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M12 8v4l3 3m6-3a9 9 0 11-18 0 9 9 0 0118 0z" />
          </svg>
          <span class="ml-3 text-sm font-medium" :class="[isExpanded || mobileMenuOpen ? 'block' : 'hidden']">History</span>
        </a> -->
        <NuxtLink to="/add-robot" @click="onMobileNav" class="flex items-center p-3 md:p-2 md:px-4 text-gray-600 dark:text-gray-400 hover:text-gray-900 dark:hover:text-white hover:bg-gray-200/60 dark:hover:bg-white/5 rounded-r-full transition-all duration-200">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6 md:h-5 md:w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M12 9v3m0 0v3m0-3h3m-3 0H9m12 0a9 9 0 11-18 0 9 9 0 0118 0z" />
          </svg>
          <span class="ml-3 text-sm font-medium" :class="[isExpanded || mobileMenuOpen ? 'block' : 'hidden']">Add Robot</span>
        </NuxtLink>
      </div>
      
      <!-- Theme Toggle & Status Indicator -->
      <div class="p-4 border-t border-gray-200 dark:border-white/5 bg-gray-100/50 dark:bg-white/5 backdrop-blur-sm">
        <div class="flex items-center justify-between">
          <div class="flex items-center" v-if="isExpanded || mobileMenuOpen">
            <div class="h-2.5 w-2.5 bg-green-400 rounded-full ring-2 ring-green-500/30 ring-offset-2 ring-offset-white dark:ring-offset-gray-900"></div>
            <span class="ml-3 text-sm text-gray-700 dark:text-white/80">System Online</span>
          </div>
          <button @click="toggleTheme" class="p-1.5 rounded-full bg-gray-200 dark:bg-gray-700 text-gray-700 dark:text-gray-200 hover:bg-gray-300 dark:hover:bg-gray-600 transition-colors ml-auto">
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
    
    <!-- Main Content with sidebar margin -->
    <div :class="['flex-1 overflow-auto transition-all duration-300 md:ml-16', 
                 isExpanded && !mobileMenuOpen ? 'md:ml-64' : '', 
                 'pt-16 md:pt-0']"> <!-- Added top padding for mobile header -->
      <NuxtPage />
    </div>
  </div>
</template>

<script setup>
import { ref, watch, onMounted, onUnmounted } from 'vue';
import { useTheme } from '~/composables/useTheme';

// Use the theme composable
const { isDark, toggleTheme } = useTheme();

// Sidebar state
const isExpanded = ref(true);
const mobileMenuOpen = ref(false);

// Handle window resize to auto-close mobile menu on larger screens
const handleResize = () => {
  if (window.innerWidth >= 768 && mobileMenuOpen.value) {
    mobileMenuOpen.value = false;
  }
};

// Toggle sidebar expanded/collapsed state (desktop only)
const toggleSidebar = () => {
  isExpanded.value = !isExpanded.value;
  // Save preference in localStorage
  if (process.client) {
    localStorage.setItem('sidebarExpanded', isExpanded.value.toString());
  }
};

// Toggle mobile menu
const toggleMobileMenu = () => {
  mobileMenuOpen.value = !mobileMenuOpen.value;
};

// Close mobile menu after navigation
const onMobileNav = () => {
  if (window.innerWidth < 768) {
    mobileMenuOpen.value = false;
  }
};

// Set up event listeners
onMounted(() => {
  window.addEventListener('resize', handleResize);
  
  // Add swipe detection for mobile
  let touchStartX = 0;
  let touchEndX = 0;
  
  document.addEventListener('touchstart', e => {
    touchStartX = e.changedTouches[0].screenX;
  }, { passive: true });
  
  document.addEventListener('touchend', e => {
    touchEndX = e.changedTouches[0].screenX;
    handleSwipe();
  }, { passive: true });
  
  function handleSwipe() {
    const SWIPE_THRESHOLD = 100;
    
    // Right swipe (to open menu)
    if (touchEndX - touchStartX > SWIPE_THRESHOLD && touchStartX < 50) {
      mobileMenuOpen.value = true;
    }
    
    // Left swipe (to close menu)
    if (touchStartX - touchEndX > SWIPE_THRESHOLD && mobileMenuOpen.value) {
      mobileMenuOpen.value = false;
    }
  }
  
  // Initialize sidebar state from localStorage (desktop only)
  if (process.client) {
    const savedState = localStorage.getItem('sidebarExpanded');
    if (savedState !== null) {
      isExpanded.value = savedState === 'true';
    }
  }
});

onUnmounted(() => {
  window.removeEventListener('resize', handleResize);
});
</script>

<style>
/* Ensure Tailwind's dark mode works properly */
.dark {
  color-scheme: dark;
}

/* Make sure fullscreen properly handles the fixed sidebar */
:global(.fullscreen-zone) .sidebar,
:global(.fullscreen-zone) .mobile-header {
  display: none !important; 
}

:global(.fullscreen-zone) .ml-16,
:global(.fullscreen-zone) .md\:ml-64,
:global(.fullscreen-zone) .ml-64 {
  margin-left: 0 !important;
}

:global(.fullscreen-zone) .pt-16 {
  padding-top: 0 !important;
}

/* Prevent scrolling when mobile menu is open */
.no-scroll {
  overflow: hidden !important;
}

/* Touch area improvements for mobile */
@media (max-width: 767px) {
  .sidebar a, 
  .sidebar button {
    min-height: 44px;
  }
}
</style>
