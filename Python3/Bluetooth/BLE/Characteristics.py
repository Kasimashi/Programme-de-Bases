import asyncio
from bleak import BleakScanner, BleakClient


async def write_to_characteristic(client,characteristic_uuid,data_to_write = b"Hello, BLE!"):
    # Write data to the characteristic
    await client.write_gatt_char(characteristic_uuid, data_to_write)
    print("Data written to characteristic")

async def read_characteristic(client, characteristic_uuid):
    try:
        # Read the value of the characteristic
        value = await client.read_gatt_char(characteristic_uuid)
        # Print the raw byte value of the characteristic
        print(f"Characteristic {characteristic_uuid}: {value}")
        # If you want to print it as a string (assuming the characteristic holds string data)
        print(f"Characteristic {characteristic_uuid} (as string): {value.decode()}")
    except Exception as e:
        print(f"Failed to read characteristic {characteristic_uuid}: {e}")

async def discover_services(address):
    # Connect to the BLE device
    async with BleakClient(address) as client:
        print(f"Connected to {address}")
        # Get all services of the device
        services = await client.get_services()
        # List services and their characteristics
        for service in services:
            print(f"Service: {service.uuid}")
            for characteristic in service.characteristics:
                #print(f"  Characteristic: {characteristic.uuid}")
                print(f"  Characteristic: {characteristic.uuid}, Properties: {characteristic.properties}")
                await read_characteristic(client, characteristic.uuid)

async def main():
    # Discover nearby devices
    devices = await BleakScanner.discover()
    print("Found Devices:")
    for device in devices:
        print(f"{device.name} ({device.address})")
    # Let's assume we want to connect to the first device found
    if devices:
        await discover_services(devices[0].address)

# Run the main function
loop = asyncio.get_event_loop()
loop.run_until_complete(main())