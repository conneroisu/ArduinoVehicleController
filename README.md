
# Context [![.github/workflows/compileSketch.yml](https://github.com/conneroisu/ArduinoVehicleController/actions/workflows/compileSketch.yml/badge.svg?event=push)](https://github.com/conneroisu/ArduinoVehicleController/actions/workflows/compileSketch.yml)
This is the arduino source code for an open source mini scale autonomous bus which is part of a larger initiative to autonomize the city of Ames. While the whole of the project surrounds the idea of autonomizing vehicles, this code acts as a control interface for the raspberry pi allowing for more computation regarding "decision making" to be done  on the raspberry pi. This repository acts as the interface between the $I^{2}C$ and the serial interface present on an arduino for the controll of steering and throttle using pwm while doing some computations needed to transform the sensor readings into an heading value which is sent on the serial connection.


The Main Project is set up to take a series of inputs from sensors and other electronic components, using this arduino serial interface to control the steering servo and throttle using pwm . The actions performed by the system will be based on the mission of autonomizing the city of Ames. Want to support the development of this project and/or initiative? Go to the project page. 

## This repo is part of a larger initiative and project found [here](https://github.com/conneroisu/OhneDriver-RPI).  

> While this repo is part of a larger project it is also intended for a general open source implementation of an serial interface intended to be interacted with through a raspberry pi usb to serial, but will work with any device which can transmitt a serial signal to an arduino; though, this might require some tweaking of values within this implementation. If you want to learn more about customization, you can learn that here.


The main idea behind the name of the entire system, "OhneDriver" comes from the german word for without. Conclusively, this name would point out the lack of driver within the context of the name of the autonomous driving system. Within context of that system, this repository holds the source code for an serial interface to an gyroscope, accelerometer, and a servo controller. The intended 3 pin servo controller ports are aligned within the code for the steering servo to be port 0 and for the throttle to be port 1.


Hardware Parts: 
| Hardware       | Description                                                                              |
| -------------- | ---------------------------------------------------------------------------------------- |
| Arduino Uno R3 | The most documented board of the arduino family                                          |
| PCA9685        | This is the servo controller board which allows for the control of throttle and steering |
| MPU6050        | This is the accelerometer and gyroscope implemented to obtain the vehicle heading        | 

# Introduction 
This repository is the pure c code repository for an I2C to Arduino to Serial Interface which allows the reallocation of computational resources within the mini autonomous bus by allowing the access of two I2C devices through the serial connection of an arduino. 

The I2C interface uses a controller to communicate with other devices, refered to as: master and slave devices. To categorize theses two devices, a controller can transmit and receive data while a slave can only transmit data when addressed by the master device.

I think that. my dream employer, Texas Instruments said it best when they described the $I^{2}C$ bus as a concept found [here](https://www.ti.com/lit/an/slva704/slva704.pdf?ts=1668582199846&ref_url=https%253A%252F%252Fwww.google.com%252F) .

> "The $I^{2}C$ bus is a very popular and powerful bus used for communication between a master (or multiple masters) and a single or multiple slave devices... many different peripherals may share a bus which is connected to a processor through only 2 wires, which is one of the largest benefits that the $I^{2}C$ bus can give when compared to other interfaces."

## Hardware
- Wiring diagram goes here
![image](https://user-images.githubusercontent.com/88785126/203611756-17ed7575-89bb-40d6-8eaf-db1b79a4eb3f.png)


Both interfaces that are intended for use with this code use an $I^{2}C$ communication protocol. A Inter-Integrated circuit protocol otherwise known as $I^{2}C$, an multi-peripheral sensors or circuits to communicate with one or more controller boards, requires two wites to exchange data. Because $I^{2}C$ requires only two wires, this simplifies the physical wiring and designing of the wiring itself. 

### MPU 6050
A popular tri-axis accelerometer and gyroscope allowing the full tracking of the sensors position and acceleration. More specifically,  while the gyroscope measures rotational velocity through the use of MEMS and Coriolis Effect, the accelerometer measures the acceleration along the 3 axes.

![](https://i.imgur.com/qhqgar8.png)

While there are 8 essential nodes present to the interface, this implementation only uses 4: VCC, Ground, **Serial Clock Line(SCL)**, and **Serial Data Line(SDA)**. 
### PCA 9685

The PCA 9685 is a servo controller board that allows for the controlling of 16 separate pwm outputs per board(You can chain a sequence of these boards with configured addresses to address more than 16 outputs). The board takes only two pins of input disregarding the voltage and ground wires. Specifically, the two wires are **Serial Clock Line(SCL)**, and **Serial Data Line(SDA)**. 

![](https://i.imgur.com/vo94msV.png)



### I2C

#### a note on speed of i2c to serial interfacing 
While this repository implements a serial interface on top of the I2C interface through the implementation of two I2C libraries, the 

#### SCL - Serial Clock Line 
This line carries the clock signal for the serial communication protocol within I2C which allows for accurate transmission of signals over the data lines.

#### SDA - Serial Data Line (I want to know what the A stands for too)
This is the data line which carries the I2C serial communication protocol and physically allows for the transmission of data. 

### Pulling Up Resistors 
Because there is sparse information about the pull up resistors required for a specific setup of I2C devices, this section will attempt to explain the idea and implementation of a pull up resistor based on your multiple slave devices and their speeds. 

## Software 
Because each electrically capable hardware part must be physically addressed by the software in some way including indirectly, this section will mirror the hardware section, but will dive into the software side of this arduino code. 

## Software libraries 

[Accelerometer and Gyro Library](https://github.com/adafruit/Adafruit_MPU6050)

[Servo Controller Library](https://github.com/NachtRaveVL/PCA9685-Arduino)
# Conclusion 
This repository has been a great learning experience for me to gain new and exciting github tools to aid in the producing of workflows, actions, and github repositories. 

## Conceptual ideas within this repository 


![[Arduino interface ohnedrive readme 2022-11-16 09.10.41.excalidraw| 999]]
