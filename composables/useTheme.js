import { ref, watch } from 'vue';
import { useNuxtApp } from '#app';

// Using a custom composable to manage theme state across components
export const useTheme = () => {
  // Create a state that can be accessed application-wide
  const nuxtApp = useNuxtApp();
  
  // Helper function to update HTML class for Tailwind dark mode
  const updateHTMLClass = (isDark) => {
    if (process.client) {
      console.log('Updating HTML class, isDark:', isDark);
      if (isDark) {
        document.documentElement.classList.add('dark');
      } else {
        document.documentElement.classList.remove('dark');
      }
    }
  };
  
  // Initialize theme state or access the existing one
  if (!nuxtApp.provide.theme) {
    // Default to light theme for consistent server/client initial render
    const isDark = ref(false);
    
    // Set up the theme state
    nuxtApp.provide.theme = isDark;
    
    // If running on client, initialize theme from localStorage or system preference
    if (process.client) {
      // Check if we already retrieved the theme preference
      if (!nuxtApp.provide.themeInitialized) {
        const savedTheme = localStorage.getItem('color-theme');
        if (savedTheme) {
          isDark.value = savedTheme === 'dark';
        } else {
          // Check system preference
          isDark.value = window.matchMedia('(prefers-color-scheme: dark)').matches;
        }
        
        // Apply theme to document element for Tailwind
        updateHTMLClass(isDark.value);
        nuxtApp.provide.themeInitialized = true;
      }
      
      // Watch for changes to update HTML class and localStorage
      watch(isDark, (newValue) => {
        console.log('Watch detected theme change:', newValue);
        updateHTMLClass(newValue);
        localStorage.setItem('color-theme', newValue ? 'dark' : 'light');
      });
    }
  }
  
  // Function to toggle the theme
  const toggleTheme = () => {
    if (process.client) {
      console.log('Toggle theme called, current value:', nuxtApp.provide.theme.value);
      const newValue = !nuxtApp.provide.theme.value;
      console.log('Setting new value:', newValue);
      nuxtApp.provide.theme.value = newValue;
      console.log('Value after update:', nuxtApp.provide.theme.value);
      
      // Force update in case reactivity isn't triggering
      updateHTMLClass(newValue);
      localStorage.setItem('color-theme', newValue ? 'dark' : 'light');
    }
  };
  
  return {
    isDark: nuxtApp.provide.theme,
    toggleTheme
  };
}; 