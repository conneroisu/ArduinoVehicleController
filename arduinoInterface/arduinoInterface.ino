
// Basic include from Adafruit MPU6050
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

//Basic Include of the PCA 9685 Servo Controller aka PWM Controller
#include <PCA9685.h>

// Create a new MPU interface
Adafruit_MPU6050 mpu;
// Create a new PCA9685 Controller
PCA9685 pwmController;

void setup(void) {
	Serial.begin(9600);

	//wait until serial is active cycle 
	while (!Serial) {
	delay(10); // will pause Zero, Leonardo, etc until serial console opens
	}

	//Rest the PWM Controller
	pwmController.resetDevices();

	//Initilizes the PWM Controller
	pwmController.init();

	//Sets the PWM Contoller Frequency
	pwmController.setPWMFrequency(100);

	//Setting the pwm on pin zero to the value of 128 shifted left 4 digits binarily. 
	pwmController.setChannelPWM(0, 128 << 4);



	// Try to initialize!
	if (!mpu.begin()) {
		Serial.println("Failed to find MPU6050 chip");
		while (1) {
			//delay 10 ms
			delay(10);
	}}
	// Sets teh accelerometer range for the mpu 6050 sensor
	mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
	// sets the gyroscope range for the mpu 6050 sensor 
	mpu.setGyroRange(MPU6050_RANGE_250_DEG);
	// sets the filter bandwidth for the mpu 6050 sensor
	mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
	Serial.println("");
	//Delay 100 ms
	delay(100);
}//void setup 

void loop() {

	/* Get new sensor events with the readings */
	sensors_event_t a, g, temp;
	mpu.getEvent(&a, &g, &temp);

	/* Print out the values */
	// Prints out the acceleration along the x axis
	Serial.print("AccelX:");
	Serial.print(a.acceleration.x);

	//Prints a comma separator
	Serial.print(",");

	//Prints the acceleration along the y axis
	Serial.print("AccelY:");
	Serial.print(a.acceleration.y);

	//Prints a comma separator
	Serial.print(",");

	//Prints the aceleration along the z axis.
	Serial.print("AccelZ:");
	Serial.print(a.acceleration.z);

	//Prints a comma separator
	Serial.print(", ");

	//Gyroscope reading along the x axis
	Serial.print("GyroX:");
	Serial.print(g.gyro.x);
	Serial.print(",");

	//Gyroscope reading along the y axis
	Serial.print("GyroY:");
	Serial.print(g.gyro.y);
	Serial.print(",");

	//Gyroscope reading along the z axis
	Serial.print("GyroZ:");
	Serial.print(g.gyro.z);
	Serial.println("");

	//delay 10 ms
	delay(10);
}
