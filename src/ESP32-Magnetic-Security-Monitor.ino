/*************************************************
 * ESP32 Magnetic Security Monitor
 * Hall Effect Sensor + OLED + LEDs + PWM Buzzer
 *************************************************/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// =====================================
// OLED CONFIGURATION
// =====================================

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  -1
);

// =====================================
// PIN DEFINITIONS
// =====================================

#define HALL_SENSOR 27

#define GREEN_LED 15
#define RED_LED 2

#define BUZZER 14

// =====================================
// VARIABLES
// =====================================

unsigned long doorOpenCounter = 0;

bool previousDoorState = false;

// =====================================
// SETUP
// =====================================

void setup()
{
  Serial.begin(115200);

  pinMode(HALL_SENSOR, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  Wire.begin(21,22);

  if(!display.begin(
      SSD1306_SWITCHCAPVCC,
      0x3C))
  {
    while(true);
  }

  // Attach PWM tone generation
  ledcAttach(BUZZER, 4000, 8);

  display.clearDisplay();

  display.setTextColor(
      SSD1306_WHITE);

  display.setTextSize(2);

  display.setCursor(10,20);

  display.println("SECURITY");

  display.display();

  delay(2000);
}

// =====================================
// LOOP
// =====================================

void loop()
{
  int hallState =
      digitalRead(HALL_SENSOR);

  display.clearDisplay();

  display.setTextSize(1);

  display.setCursor(0,0);

  display.println(
      "MAGNETIC SECURITY");

  // ---------------------------------
  // DOOR CLOSED
  // ---------------------------------

  if(hallState == LOW)
  {
    digitalWrite(
      GREEN_LED,
      HIGH);

    digitalWrite(
      RED_LED,
      LOW);

    // Buzzer OFF
    ledcWriteTone(
      BUZZER,
      0);

    previousDoorState = false;

    display.setTextSize(2);

    display.setCursor(0,20);

    display.println("CLOSED");

    display.setTextSize(1);

    display.setCursor(0,50);

    display.print("Count: ");

    display.print(
      doorOpenCounter);

    Serial.println(
      "DOOR CLOSED");
  }

  // ---------------------------------
  // DOOR OPEN
  // ---------------------------------

  else
  {
    digitalWrite(
      GREEN_LED,
      LOW);

    digitalWrite(
      RED_LED,
      HIGH);

    // High-pitched buzzer
    ledcWriteTone(
      BUZZER,
      1000);

    if(previousDoorState == false)
    {
      doorOpenCounter++;

      previousDoorState = true;
    }

    display.setTextSize(2);

    display.setCursor(0,20);

    display.println("OPEN");

    display.setTextSize(1);

    display.setCursor(0,50);

    display.print("Count: ");

    display.print(
      doorOpenCounter);

    Serial.println(
      "DOOR OPEN");
  }

  display.display();

  delay(100);
}