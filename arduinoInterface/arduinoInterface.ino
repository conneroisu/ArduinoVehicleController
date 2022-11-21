
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
	// Sets the accelerometer range for the mpu 6050 sensor
	mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
	// sets the gyroscope range for the mpu 6050 sensor 
	mpu.setGyroRange(MPU6050_RANGE_250_DEG);
	// sets the filter bandwidth for the mpu 6050 sensor
	mpu.setFilterBandwidth(MPU6050_BAND_21_HZ); Serial.println("");
	//Delay 100 ms
	delay(100);
}//void setup 

void loop() {
	// if there is a string message in the serial buffer
	

	/* Get new sensor events with the readings */
	sensors_event_t a, g, temp;
	mpu.getEvent(&a, &g, &temp);

	//Create heading values from the gyroscope readings
	float heading = atan2(g.gyro.y, g.gyro.x);
	//Convert the heading to degrees
	heading = heading * 180 / M_PI;
	//Create geading values from the accelerometer readings
	float heading2 = atan2(a.acceleration.y, a.acceleration.x);
	//Convert the heading to degrees
	heading2 = heading2 * 180 / M_PI;

	//Print the heading values to the serial monitor
	Serial.print("Heading: ");
	Serial.print(heading);
	Serial.print(" Heading2: ");
	Serial.println(heading2);


}
