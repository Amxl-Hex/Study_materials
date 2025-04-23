from machine import Pin
import time
import dht

# Configure the DHT11 sensor pin (e.g., GPIO15)
dht11_pin = Pin(15, Pin.IN)  # Or whatever pin you are using

# Create a DHT11 object
sensor = dht.DHT11(dht11_pin)

while True:
    try:
        # Measure the temperature and humidity
        sensor.measure()

        # Get the temperature and humidity values
        temperature = sensor.temperature()
        humidity = sensor.humidity()

        # Print the values
        print(f"Temperature: {temperature:.1f}°C")
        print(f"Humidity: {humidity:.1f}%")

    except OSError as e:
        print("Failed to read sensor. ", e)

    time.sleep(2) # Wait for 2 seconds before the next reading