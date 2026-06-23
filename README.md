# 🚪 Touchless Automatic Door System using ESP32, IR Sensor, Servo Motor, and OLED Display

## Project Overview

The **Touchless Automatic Door System** is an ESP32-based automation project that uses an **IR Obstacle Detection Sensor** to detect the presence of a person or object and automatically open or close a door using a **Servo Motor**. An **OLED Display** provides real-time information about the sensor status and door state.

This project demonstrates sensor interfacing, motor control, and OLED display integration using the ESP32 platform, making it an excellent beginner-to-intermediate IoT and embedded systems project.

---

## Circuit Diagram

### OLED Display (SSD1306 I2C)

| OLED Pin | ESP32 Pin |
| -------- | --------- |
| VCC      | 3.3V      |
| GND      | GND       |
| SDA      | GPIO 20   |
| SCL      | GPIO 21   |

### IR Obstacle Sensor

| IR Sensor Pin | ESP32 Pin |
| ------------- | --------- |
| VCC           | 3.3V      |
| GND           | GND       |
| OUT           | GPIO 14   |

### Servo Motor

| Servo Pin | ESP32 Pin |
| --------- | --------- |
| Signal    | GPIO 41   |
| VCC       | 5V        |
| GND       | GND       |

> **Note:** For reliable operation, power the servo motor from an external 5V supply and connect all grounds together.

---

## Components Used

* ESP32-S3 Development Board
* IR Obstacle Detection Sensor
* SG90 Servo Motor
* 0.96" OLED Display (SSD1306, I2C)
* Jumper Wires
* Breadboard
* 5V Power Supply

---

## Working Principle

1. The IR sensor continuously monitors the area in front of the door.
2. When an object or person is detected, the sensor output becomes LOW.
3. The ESP32 reads the sensor signal and commands the servo motor to rotate to 90°, opening the door.
4. The OLED displays:

   * Sensor Status: DETECTED
   * Door Status: OPEN
5. When the object moves away, the sensor output becomes HIGH.
6. The ESP32 rotates the servo back to 0°, closing the door.
7. The OLED updates the display to show:

   * Sensor Status: CLEAR
   * Door Status: CLOSED

---

## Features

* Touchless door operation
* Real-time object detection
* Automatic door opening and closing
* OLED status display
* Low-cost automation solution
* Suitable for smart homes and public facilities
* Easy to build and customize

---

## OLED Display Output

### When Object is Detected

```text
AUTO DOOR SYSTEM

Sensor: DETECTED

Door: OPEN
```

### When No Object is Present

```text
AUTO DOOR SYSTEM

Sensor: CLEAR

Door: CLOSED
```

---

## Code Logic

### Setup

* Initialize Serial Monitor.
* Configure IR sensor pin as input.
* Initialize I2C communication.
* Initialize OLED display.
* Attach servo motor.
* Set door position to closed.

### Loop

* Read IR sensor state.
* If sensor output is LOW:

  * Open door using servo motor.
  * Update OLED display.
* If sensor output is HIGH:

  * Close door using servo motor.
  * Update OLED display.
* Continuously refresh display and monitor sensor state.

---

## Algorithm

```text
Start
│
├── Initialize ESP32
├── Initialize OLED Display
├── Initialize Servo Motor
├── Initialize IR Sensor
│
└── Loop
     │
     ├── Read IR Sensor
     │
     ├── Object Detected?
     │      │
     │      ├── YES
     │      │     ├── Open Door
     │      │     ├── Display DETECTED
     │      │     └── Display OPEN
     │      │
     │      └── NO
     │            ├── Close Door
     │            ├── Display CLEAR
     │            └── Display CLOSED
     │
     └── Repeat
```

---

## Installation Steps

1. Connect all components according to the wiring table.
2. Install the required libraries in Arduino IDE.
3. Select the correct ESP32 board.
4. Upload the code to the ESP32.
5. Open the Serial Monitor at 115200 baud.
6. Test the system by placing an object in front of the IR sensor.

---

## Required Libraries

Install the following libraries using Arduino IDE Library Manager:

```cpp
Adafruit GFX Library
Adafruit SSD1306
ESP32Servo
Wire
```

---

## Applications

* Smart Home Automation
* Touchless Entry Systems
* Hospitals and Clinics
* Offices and Commercial Buildings
* Laboratories
* Educational Embedded Systems Projects
* IoT Automation Demonstrations

---

## Future Improvements

* Add Ultrasonic Sensor for distance measurement
* Integrate RFID-based access control
* Add Wi-Fi monitoring using ESP32
* Implement Face Recognition access
* Add Buzzer and LED indicators
* Create a web dashboard for monitoring
* Add automatic closing delay timer

---

## Author

**Muhammad Zulqarnain Khandapa**

Robotics Engineering Student
IoT Developer | Embedded Systems Enthusiast | ESP32 & Arduino Projects

---

## License

This project is open-source and available under the MIT License.
