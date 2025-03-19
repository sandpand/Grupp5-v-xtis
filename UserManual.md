# User Manual: Smart Plant Watering System

## 1. Introduction
This system is designed to automatically monitor and water plants using an Arduino platform. The system measures soil moisture and light levels to control a water pump and UV-LED, providing optimal watering and visual feedback.

---

## 2. System Components
- **Arduino Uno** – Control system
- **Moisture Sensor** – Measures soil moisture level
- **Light Sensor (LDR)** – Detects light level
- **Water Pump** – Automatically waters when needed
- **RGB-LED** – Displays plant status with colors
- **UV-LED** – Activates at low light levels
- **LCD Screen** – Displays current sensor values
- **Relay Module** – Controls the water pump's on/off state

---

## 3. Usage
### 3.1 System Functions
- **Startup Mode:** The system starts reading sensor data immediately.
- **LED Status:**
  - 🟢 **Green:** Good moisture level
  - 🔵 **Blue:** Moderate moisture level
  - 🔴 **Red:** Dry soil – pump activated
- **UV-LED:**
  - **On:** Low light level detected
  - **Off:** Sufficient light level
- **LCD Screen:** Displays current moisture and light values

---

## 4. Maintenance
- **Sensors:** Clean regularly to ensure accurate readings.
- **Pump:** Check hoses and connections to avoid blockages.
- **Power Supply:** Check cables and power adapter.

---

## 5. Troubleshooting
| **Problem** | **Possible Solution** |
|---|---|
| Pump does not start | Check cables, relay, and code |
| LED displays the wrong color | Ensure RGB cables are correctly connected |
| Nothing is displayed on the LCD | Check connections to the LCD pins |
| UV-LED does not light up | Check connection and light values |
