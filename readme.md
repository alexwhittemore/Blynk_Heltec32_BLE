# Blynk Heltec32 BLE

This is a simple demo of Blynk running on a [Heltec WifiKit 32](https://heltec.org/project/wifi-kit-32/).

It uses Adafruit 1Wire libraries https://github.com/adafruit/MAX31850_OneWire and https://github.com/adafruit/MAX31850_DallasTemp to read the temperature from a MAX31850 1-Wire K type thermocouple digitizer ([docs](https://learn.adafruit.com/adafruit-1-wire-thermocouple-amplifier-max31850k/wiring-and-test)).

## Blynk setup

This is based on the Blynk BLE example code [here](https://github.com/blynkkk/blynk-library/blob/master/examples/Boards_Bluetooth/ESP32_BLE/ESP32_BLE.ino).

The main trick to connect is that you must add a "BLE" widget to the canvas, and connect using that widget BEFORE running the Blynk app [reference](https://community.blynk.cc/t/esp32-with-ble-the-android-app-doesnt-find-the-esp32-device/35819).