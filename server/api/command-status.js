export default defineEventHandler(async (event) => {
  try {
    // Get command ID from query parameter (optional)
    const query = getQuery(event);
    const commandId = query.id;
    
    // Get the commands storage
    const storage = useStorage('commands');
    
    // Get command queue
    const commandQueue = await storage.getItem('queue') || [];
    
    // If command ID is provided, return status for that command
    if (commandId) {
      const command = commandQueue.find(cmd => cmd.id === commandId);
      
      if (!command) {
        return {
          success: false,
          message: `Command with ID ${commandId} not found`,
          statusCode: 404
        };
      }
      
      return {
        success: true,
        data: {
          command: command.command,
          id: command.id,
          timestamp: command.timestamp,
          status: command.completed ? 'completed' : command.executed ? 'executing' : 'pending',
          completedAt: command.completedAt
        }
      };
    }
    
    // If no command ID is provided, return status for all recent commands
    const recentCommands = commandQueue.slice(0, 10).map(cmd => ({
      command: cmd.command,
      id: cmd.id,
      timestamp: cmd.timestamp,
      status: cmd.completed ? 'completed' : cmd.executed ? 'executing' : 'pending',
      completedAt: cmd.completedAt
    }));
    
    return {
      success: true,
      data: recentCommands
    };
  } catch (error) {
    console.error('Error retrieving command status:', error);
    
    return {
      success: false,
      message: 'Failed to retrieve command status: ' + (error.message || 'Unknown error'),
      statusCode: 500
    };
  }
}); 