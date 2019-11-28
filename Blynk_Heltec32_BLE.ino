/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Social networks:            http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example shows how to use ESP32 BLE
  to connect your project to Blynk.

  Warning: Bluetooth support is in beta!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#define BLYNK_USE_DIRECT_CONNECT

#include <BlynkSimpleEsp32_BLE.h>
#include <BLEDevice.h>
#include <BLEServer.h>

#include <OneWire.h>
#include <DallasTemperature.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "p2kZ8gE_EbFRcvTgUpfQ-el5T7Zpw70F";

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 4

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
 
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
DeviceAddress addr;

BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
//  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
//  Serial.println("DONE");
  // You can send any value at any time.
  // Please don't send more that 10 values per second.

//  for (uint8_t s=0; s < sensors.getDeviceCount(); s++) {
//    // get the unique address 
//    sensors.getAddress(addr, s);
//    // just look at bottom two bytes, which is pretty likely to be unique
//    int smalladdr = (addr[6] << 8) | addr[7];
//    
//    Serial.print("Temperature for the device #"); Serial.print(s); 
//    Serial.print(" with ID #"); Serial.print(smalladdr);
//    Serial.print(" is: ");
//    Serial.println(sensors.getTempCByIndex(s));  
//  }
  
  Blynk.virtualWrite(V5, sensors.getTempCByIndex(0));
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  Serial.println("Waiting for connections...");

  Blynk.setDeviceName("Blynk");

  Blynk.begin(auth);
  // Setup a function to be called every half second
  timer.setInterval(500L, myTimerEvent);

  // Start up the library
  sensors.begin();
}

void loop()
{
  Blynk.run();
  timer.run();
}
