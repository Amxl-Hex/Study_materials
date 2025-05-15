/*
  This experiment was done using a development board from NIELIT Calicut. It incorporates ESP32-Wroom and several peripherals like RGB, Touch sensor, Buzzer, LDR
  DHT11 and switch. 

  Here we use ESP32 as access point. First we set up a WiFi for the ESP32 and then using html commands we configure IP address.
  In the IP address we have set up two buttons 'Turn LED ON' and 'Turn LED OFF'. Actions on these buttons are read and then the corresponding block of code is realised. 
  The device from which we are to control should be connected to the WiFi of the ESP32 and then connect to the IP address the ESP32 displays on the serial monitor.
*/

#include <WiFi.h>
#include <WebServer.h>

// setting up the SSID and password for ESP32 AP
const char* ssid = "ESP32_WiFi";  
const char* password = "12345678"; 

const int ledPin = 2; // GPIO 2 for LED
WebServer server(80); // Web server on port 80

// configuring the webserver
void handleRoot() {
  String html = "<h1>ESP32 AP Mode - LED Control</h1>";
  html += "<p><a href=\"/led/on\"><button>Turn LED ON</button></a></p>";
  html += "<p><a href=\"/led/off\"><button>Turn LED OFF</button></a></p>";
  server.send(200, "text/html", html);
}

//block of code if 'Turn LED ON' button is pressed
void handleLedOn() {
  digitalWrite(ledPin, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
}

//block of code if 'Turn LED OFF' button is pressed
void handleLedOff() {
  digitalWrite(ledPin, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // LED off initially

  Serial.println("Setting up ESP32 as Access Point...");
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  Serial.print("AP Started. IP Address: ");
  Serial.println(WiFi.softAPIP()); //this prints the IP address of the webserver

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