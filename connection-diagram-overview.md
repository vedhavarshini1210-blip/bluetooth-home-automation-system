# Connection Diagram

## Overview

This document describes the hardware connections used in the Bluetooth Home Automation System. The Arduino Uno serves as the central controller and interfaces with the HC-05 Bluetooth module, DS3231 RTC module, and 4-channel relay module to control electrical appliances.

---

# Hardware Connection Diagram

```text
                    +----------------------+
                    |     Arduino Uno      |
                    +----------+-----------+
                               |
        -------------------------------------------------
        |                      |                       |
        ▼                      ▼                       ▼
 HC-05 Bluetooth         DS3231 RTC            Relay Module
        |                      |                       |
        ▼                      ▼                       ▼
 Smartphone          Time Scheduling         Electrical Appliances
```

---

# HC-05 Bluetooth Module Connections

| HC-05 Pin | Arduino Uno Pin   |
| --------- | ----------------- |
| VCC       | 5V                |
| GND       | GND               |
| TX        | D10 (Software RX) |
| RX        | D11 (Software TX) |

### Purpose

The HC-05 module enables wireless communication between the smartphone and Arduino Uno using Bluetooth.

---

# DS3231 RTC Module Connections

| RTC Pin | Arduino Uno Pin |
| ------- | --------------- |
| VCC     | 5V              |
| GND     | GND             |
| SDA     | A4              |
| SCL     | A5              |

### Purpose

The RTC module provides accurate real-time information for automatic appliance scheduling.

---

# Relay Module Connections

| Relay Pin | Arduino Uno Pin |
| --------- | --------------- |
| IN1       | D4              |
| IN2       | D5              |
| IN3       | D6              |
| IN4       | D7              |
| VCC       | 5V              |
| GND       | GND             |

### Purpose

The relay module receives digital control signals from Arduino Uno and switches connected electrical appliances safely.

---

# Power Connections

| Component    | Supply           |
| ------------ | ---------------- |
| Arduino Uno  | USB / 9V Adapter |
| HC-05        | 5V               |
| DS3231 RTC   | 5V               |
| Relay Module | 5V               |

All modules share a **common GND** to ensure reliable communication and stable system operation.

---

# Appliance Connections

Each appliance is connected through an individual relay channel.

```text
Arduino Uno
      │
      ▼
Relay Module
      │
 ┌────┴─────┐
 │          │
 ▼          ▼
Light      Fan
```

The relay electrically isolates the low-voltage Arduino circuit from high-voltage electrical appliances, ensuring safe operation.

---

# Communication Interfaces

| Module                 | Interface    |
| ---------------------- | ------------ |
| Smartphone ↔ HC-05     | Bluetooth    |
| HC-05 ↔ Arduino Uno    | UART Serial  |
| RTC ↔ Arduino Uno      | I2C          |
| Arduino ↔ Relay Module | Digital GPIO |

---

# Connection Summary

* Arduino Uno acts as the central controller.
* HC-05 provides wireless Bluetooth communication.
* DS3231 RTC enables time-based automation.
* Relay module safely controls electrical appliances.
* All modules operate on a regulated 5V supply with a common ground connection.

---

# Reference Diagram

Add the circuit connection image below:

```text
assets/circuit-diagram.png
```
