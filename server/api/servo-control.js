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
      
      // Validate the command
      if (!body || !body.command) {
        return {
          success: false,
          message: 'Missing command parameter',
          statusCode: 400
        };
      }
      
      // Validate command type
      const validCommands = ['gripper_open', 'gripper_close', 'arm_up', 'arm_down'];
      if (!validCommands.includes(body.command)) {
        return {
          success: false,
          message: 'Invalid command',
          statusCode: 400
        };
      }
      
      // Get the command
      const command = body.command;
      
      // Store the command in the server's storage for polling
      const storage = useStorage('commands');
      
      // Add command to queue with timestamp and unique ID
      const commandObj = {
        id: Date.now().toString() + Math.random().toString(36).substr(2, 5),
        command,
        timestamp: Date.now(),
        executed: false
      };
      
      // Get existing queue or create a new one
      const commandQueue = await storage.getItem('queue') || [];
      
      // Add new command to the beginning of the queue
      commandQueue.unshift(commandObj);
      
      // Keep only the latest 20 commands
      const trimmedQueue = commandQueue.slice(0, 20);
      
      // Save updated queue
      await storage.setItem('queue', trimmedQueue);
      
      // Log the command to server console
      console.log(`Command added to queue: ${command} (ID: ${commandObj.id})`);
      
      // Return success response
      return {
        success: true,
        message: 'Command queued successfully',
        data: {
          command,
          id: commandObj.id,
          timestamp: commandObj.timestamp
        }
      };
    } catch (error) {
      console.error('Error processing command:', error);
      
      // Return error response
      return {
        success: false,
        message: 'Failed to process command: ' + (error.message || 'Unknown error'),
        statusCode: 500
      };
    }
  });