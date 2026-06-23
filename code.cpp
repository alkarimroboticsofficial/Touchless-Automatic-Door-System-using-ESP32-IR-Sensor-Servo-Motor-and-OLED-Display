#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP32Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

#define IR_SENSOR_PIN 14
#define SERVO_PIN 41

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Servo doorServo;

bool doorOpen = false;

void setup()
{
    Serial.begin(115200);

    pinMode(IR_SENSOR_PIN, INPUT);

    Wire.begin(20, 21);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println("OLED Failed!");
        while (1);
    }

    display.setTextColor(SSD1306_WHITE); // Make text visible

    doorServo.attach(SERVO_PIN);
    doorServo.write(0);

    display.clearDisplay();
    display.display();

    Serial.println("Automatic Door System Started");
}

void loop()
{
    // Reading 0 (LOW) or 1 (HIGH)
    int irValue = digitalRead(IR_SENSOR_PIN);

    // Most IR sensors output LOW (0) when an object is detected
    if (irValue == LOW) 
    {
        if (!doorOpen)
        {
            doorServo.write(90); // Open door
            doorOpen = true;
            Serial.println("Object Detected -> Door OPEN");
        }
    }
    else // Sensor reads HIGH (1), meaning path is clear
    {
        if (doorOpen)
        {
            doorServo.write(0); // Close door
            doorOpen = false;
            Serial.println("Path Clear -> Door CLOSED");
        }
    }

    // OLED Display
    display.clearDisplay();
    display.setTextSize(1);

    display.setCursor(0, 0);
    display.println("AUTO DOOR SYSTEM");

    display.setCursor(0, 20);
    display.print("Sensor: ");
    if (irValue == LOW) {
        display.println("DETECTED");
    } else {
        display.println("CLEAR");
    }

    display.setCursor(0, 40);
    display.print("Door: ");
    if (doorOpen)
        display.println("OPEN");
    else
        display.println("CLOSED");

    display.display();

    delay(100);
}
