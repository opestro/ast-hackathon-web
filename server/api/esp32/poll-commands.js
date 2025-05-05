export default defineEventHandler(async (event) => {
  try {
    // Get the commands storage
    const storage = useStorage('commands');
    
    // Get command queue
    const commandQueue = await storage.getItem('queue') || [];
    
    // Find the oldest non-executed command
    const pendingCommand = commandQueue.find(cmd => !cmd.executed);
    
    if (pendingCommand) {
      // Mark the command as executed
      pendingCommand.executed = true;
      
      // Update the command in the queue
      const updatedQueue = commandQueue.map(cmd => 
        cmd.id === pendingCommand.id ? pendingCommand : cmd
      );
      
      // Save the updated queue
      await storage.setItem('queue', updatedQueue);
      
      // Log that a command was retrieved
      console.log(`ESP32 retrieved command: ${pendingCommand.command} (ID: ${pendingCommand.id})`);
      
      // Return the command
      return {
        command: pendingCommand.command,
        id: pendingCommand.id,
        timestamp: pendingCommand.timestamp
      };
    }
    
    // No pending commands
    return {
      message: "No pending commands"
    };
  } catch (error) {
    console.error('Error retrieving commands:', error);
    
    return createError({
      statusCode: 500,
      statusMessage: 'Internal Server Error',
      message: 'Failed to retrieve commands: ' + (error.message || 'Unknown error')
    });
  }
}); 