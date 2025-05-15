/*
  This experiment was done using a development board from NIELIT Calicut. It incorporates ESP32-Wroom and several peripherals like RGB, Touch sensor, Buzzer, LDR
  DHT11 and switch.

  Here we control the built-in LED of the ESP32 and also the RGB of the development board.
*/

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)  //this is to make sure that bluetooth is enabled
#error Bluetooth is not enabled! Please run `make menuconfig` and enable it  //if it is not properly enabled it will show this error
#endif

//configure the pin numbers using the datasheet of the board you are using
#define LED_BUILTIN 2 //check your data sheet for the corresponding builtin led pin number
#define LED_RED 26  
#define LED_GREEN 25
#define LED_BLUE 4

BluetoothSerial SerialBT;
char inputChar;

void setup() {
pinMode(LED_BUILTIN, OUTPUT);
pinMode(1, OUTPUT);
pinMode(LED_RED, OUTPUT);
pinMode(2, OUTPUT);
pinMode(LED_GREEN, OUTPUT);
pinMode(3, OUTPUT);
pinMode(LED_BLUE, OUTPUT);
pinMode(4, OUTPUT);
Serial.begin(115200);
SerialBT.begin("Fri_mal"); //Bluetooth device name
Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
if (SerialBT.available()) {
/*
  Y -> turns ON the built-in led
  N -> turns OFF the built-in led
  R -> turns ON only the Red of RGB
  G -> turns ON only the Green of RGB
  B -> turns ON only the Blue of RGB
  if other colours are required using RGB then combinations of the Red, Green and Blue leds should be turned ON
  */
inputChar = SerialBT.read();
}
if (inputChar=='Y')
{
digitalWrite(LED_BUILTIN, HIGH);
delay(100);
SerialBT.write('H');
}
if (inputChar=='N')
{
digitalWrite(LED_BUILTIN, LOW);
}
if (inputChar=='R')
{
digitalWrite(LED_RED, HIGH);
digitalWrite(LED_GREEN, LOW);  
digitalWrite(LED_BLUE, LOW);
}
if (inputChar=='G')
{
digitalWrite(LED_RED, LOW);
digitalWrite(LED_GREEN, HIGH);
digitalWrite(LED_BLUE, LOW);
}
if (inputChar=='B')
{
digitalWrite(LED_RED, LOW);
digitalWrite(LED_GREEN, LOW);
digitalWrite(LED_BLUE, HIGH);
}

}
