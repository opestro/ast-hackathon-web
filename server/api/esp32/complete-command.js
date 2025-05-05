export default defineEventHandler(async (event) => {
  // Only allow POST method
  if (event.method !== 'POST') {
    return createError({
      statusCode: 405,
      statusMessage: 'Method Not Allowed',
      message: 'Only POST method is allowed'
    });
  }
  
  try {
    // Get the request body
    const body = await readBody(event);
    
    // Validate the command ID
    if (!body || !body.id) {
      return {
        success: false,
        message: 'Missing command ID',
        statusCode: 400
      };
    }
    
    // Get the command ID
    const commandId = body.id;
    
    // Get the commands storage
    const storage = useStorage('commands');
    
    // Get command queue
    const commandQueue = await storage.getItem('queue') || [];
    
    // Find the command by ID
    const commandIndex = commandQueue.findIndex(cmd => cmd.id === commandId);
    
    if (commandIndex === -1) {
      return {
        success: false,
        message: `Command with ID ${commandId} not found`,
        statusCode: 404
      };
    }
    
    // Mark the command as completed
    commandQueue[commandIndex].completed = true;
    commandQueue[commandIndex].completedAt = Date.now();
    
    // Save the updated queue
    await storage.setItem('queue', commandQueue);
    
    // Log the completion
    console.log(`ESP32 marked command as completed: ${commandQueue[commandIndex].command} (ID: ${commandId})`);
    
    // Return success
    return {
      success: true,
      message: 'Command marked as completed'
    };
  } catch (error) {
    console.error('Error completing command:', error);
    
    return {
      success: false,
      message: 'Failed to complete command: ' + (error.message || 'Unknown error'),
      statusCode: 500
    };
  }
}); 