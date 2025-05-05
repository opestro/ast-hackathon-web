export default defineEventHandler(async (event) => {
  // Get data from storage
  const storage = useStorage('rfid')
  const rfidData = await storage.getItem('data') || []
  
  // Return data
  return rfidData
}) 