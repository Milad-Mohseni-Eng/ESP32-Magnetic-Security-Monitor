# ESP32 Magnetic Security Monitor

ESP32-based magnetic security monitoring system using an A3144 Hall Effect sensor, SSD1306 OLED display, LEDs, and buzzer for real-time door status monitoring and intrusion alert indication.

---

## Overview

This project demonstrates a simple embedded security system using magnetic field detection.

A Hall Effect sensor (A3144) continuously monitors the presence of a nearby magnet. When the magnet is removed, the system interprets the event as a door opening and immediately activates visual and audible alarms.

The project combines:

- Magnetic sensing
- OLED user interface
- Event counting
- Real-time alarm indication
- Embedded monitoring logic

---

## Features

- Real-time magnetic field detection
- Door OPEN/CLOSED monitoring
- SSD1306 OLED display
- Green LED safe indicator
- Red LED alarm indicator
- Audible buzzer alarm
- Door opening event counter
- Serial monitor diagnostics
- ESP32 compatible

---

## Hardware Components

| Component | Quantity |
|------------|------------|
| ESP32 Development Board | 1 |
| A3144 Hall Effect Sensor | 1 |
| Small Magnet | 1 |
| SSD1306 OLED Display | 1 |
| Green LED | 1 |
| Red LED | 1 |
| Passive Buzzer | 1 |
| 220Ω Resistors | 2 |
| Jumper Wires | Several |

---

## Pin Configuration

### Hall Effect Sensor

| A3144 Pin | ESP32 |
|------------|------------|
| VCC | 3.3V |
| GND | GND |
| OUT | GPIO27 |

---

### OLED Display

| OLED Pin | ESP32 |
|------------|------------|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO21 |
| SCL | GPIO22 |

---

### LEDs

| Device | GPIO |
|----------|----------|
| Green LED | GPIO15 |
| Red LED | GPIO2 |

---

### Buzzer

| Device | GPIO |
|----------|----------|
| Passive Buzzer | GPIO14 |

---

## System States

### CLOSED State

Condition:


Magnet detected


Actions:


Green LED ON
Red LED OFF
Buzzer OFF
OLED displays CLOSED


---

### OPEN State

Condition:


Magnet removed


Actions:


Green LED OFF
Red LED ON
Buzzer ON
OLED displays OPEN
Door counter incremented


---

## How It Works

### Step 1

The Hall Effect sensor continuously monitors the magnetic field.

---

### Step 2

When a magnet is close to the sensor:


Sensor Output = LOW


The system enters the CLOSED state.

---

### Step 3

When the magnet moves away:


Sensor Output = HIGH


The system enters the OPEN state.

---

### Step 4

The ESP32:

- Activates the alarm
- Updates the OLED
- Records the event count

---

### Step 5

Monitoring continues indefinitely.

---

## Event Counter

The project counts door opening events.

Example:


Door Open #1
Door Open #2
Door Open #3


OLED:


MAGNETIC SECURITY

OPEN

Count: 3


The counter increases only when a new opening event occurs.

---

## OLED Screens

### Door Closed


MAGNETIC SECURITY

CLOSED

Count: 5


---

### Door Open


MAGNETIC SECURITY

OPEN

Count: 6


---

## Buzzer Note

A passive buzzer is driven using ESP32 PWM tone generation.

Testing showed that lower frequencies produced stronger sound output on the selected buzzer.

Example:

```cpp
ledcWriteTone(BUZZER,1000);
```

was significantly louder than:

```cpp
ledcWriteTone(BUZZER,8000);
```

due to the buzzer's resonant frequency characteristics.

---

## Wiring

### Wiring Diagram

![Wiring](docs/wiring.png)

---

### Circuit Diagram

![Circuit Diagram](docs/circuit_diagram.png)

---

### OLED Active State

![OLED Active](docs/oled_active.png)

---

## Demo Video

Demo video included:


docs/demo_video.mp4


---

## Software Requirements

### Arduino IDE


Arduino IDE 2.x


---

### ESP32 Board Package

Install:


ESP32 by Espressif Systems


---

### Required Libraries

```text
Adafruit GFX Library
Adafruit SSD1306 Library
Wire Library
```

---

## Installation

Clone repository:

```bash
git clone https://github.com/your-username/ESP32-Magnetic-Security-Monitor.git
```

Open:

```text
src/ESP32_Magnetic_Security_Monitor.ino
```

Upload to ESP32.

---

## Educational Objectives

This project demonstrates:

- Hall Effect sensing
- Magnetic field detection
- Security monitoring
- OLED user interfaces
- GPIO programming
- Event counting
- Embedded alarm systems
- Real-time monitoring

---

## Real-World Applications

- Door security systems
- Window monitoring
- Cabinet intrusion detection
- Server rack monitoring
- Access control systems
- Industrial safety systems

---

## Future Improvements

Possible enhancements:

- Wi-Fi notifications
- MQTT integration
- Mobile alerts
- Cloud logging
- SD card event storage
- RTC timestamping
- Multi-door monitoring
- FreeRTOS task scheduling
- Web dashboard

---

## Author

**Milad Mohseni**

Embedded Systems & IoT Engineer

Areas of Interest:

- Embedded Systems
- ESP32 Development
- IoT Applications
- Sensor Interfacing
- Firmware Development
- Real-Time Monitoring Systems

---

## License

Licensed under the MIT License.
