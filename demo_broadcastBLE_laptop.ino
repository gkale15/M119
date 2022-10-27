// using skeleton code taken from 
// https://github.com/ucla-hci/m119/blob/main/m2b_peripheral/m2b_peripheral.ino

#include <ArduinoBLE.h>
#include <Arduino_LSM6DS3.h>

#define BLE_UUID_ACCELEROMETER_SERVICE "1101"
#define BLE_UUID_ACCELEROMETER_X "2101"
#define BLE_UUID_ACCELEROMETER_Y "2102"
#define BLE_UUID_ACCELEROMETER_Z "2103"

#define BLE_DEVICE_NAME "GKNano"

BLEService accelerometerService(BLE_UUID_ACCELEROMETER_SERVICE);

BLEFloatCharacteristic accelerometerCharacteristicX(BLE_UUID_ACCELEROMETER_X, BLERead | BLENotify);
BLEFloatCharacteristic accelerometerCharacteristicY(BLE_UUID_ACCELEROMETER_Y, BLERead | BLENotify);
BLEFloatCharacteristic accelerometerCharacteristicZ(BLE_UUID_ACCELEROMETER_Z, BLERead | BLENotify);

float x, y, z;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  // initialize IMU
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1)
      ;
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println("Hz");

  // initialize BLE
  if (!BLE.begin()) {
    Serial.println("Starting Bluetooth® Low Energy module failed!");
    while (1)
      ;
  }

  // set advertised local name and service UUID
  //
  // <add your code here>
  //

  BLE.setDeviceName(BLE_DEVICE_NAME);
  BLE.setLocalName(BLE_DEVICE_NAME);
  BLE.setAdvertisedService(accelerometerService);


  accelerometerService.addCharacteristic(accelerometerCharacteristicX);
  accelerometerService.addCharacteristic(accelerometerCharacteristicY);
  accelerometerService.addCharacteristic(accelerometerCharacteristicZ);

  
  // add characteristics and service
  //
  // <add your code here>
  //

  BLE.addService(accelerometerService);

  accelerometerCharacteristicX.writeValue(0);
  accelerometerCharacteristicY.writeValue(0);
  accelerometerCharacteristicZ.writeValue(0);

  // start advertising
  //
  // <add your code here>
  //

  BLE.advertise();

  Serial.println("BLE Accelerometer Peripheral");
}

void loop() {
  BLEDevice central = BLE.central();

  // obtain and write accelerometer data
  // 
  // <add your code here>
  // 
}
