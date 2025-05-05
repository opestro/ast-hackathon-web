export default defineEventHandler(async (event) => {
  // Get the request body
  const body = await readBody(event)
  
  // Validate the request
  if (!body || !body.rfid || !body.type) {
    return {
      error: true,
      message: 'Invalid request data',
      statusCode: 400
    }
  }
  
  // Add a timestamp if not provided
  if (!body.timestamp) {
    body.timestamp = Date.now()
  }
  
  // Store in memory or in a database
  // For simplicity, we'll use server-side runtime state
  const storage = useStorage('rfid')
  
  // Get existing data or initialize an empty array
  let rfidData = await storage.getItem('data') || []
  
  // Add new data at the beginning
  rfidData = [body, ...rfidData].slice(0, 20) // Keep only last 20 entries
  
  // Store updated data
  await storage.setItem('data', rfidData)
  
  // Return success response
  return {
    success: true,
    message: 'RFID data received and stored',
    data: body
  }
}) 