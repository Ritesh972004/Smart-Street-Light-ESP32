# Smart-Street-Light-ESP32
\
# 🌆 Smart Street Light System using ESP32

An IoT-based embedded system project that automatically controls street lights using an **LDR sensor** and **ESP32 microcontroller**.  
The system monitors ambient light intensity and turns street lights ON or OFF accordingly.  
It also sends real-time data to the **Blynk IoT dashboard** for remote monitoring.

---

## 🔧 Features

- Automatic control of LED (street light) using an LDR sensor.
- Real-time light intensity monitoring via Blynk IoT cloud.
- Wi-Fi-based connectivity using ESP32.
- Energy-efficient and scalable design.
- Demonstrates integration of IoT, sensors, and cloud communication.

---

## 🧠 Project Overview

| Component | Description |
|------------|-------------|
| **Microcontroller** | ESP32 |
| **Sensor** | LDR (Light Dependent Resistor) |
| **Actuator** | LED (simulates street light) |
| **Platform** | Arduino IDE + Blynk IoT |
| **Communication** | Wi-Fi (using ESP32 WiFi library) |

---

## ⚙️ Circuit Connections

| ESP32 Pin | Component | Description |
|------------|------------|-------------|
| GPIO 34 | LDR Sensor (Analog Input) | Reads light intensity |
| GPIO 2 | LED | Controls street light |
| 3.3V / GND | Power | Sensor and LED power supply |

---

## 🧩 Code Explanation

The main code is in the file [`smart_street_light.ino`](./smart_street_light.ino).

### Functional Flow:
1. Initialize ESP32 peripherals and connect to Wi-Fi & Blynk.
2. Read ambient light intensity using the LDR sensor.
3. Compare the value with a threshold (default = 500).
4. Turn ON/OFF LED based on light conditions.
5. Send live sensor data to the Blynk IoT dashboard.

---

## 🚀 Getting Started

### Requirements:
- [Arduino IDE](https://www.arduino.cc/en/software)
- ESP32 Board Manager installed
- [Blynk IoT App](https://blynk.io/)
- Wi-Fi connection

### Steps:
1. Open the file `smart_street_light.ino` in Arduino IDE.
2. Replace these credentials:
   ```cpp
   char ssid[] = "Your_WiFi_SSID";
   char pass[] = "Your_WiFi_Password";
   #define BLYNK_AUTH_TOKEN "Your_Blynk_Auth_Token"
