/*
  This experiment was done using a development board from NIELIT Calicut. It incorporates ESP32-Wroom and several peripherals like RGB, Touch sensor, Buzzer, LDR
  DHT11 and switch. 

  Here we use ESP32 in station mode. First we connect the ESP32 to the WiFi which is hotspot from the device we are to be controlling the LED from.
  In the IP address we have set up two buttons 'Turn LED ON' and 'Turn LED OFF'. Actions on these buttons are read and then the corresponding block of code is realised. 
  ESP32 should be successfully connected to the WiFi hotspot of the device we are to control from and then the device should be connected to the IP address the ESP32 
  displays on the serial monitor.
*/


#include <WiFi.h>
#include <WebServer.h>

// Replace with your Wi-Fi credentials
const char* ssid = "ESP32_Test";
const char* password = "567894321";

const int ledPin = 2; // GPIO 2 for LED
WebServer server(80); // Web server on port 80

void handleRoot() {
  String html = "<h1>ESP32 STA Mode - LED Control</h1>";
  html += "<p><a href=\"/led/on\"><button>Turn LED ON</button></a></p>";
  html += "<p><a href=\"/led/off\"><button>Turn LED OFF</button></a></p>";
  server.send(200, "text/html", html);
}

void handleLedOn() {
  digitalWrite(ledPin, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleLedOff() {
  digitalWrite(ledPin, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // LED off initially

  Serial.println("Connecting to WiFi...");
  WiFi.mode(WIFI_STA); //setting up ESP32 in station mode
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Attempting to connect...");
  }

  Serial.println("Connected to WiFi!");
  Serial.print("IP Address: "); //prints the IP address of the webserver
  Serial.println(WiFi.localIP());

  // Setup web server routes
  server.on("/", handleRoot);
  server.on("/led/on", handleLedOn);
  server.on("/led/off", handleLedOff);
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  server.handleClient(); // Handle incoming client requests
}