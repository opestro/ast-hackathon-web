<!-- Notification Panel (Side Slide-out) -->
<template>
  <div class="fixed top-0 right-0 h-full w-80 bg-white/90 dark:bg-gray-800/90 backdrop-blur-xl shadow-xl transform transition-all duration-300 ease-in-out z-50 border-l border-gray-200/50 dark:border-white/5 overflow-y-auto"
    :class="[isOpen ? 'translate-x-0' : 'translate-x-full']">
    <div class="p-5">
      <div class="flex justify-between items-center mb-5">
        <h2 class="text-lg font-medium text-gray-800 dark:text-white">Notifications</h2>
        <button @click="closePanel" class="p-1 rounded-lg hover:bg-gray-100 dark:hover:bg-gray-700 text-gray-500 dark:text-gray-400">
          <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M6 18L18 6M6 6l12 12" />
          </svg>
        </button>
      </div>
      
      <div v-if="notifications.length > 0" class="space-y-4">
        <div v-for="(notification, index) in notifications" :key="index" 
          class="p-3 rounded-lg border border-gray-200/50 dark:border-white/5 shadow-md"
          :class="{
            'bg-red-50 dark:bg-red-900/20 border-red-200 dark:border-red-800/20': notification.type === 'critical',
            'bg-yellow-50 dark:bg-yellow-900/20 border-yellow-200 dark:border-yellow-800/20': notification.type === 'warning',
            'bg-blue-50 dark:bg-blue-900/20 border-blue-200 dark:border-blue-800/20': notification.type === 'info'
          }">
          <div class="flex justify-between items-start">
            <div class="flex items-start space-x-2">
              <div class="h-2.5 w-2.5 mt-1.5 rounded-full" 
                :class="{
                  'bg-red-500 animate-pulse': notification.type === 'critical',
                  'bg-yellow-500': notification.type === 'warning',
                  'bg-blue-500': notification.type === 'info'
                }"></div>
              <div>
                <p class="text-sm font-medium" 
                  :class="{
                    'text-red-800 dark:text-red-300': notification.type === 'critical',
                    'text-yellow-800 dark:text-yellow-300': notification.type === 'warning',
                    'text-blue-800 dark:text-blue-300': notification.type === 'info'
                  }">{{ notification.title }}</p>
                <p class="text-xs mt-1"
                  :class="{
                    'text-red-600 dark:text-red-400': notification.type === 'critical',
                    'text-yellow-600 dark:text-yellow-400': notification.type === 'warning',
                    'text-blue-600 dark:text-blue-400': notification.type === 'info'
                  }">{{ notification.message }}</p>
              </div>
            </div>
            <span class="text-xs text-gray-500 dark:text-gray-400">{{ notification.time }}</span>
          </div>
          <div class="mt-3 flex justify-end">
            <button @click="markAsRead(index)" class="text-xs px-2 py-1 rounded bg-white/70 dark:bg-gray-800/70 text-gray-600 dark:text-gray-300 hover:bg-white dark:hover:bg-gray-700">
              Mark as read
            </button>
          </div>
        </div>
      </div>
      
      <div v-else class="text-center py-8">
        <svg xmlns="http://www.w3.org/2000/svg" class="h-10 w-10 mx-auto text-gray-300 dark:text-gray-600" fill="none" viewBox="0 0 24 24" stroke="currentColor">
          <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M15 17h5l-1.405-1.405A2.032 2.032 0 0118 14.158V11a6.002 6.002 0 00-4-5.659V5a2 2 0 10-4 0v.341C7.67 6.165 6 8.388 6 11v3.159c0 .538-.214 1.055-.595 1.436L4 17h5m6 0v1a3 3 0 11-6 0v-1m6 0H9" />
        </svg>
        <p class="mt-2 text-gray-500 dark:text-gray-400">No notifications</p>
      </div>
      
      <div class="mt-6 border-t border-gray-200 dark:border-gray-700 pt-4">
        <button class="w-full py-2 text-sm text-gray-500 dark:text-gray-400 hover:text-gray-700 dark:hover:text-gray-200">
          View all notifications
        </button>
      </div>
    </div>
  </div>
</template>

<script setup>
import { defineProps, defineEmits } from 'vue';

const props = defineProps({
  isOpen: {
    type: Boolean,
    default: false
  },
  notifications: {
    type: Array,
    default: () => []
  }
});

const emit = defineEmits(['close', 'markAsRead']);

const closePanel = () => {
  emit('close');
};

const markAsRead = (index) => {
  emit('markAsRead', index);
};
</script> 