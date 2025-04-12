<template>
  <div class="p-6 md:p-8">
    <!-- Zone Header Component -->
    <ZoneHeader 
      :zones="zones" 
      :is-fullscreen="isFullscreen" 
      :selected-zone-id="activeZone.id"
      :unread-notifications="unreadNotificationsCount"
      @toggle-fullscreen="toggleFullscreen"
      @toggle-notifications="toggleNotifications"
      @select-zone="onZoneSelect"
    />
    
    <!-- Zone Overview Component -->
    <ZoneOverview 
      :zone-id="activeZone.id"
      :zone-name="activeZone.name"
      :zone-description="activeZone.description"
      :zone-status="activeZone.status"
      :zone-color="zoneColors[activeZone.id] || 'from-blue-500 to-blue-600'"
      :robot-count="activeZone.robotCount"
      :package-count="activeZone.packageCount"
      :throughput="activeZone.throughput"
      :efficiency="activeZone.efficiency"
    />
    
    <!-- Main Content -->
    <div class="grid  grid-cols lg:grid-cols-4 gap-6">
       <!-- Zone Map Component -->
       <ZoneMap 
       :robots="activeZone.robots"
       :zone-name="activeZone.name"
       :zone-color="zoneColors[activeZone.id] || 'from-blue-500 to-blue-600'"
     />
      <!-- Robot List Component -->
      <RobotList 
        :robots="activeZone.robots" 
        :zone-name="activeZone.name"
        :selected-robot-id="selectedRobot?.id"
        @select-robot="selectRobot"
      />
      
     
    </div>
    
    <!-- Secondary Content -->
    <div class="grid grid-cols-1 md:grid-cols-2 gap-6 mt-8">
      <!-- Performance Chart Component -->
      <PerformanceChart 
        :throughput-data="[activeZone.throughput - 5, activeZone.throughput - 10, activeZone.throughput - 2, activeZone.throughput + 3, activeZone.throughput - 8, activeZone.throughput - 1, activeZone.throughput]"
        :efficiency-data="[activeZone.efficiency - 3, activeZone.efficiency - 7, activeZone.efficiency - 5, activeZone.efficiency + 1, activeZone.efficiency - 10, activeZone.efficiency - 2, activeZone.efficiency]"
        :robot-utilization-data="[75, 72, 80, 78, 82, 79, 85]"
      />
      
      <!-- Activity Timeline Component -->
      <ActivityTimeline 
        :activities="activeZone.recentActivities"
      />
    </div>
  </div>

  <!-- Floating Action Button (Mobile Only) -->
  <button v-show="isFullscreen" @click="toggleFullscreen" class="fixed bottom-6 right-6 md:hidden bg-white dark:bg-gray-800 p-3 rounded-full shadow-xl border border-gray-200 dark:border-gray-700 z-50">
    <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6 text-gray-600 dark:text-gray-300" fill="none" viewBox="0 0 24 24" stroke="currentColor">
      <path stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" d="M6 18L18 6M6 6l12 12" />
    </svg>
  </button>

  <!-- Robot Detail Panel Component -->
  <RobotDetailPanel 
    :robot="selectedRobot"
    @close="selectedRobot = null"
    @send-to-charging-station="sendToChargingStation"
    @assign-new-task="assignNewTask"
    @change-zone="changeZone"
  />

  <!-- Notification Panel Component -->
  <NotificationPanel 
    :is-open="showNotifications"
    :notifications="notifications"
    @close="showNotifications = false"
    @mark-as-read="markAsRead"
  />
</template>

<script setup>
import { ref, computed, onMounted, onUnmounted } from 'vue';
import ZoneHeader from '@/components/zones/ZoneHeader.vue';
import ZoneOverview from '@/components/zones/ZoneOverview.vue';
import RobotList from '@/components/zones/RobotList.vue';
import ZoneMap from '@/components/zones/ZoneMap.vue';
import PerformanceChart from '@/components/zones/PerformanceChart.vue';
import ActivityTimeline from '@/components/zones/ActivityTimeline.vue';
import RobotDetailPanel from '@/components/zones/RobotDetailPanel.vue';
import NotificationPanel from '@/components/zones/NotificationPanel.vue';

// Fullscreen mode state
const isFullscreen = ref(false);
const showNotifications = ref(false);
const selectedRobot = ref(null);

// Mock zones data
const zones = ref([
  {
    id: "zone-a",
    name: "Zone A",
    description: "Storage & Inventory",
    status: "Active",
    alerts: 1,
    robotCount: 3,
    packageCount: 450,
    throughput: 65,
    efficiency: 92,
    robots: [
      {
        id: "RB-001",
        model: "LineFollower Pro",
        status: "Active",
        position: { x: 12.5, y: 33.33 }
      },
      {
        id: "RB-002",
        model: "Sorter X1",
        status: "Active",
        position: { x: 37.5, y: 16.67 }
      },
      {
        id: "RB-004",
        model: "Transport T3",
        status: "Charging",
        position: { x: 25, y: 50 }
      }
    ],
    recentActivities: [
      {
        id: "act-1",
        type: "package",
        message: "Package #A78945 processed by RB-001",
        time: "15 minutes ago"
      },
      {
        id: "act-2",
        type: "robot",
        message: "RB-004 started charging cycle",
        time: "45 minutes ago"
      },
      {
        id: "act-3",
        type: "system",
        message: "Zone throughput increased by 5%",
        time: "2 hours ago"
      },
      {
        id: "act-4",
        type: "package",
        message: "Batch #45623 processed and shipped",
        time: "4 hours ago"
      }
    ]
  },
  {
    id: "zone-b",
    name: "Zone B",
    description: "Packaging & Shipping",
    status: "Active",
    alerts: 0,
    robotCount: 5,
    packageCount: 320,
    throughput: 58,
    efficiency: 87,
    robots: [
      {
        id: "RB-003",
        model: "Packager P2",
        status: "Active",
        position: { x: 62.5, y: 25 }
      },
      {
        id: "RB-005",
        model: "Transport T3",
        status: "Active",
        position: { x: 75, y: 66.67 }
      }
    ],
    recentActivities: []
  },
  {
    id: "zone-c",
    name: "Zone C",
    description: "Receiving & Sorting",
    status: "Maintenance",
    alerts: 2,
    robotCount: 2,
    packageCount: 180,
    throughput: 42,
    efficiency: 76,
    robots: [
      {
        id: "RB-006",
        model: "Sorter X1",
        status: "Maintenance",
        position: { x: 50, y: 75 }
      }
    ],
    recentActivities: []
  }
]);

// Map zone IDs to colors for consistent styling
const zoneColors = {
  "zone-a": "from-blue-500 to-blue-600",
  "zone-b": "from-purple-500 to-purple-600",
  "zone-c": "from-orange-500 to-orange-600"
};

// Active zone
const activeZone = ref(zones.value[0]);

// Mock notifications
const notifications = ref([
  {
    type: 'critical',
    title: 'Robot RB-006 battery critical',
    message: 'Battery level below 10%. Please send to charging station immediately.',
    time: '2 min ago',
  },
  {
    type: 'warning',
    title: 'Obstacle detected in Zone B',
    message: 'Multiple robots reporting navigation difficulties.',
    time: '15 min ago',
  },
  {
    type: 'info',
    title: 'Task completed',
    message: 'Robot RB-002 has completed package delivery to Zone C.',
    time: '1 hour ago',
  },
]);

// Computed properties
const unreadNotificationsCount = computed(() => notifications.value.length);

// Toggle fullscreen mode
const toggleFullscreen = () => {
  if (!process.client) return;
  
  const mainContent = document.querySelector('.flex-1');
  const parentElement = document.querySelector('.p-6.md\\:p-8')?.parentElement;
  
  if (!isFullscreen.value) {
    // Enter fullscreen mode
    isFullscreen.value = true;
    
    // Force scrollable content 
    if (mainContent) {
      mainContent.style.overflowY = 'auto';
      mainContent.style.height = '100vh';
      mainContent.style.marginLeft = '0';
    }
    
    // Add parent class for proper positioning
    if (parentElement) {
      parentElement.classList.add('fullscreen-mode-parent');
    }
    
    // Request fullscreen
    const element = document.documentElement;
    if (element.requestFullscreen) {
      element.requestFullscreen();
    } else if (element.mozRequestFullScreen) {
      element.mozRequestFullScreen();
    } else if (element.webkitRequestFullscreen) {
      element.webkitRequestFullscreen();
    } else if (element.msRequestFullscreen) {
      element.msRequestFullscreen();
    }
    
    // Add fullscreen class directly to html element
    document.documentElement.classList.add('fullscreen-zone');
    document.body.style.overflow = 'auto';
    setTimeout(() => window.scrollTo(0, 0), 100);
  } else {
    // Exit fullscreen mode
    isFullscreen.value = false;
    
    // Reset main content
    if (mainContent) {
      mainContent.style.overflowY = '';
      mainContent.style.height = '';
      // Restore margin - will be automatically handled by responsive classes
    }
    
    // Remove parent class
    if (parentElement) {
      parentElement.classList.remove('fullscreen-mode-parent');
    }
    
    // Exit fullscreen
    if (document.exitFullscreen) {
      document.exitFullscreen();
    } else if (document.mozCancelFullScreen) {
      document.mozCancelFullScreen();
    } else if (document.webkitExitFullscreen) {
      document.webkitExitFullscreen();
    } else if (document.msExitFullscreen) {
      document.msExitFullscreen();
    }
    
    // Remove fullscreen class
    document.documentElement.classList.remove('fullscreen-zone');
    document.body.style.overflow = '';
    selectedRobot.value = null;
  }
};

// Toggle notifications panel
const toggleNotifications = () => {
  showNotifications.value = !showNotifications.value;
};

// Handle zone selection
const onZoneSelect = (zone) => {
  activeZone.value = zone;
  selectedRobot.value = null;
};

// Select a robot to view details
const selectRobot = (robot) => {
  selectedRobot.value = robot;
};

// Mark notification as read
const markAsRead = (index) => {
  notifications.value.splice(index, 1);
};

// Robot control functions
const sendToChargingStation = (robot) => {
  alert(`Sending ${robot.id} to charging station`);
};

const assignNewTask = (robot) => {
  alert(`Assigning new task to ${robot.id}`);
};

const changeZone = (robot) => {
  alert(`Changing zone assignment for ${robot.id}`);
};

// Handle keyboard shortcuts
const handleKeyPress = (e) => {
  // Fullscreen toggle with F11 or Ctrl+Shift+F
  if (e.key === 'F11' || (e.ctrlKey && e.shiftKey && e.key === 'F')) {
    e.preventDefault();
    toggleFullscreen();
  }
  
  // Escape key to exit fullscreen
  if (e.key === 'Escape' && isFullscreen.value) {
    toggleFullscreen();
  }
};

// Set up event listeners
let notificationInterval;

onMounted(() => {
  window.addEventListener('keydown', handleKeyPress);
  
  // Listen for fullscreen change events
  document.addEventListener('fullscreenchange', handleFullscreenChange);
  document.addEventListener('webkitfullscreenchange', handleFullscreenChange);
  document.addEventListener('mozfullscreenchange', handleFullscreenChange);
  document.addEventListener('MSFullscreenChange', handleFullscreenChange);
  
  // Set up a simulation of real-time notifications
  notificationInterval = setInterval(() => {
    // 20% chance of new notification every 30-60 seconds
    if (Math.random() < 0.2) {
      const types = ['info', 'warning', 'critical'];
      const type = types[Math.floor(Math.random() * types.length)];
      const robotIds = activeZone.value.robots.map(robot => robot.id);
      const robotId = robotIds[Math.floor(Math.random() * robotIds.length)];
      
      let title, message;
      
      if (type === 'critical') {
        title = `Robot ${robotId} requires attention`;
        message = 'Critical issue detected. Immediate action required.';
      } else if (type === 'warning') {
        title = `Performance issue with ${robotId}`;
        message = 'Reduced efficiency detected in current task.';
      } else {
        title = `Status update: ${robotId}`;
        message = 'Task progress update or new assignment available.';
      }
      
      notifications.value.unshift({
        type,
        title,
        message,
        time: 'Just now'
      });
    }
  }, Math.floor(Math.random() * 30000) + 30000); // Random interval between 30-60 seconds
});

onUnmounted(() => {
  window.removeEventListener('keydown', handleKeyPress);
  
  // Remove fullscreen change listeners
  document.removeEventListener('fullscreenchange', handleFullscreenChange);
  document.removeEventListener('webkitfullscreenchange', handleFullscreenChange);
  document.removeEventListener('mozfullscreenchange', handleFullscreenChange);
  document.removeEventListener('MSFullscreenChange', handleFullscreenChange);
  
  clearInterval(notificationInterval);
});

// Handle fullscreen change events
const handleFullscreenChange = () => {
  if (!process.client) return;
  
  // Check if browser is in fullscreen mode
  const isInFullscreen = !!(
    document.fullscreenElement ||
    document.webkitFullscreenElement ||
    document.mozFullScreenElement ||
    document.msFullscreenElement
  );
  
  // Target main content
  const mainContent = document.querySelector('.flex-1');
  const parentElement = document.querySelector('.p-6.md\\:p-8')?.parentElement;
  
  // Update state based on browser fullscreen state
  if (isInFullscreen !== isFullscreen.value) {
    isFullscreen.value = isInFullscreen;
    
    if (isFullscreen.value) {
      // Force scrollable content
      if (mainContent) {
        mainContent.style.overflowY = 'auto';
        mainContent.style.height = '100vh';
        mainContent.style.marginLeft = '0';
      }
      
      // Add parent class for proper positioning
      if (parentElement) {
        parentElement.classList.add('fullscreen-mode-parent');
      }
      
      document.documentElement.classList.add('fullscreen-zone');
      document.body.style.overflow = 'auto';
      setTimeout(() => window.scrollTo(0, 0), 100);
    } else {
      // Reset main content
      if (mainContent) {
        mainContent.style.overflowY = '';
        mainContent.style.height = '';
        // Margin will be restored automatically by responsive classes
      }
      
      // Remove parent class
      if (parentElement) {
        parentElement.classList.remove('fullscreen-mode-parent');
      }
      
      document.documentElement.classList.remove('fullscreen-zone');
      document.body.style.overflow = '';
      selectedRobot.value = null;
    }
  }
};
</script>

<style scoped>
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

/* Force scrolling in fullscreen mode */
:global(.fullscreen-zone),
:global(.fullscreen-zone body),
:global(.fullscreen-zone #__nuxt),
:global(.fullscreen-zone .min-h-screen),
:global(.fullscreen-zone .flex-1) {
  overflow-y: auto !important;
  overflow-x: hidden !important;
  height: 100% !important;
  max-height: 100% !important;
  overscroll-behavior: contain;
}

:global(.fullscreen-zone) .p-6.md\:p-8 {
  padding: 1rem !important;
  height: auto !important;
  min-height: 100vh !important;
  width: 100% !important;
  max-width: 100% !important;
  overflow: visible !important;
}

/* Ensure content is actually scrollable in fullscreen */
:global(.fullscreen-zone) #__nuxt,
:global(.fullscreen-zone) .min-h-screen {
  position: absolute !important;
  width: 100% !important;
}

:global(.dark .fullscreen-zone) {
  background-color: #0f172a;
}

/* Ensure grid content is visible */
:global(.fullscreen-zone) .grid {
  overflow: visible !important;
  height: auto !important;
  display: grid !important;
}

/* Fixed button position in fullscreen */
:global(.fullscreen-zone) button.fixed {
  position: fixed;
  bottom: 1rem;
  right: 1rem;
  z-index: 50;
}

/* Add this to the component containing this template */
:global(.fullscreen-mode-parent) {
  height: 100vh !important;
  overflow-y: scroll !important;
  position: absolute !important;
  top: 0 !important;
  left: 0 !important;
  right: 0 !important;
  bottom: 0 !important;
}
</style> 