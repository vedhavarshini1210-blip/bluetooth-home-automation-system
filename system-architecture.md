# System Architecture

## Overview

The Bluetooth Home Automation System follows a layered embedded architecture that enables users to control electrical appliances wirelessly through a smartphone while also supporting automatic time-based scheduling using a Real-Time Clock (RTC) module.

The Arduino Uno acts as the central controller, processing Bluetooth commands received from the HC-05 module and scheduling information from the DS3231 RTC module. Based on these inputs, the relay module switches the connected appliances safely and efficiently.

---

# Architecture Diagram

```text
                  +----------------------+
                  |     Smartphone       |
                  | (Bluetooth Terminal) |
                  +----------+-----------+
                             |
                    Bluetooth Commands
                             |
                             v
                  +----------------------+
                  |  HC-05 Bluetooth     |
                  |      Module          |
                  +----------+-----------+
                             |
                    UART Serial Communication
                             |
                             v
                  +----------------------+
                  |     Arduino Uno      |
                  |  Main Controller     |
                  +----+------------+----+
                       |            |
             I2C       |            | Digital Output
                       |            |
                       v            v
              +---------------+  +----------------+
              | DS3231 RTC    |  | Relay Module   |
              | Time Schedule |  | 4-Channel      |
              +---------------+  +-------+--------+
                                        |
                                        |
                                        v
                           +---------------------------+
                           | Electrical Appliances     |
                           | Light • Fan • Other Loads |
                           +---------------------------+
```

---

# Architecture Layers

## 1. User Interface Layer

The user interacts with the system using a smartphone application that communicates with the HC-05 Bluetooth module. Commands such as turning appliances ON or OFF are transmitted wirelessly.

---

## 2. Communication Layer

The HC-05 Bluetooth module receives commands from the smartphone and transfers them to the Arduino Uno using UART serial communication.

---

## 3. Processing Layer

Arduino Uno functions as the central processing unit of the system.

Its responsibilities include:

* Receiving Bluetooth commands
* Reading current time from the RTC module
* Executing programmed control logic
* Controlling relay outputs
* Coordinating manual and scheduled operations

---

## 4. Scheduling Layer

The DS3231 RTC module continuously maintains accurate date and time.

Its responsibilities include:

* Real-time clock management
* Time-based appliance scheduling
* Battery-backed timekeeping during power interruptions

---

## 5. Control Layer

The relay module receives digital signals from the Arduino and safely switches connected electrical appliances.

This layer provides electrical isolation between the low-voltage control circuit and high-voltage loads.

---

## 6. Output Layer

The output layer consists of electrical appliances such as:

* Light
* Fan
* Other AC/DC Devices

The appliances respond according to Bluetooth commands or scheduled timings.

---

# Data Flow

```text
Smartphone
      │
      ▼
HC-05 Bluetooth Module
      │
      ▼
Arduino Uno
      │
 ┌────┴─────┐
 │          │
 ▼          ▼
RTC      Relay Module
 │          │
 └────┬─────┘
      ▼
Electrical Appliances
```

---

# Communication Protocols

| Module                 | Communication Method |
| ---------------------- | -------------------- |
| Smartphone ↔ HC-05     | Bluetooth            |
| HC-05 ↔ Arduino Uno    | UART Serial          |
| RTC ↔ Arduino Uno      | I2C                  |
| Arduino ↔ Relay Module | Digital GPIO         |

---

# Key Functional Modules

* Wireless Bluetooth Communication
* Real-Time Scheduling
* Embedded Control Logic
* Safe Relay-Based Switching
* Manual and Automatic Operation

---

# Summary

The system architecture integrates Bluetooth communication, real-time scheduling, and embedded control into a single platform. This layered design ensures reliable wireless operation, accurate time-based automation, safe appliance switching, and efficient energy management, making the project suitable for smart home automation applications.
