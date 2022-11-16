#include <PCA9685.h>

// Basic demo for accelerometer readings from Adafruit MPU6050

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;
PCA9685 pwmController;



void setup(void) {
  Serial.begin(9600);

  //wait until serial is active cycle 
  while (!Serial) {
    delay(10); // will pause Zero, Leonardo, etc until serial console opens
  }

  pwmController.resetDevices();
  
  pwmController.init();

  pwmController.setPWMFrequency(100);

  //Setting the pwm on pin zero to the value of 128 shifted left 4 digits binarily. 
  pwmController.setChannelPWM(0, 128 << 4);



  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.println("");
  delay(100);
}

void loop() {

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /* Print out the values */
  // Prints out the acceleration within the x axis
  Serial.print("AccelX:");
  Serial.print(a.acceleration.x);

	//Prints a comma separator
  Serial.print(",");

	//Prints the acceleration within the y axis
  Serial.print("AccelY:");
  Serial.print(a.acceleration.y);

	//Prints a comma separator
  Serial.print(",");

	//Prints the aceleration within the z axis
  Serial.print("AccelZ:");
  Serial.print(a.acceleration.z);

  	//Prints a comma separator
  Serial.print(", ");

  	//Gyroscope reading on 
  Serial.print("GyroX:");
  Serial.print(g.gyro.x);
  Serial.print(",");
  Serial.print("GyroY:");
  Serial.print(g.gyro.y);
  Serial.print(",");
  Serial.print("GyroZ:");
  Serial.print(g.gyro.z);
  Serial.println("");

  delay(10);
}
