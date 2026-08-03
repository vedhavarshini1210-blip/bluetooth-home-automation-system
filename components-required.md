# Components Required

This document lists the hardware and software components required to build the Bluetooth Home Automation System.

---

# Hardware Components

| Component                    |   Quantity  | Purpose                                                           |
| ---------------------------- | :---------: | ----------------------------------------------------------------- |
| Arduino Uno                  |      1      | Main microcontroller used to control the entire system            |
| HC-05 Bluetooth Module       |      1      | Enables wireless communication between the smartphone and Arduino |
| DS3231 RTC Module            |      1      | Provides accurate real-time clock for automatic scheduling        |
| 4-Channel Relay Module       |      1      | Controls electrical appliances safely using Arduino signals       |
| Breadboard                   |      1      | Used for temporary circuit assembly and testing                   |
| Jumper Wires                 | As Required | Establishes electrical connections between components             |
| USB Data Cable               |      1      | Uploads the program to Arduino and provides power during testing  |
| 9V Battery / 5V Power Supply |      1      | Supplies power to the system                                      |
| Coin Cell Battery (CR2032)   |      1      | Maintains RTC time during power interruptions                     |
| Light Bulb                   |      1      | Demonstrates appliance control                                    |
| DC Fan                       |      1      | Demonstrates appliance switching through the relay                |

---

# Software Requirements

| Software                       | Purpose                                            |
| ------------------------------ | -------------------------------------------------- |
| Arduino IDE                    | Writing, compiling, and uploading Arduino programs |
| Bluetooth Terminal Application | Sends wireless control commands from a smartphone  |

---

# Communication Modules

## HC-05 Bluetooth Module

* Bluetooth Version: 2.0 + EDR
* Operating Voltage: 5V
* Communication Type: UART Serial
* Typical Range: Up to 10 meters

---

## DS3231 RTC Module

* Operating Voltage: 5V
* Communication Protocol: I2C
* Battery Backup Support
* High-Accuracy Real-Time Clock

---

# Relay Module Specifications

* Operating Voltage: 5V
* Number of Channels: 4
* Supports AC and DC Load Switching
* Provides Electrical Isolation
* Controlled through Arduino Digital Pins

---

# Development Platform

* Embedded System Platform
* Arduino Uno
* Embedded C Programming
* Bluetooth Communication
* Real-Time Scheduling

---

# Summary

The Bluetooth Home Automation System is built using readily available, low-cost electronic components. The combination of Arduino Uno, HC-05 Bluetooth Module, DS3231 RTC Module, and Relay Module enables reliable wireless appliance control with automatic time-based scheduling, making the system suitable for educational, prototype, and smart home applications.
