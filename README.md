# Arduino Temperature Monitoring & Alert System 🌡️🔔

An embedded temperature monitoring and warning project built using an **Arduino Uno**, a **DS18B20 digital temperature sensor**, a **16x2 LCD display**, and an **LED alert indicator**. The system continuously tracks ambient temperature and triggers an instant warning when the value exceeds a pre-set threshold of **25.0 °C**.

---

## 🚀 Features
* **Real-Time Monitoring:** Continuously tracks temperature via the 1-Wire protocol using the DS18B20 sensor.
* **Live LCD Feedback:** Displays real-time temperature readings and operational status messages on a 16x2 LCD screen.
* **Visual Alert System:** Automatically lights up an LED indicator whenever the temperature crosses the 25.0 °C threshold.
* **Robust Error Handling:** Detects disconnected or faulty sensors and reports errors directly to both the LCD and Serial Monitor[cite: 4].

---

## 🛠️ Components Required
* 1x Arduino Uno[cite: 4]
* 1x DS18B20 Temperature Sensor[cite: 4]
* 1x 16x2 LCD Display[cite: 4]
* 1x LED (Alert Indicator)[cite: 4]
* 1x 4.7kΩ Resistor (Pull-up for 1-Wire data line)
* 1x 220Ω Resistor (Current-limiting for LED)
* 1x Breadboard & Jumper Wires[cite: 4]

---

## 🔌 Circuit Wiring Guide

| Component / Pin | Arduino Connection |
| :--- | :--- |
| **DS18B20 Data Pin** | Digital Pin 9 (with 4.7kΩ pull-up resistor to 5V)[cite: 4] |
| **LCD RS Pin** | Digital Pin 12[cite: 4] |
| **LCD Enable (E) Pin** | Digital Pin 11[cite: 4] |
| **LCD Data Pins (D4–D7)** | Digital Pins 5, 4, 3, 2[cite: 4] |
| **LED Anode (+)** | Digital Pin 8 via 220Ω Resistor[cite: 4] |
| **Power Rails** | 5V and GND connected to breadboard rails |

---

