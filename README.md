<div align="center"> <h1> 🚀 ViraWM – Advanced WiFi Manager for ESP8266 </h1></div>
<br>
<p align="center">
  <img src="https://img.shields.io/badge/ESP8266-ViraWM-0ea5e9?style=for-the-badge&logo=espressif"/>
  <img src="https://img.shields.io/badge/IoT-WiFi_Manager-1f2937?style=for-the-badge&logo=wifi"/>
  <img src="https://img.shields.io/badge/Author-Mostafa%20MirMousavi-ff8800?style=for-the-badge&logo=github"/>
  <img src="https://img.shields.io/badge/Version-1.0.0-22c55e?style=for-the-badge&logo=semantic-release"/>
  <img src="https://img.shields.io/badge/Status-Stable-success?style=for-the-badge&logo=checkmarx"/>
</p>

<p align="center">
  <b>⚡ Lightweight • 🔌 Plug & Play • 📡 Smart Connectivity • 🧠 Self-Healing Network Engine</b>
</p>

<p align="center">
  <i>
    Professional-grade WiFi management library for ESP8266 IoT systems with automatic fallback, captive portal configuration, and persistent network memory.
  </i>
</p>


# ⚡ Overview

ViraWM is a professional-grade WiFi management library for ESP8266 designed by ViraMedar (Mostafa MirMousavi).

It removes the complexity of WiFi configuration and replaces it with a smart, self-healing connection system.

## ✨ Key Features

✔ Captive Portal WiFi Setup (Browser-based)  
✔ Static IP / DHCP Switching  
✔ EEPROM Persistent Storage  
✔ Auto AP Fallback System  
✔ One-line AutoConnect API  
✔ WiFi Profile Reset (Factory Reset)  
✔ Lightweight ESP8266 Optimized  

# 🧠 Smart Connection Engine

At startup, ViraWM automatically decides the best connection strategy:

### 🔵 Normal Mode (Saved Credentials Found)

✔ Connects automatically to saved WiFi  
✔ Applies Static IP (if enabled)  

---

<p align="center">
  <img src="https://raw.githubusercontent.com/admin3314/Vira_WiFi_Manager/main/assets/demo.jpg" width="260"/>
</p>

<p align="center">
  <b>Static IP Configuration Panel</b><br>
  <sub>Part of ViraWM Captive Portal UI</sub>
</p>

---

✔ Restores previous network state  
✔ Runs in STA mode

🔴 Recovery Mode (No WiFi / Failed Connection)

✔ Switches to Access Point (AP) mode

✔ Starts configuration portal

✔ Allows WiFi setup via browser

✔ Saves configuration to EEPROM

# 📡 AP Configuration Portal

When the device enters setup mode, it creates a WiFi network:

# 📶 Vira WiFiManager Configuration

📲 User Flow:

Connect with phone or laptop

Open browser

Configure WiFi settings:

SSID 📡

Password 🔐

Static IP (optional) 🌐

Subnet Mask 🧩

Gateway 🚪

Save & reboot automatically

# 🌐 Static IP System

ViraWM supports full network manual configuration:

✔ Available Settings

IP Address

Subnet Mask

Gateway

🔄 Modes:

Static Mode: Manual network control

DHCP Mode: Automatic IP assignment

# 🧹 WiFi Profile Reset

You can fully reset stored network credentials anytime:

```cpp
wifiManager.clearWiFiProfile(true);
```

What happens:

  🧹 Erases saved SSID & Password

  💾 Clears EEPROM storage

  🔄 Forces AP Mode on next boot

---
  
## 📦 Installation

### 1️⃣ Download Library
Clone or download repository

### 2️⃣ Install
Copy folder to:
Documents/Arduino/libraries/ViraWM

### 3️⃣ Restart Arduino IDE
Done ✔

  
---
 
# 🔧 Basic Example
```cpp
#include <WiFiClient.h>
#include <ViraWM.h>
#include <EEPROM.h>

#define BAUD_RATE 115200
#define Server_Port 80

ESP8266WebServer server(Server_Port);

void setup() {
  EEPROM.begin(512);
  Serial.begin(BAUD_RATE);
  delay(100);

  ViraWM wifiManager;

  // Auto connect or start AP portal
  wifiManager.autoConnect("Vira WiFiManager Configuration");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("IP address: " + WiFi.localIP().toString());

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // Your code here
}
```

## 🔄 How It Works

```text
┌───────────────┐
│   ESP Boots   │
└──────┬────────┘
       │
       ▼
┌──────────────────────┐
│ Read EEPROM Config   │
└──────┬───────────────┘
       │
       ▼
┌──────────────────────┐
│ Credentials Exists ?  │
└──────┬───────────────┘
   YES │            NO
       ▼              ▼
┌──────────────┐   ┌──────────────────┐
│ Connect WiFi │   │  Start AP Mode   │
└──────┬───────┘   └──────┬───────────┘
       │                  │
       ▼                  ▼
┌──────────────┐   ┌──────────────────┐
│ Connection OK│   │ Captive Portal   │
└──────┬───────┘   └──────┬───────────┘
       │                  │
   YES │              User Config
       ▼                  │
┌──────────────┐         ▼
│ STA MODE RUN │   ┌──────────────────┐
│ NORMAL STATE  │   │ Save to EEPROM   │
└──────────────┘   └──────┬───────────┘
                           │
                           ▼
                    ┌──────────────┐
                    │ Auto Reboot  │
                    └──────┬───────┘
                           │
                           ▼
                    ┌──────────────┐
                    │ Reconnect STA│
                    └──────────────┘
```

## 🛠 Feature Highlights

### ⚡ Fast AutoConnect Engine
Instant connection with stored credentials

### 📡 Captive Portal UI
Browser-based WiFi setup (no app needed)

### 💾 EEPROM Persistence
WiFi credentials saved permanently in flash memory

### 🌐 Static IP + DHCP Support
Switch between manual IP and automatic network config

### 🔄 Auto AP Fallback System
Automatically enters AP mode if connection fails

### 🧹 WiFi Profile Reset
Clean stored credentials anytime with one function

### 📶 ESP8266 Optimized Stability
Designed for long-running IoT and embedded systems

---

## 👨‍💻 Author

**Mostafa MirMousavi (@admin3314)**

- GitHub: https://github.com/admin3314  
- YouTube: https://youtube.com/@viramedar  
- Instagram: https://instagram.com/viramedar  
- Telegram Channel: https://t.me/viramedar
- Personal Telegram: https://t.me/viraep  


---

## 📜 License

MIT License

This project is released under a commercial-friendly custom license by ViraMedar.

---


# ⭐ Future Plans

ESP32 support

Web dashboard upgrade

JSON configuration API

OTA update integration

Multi-device provisioning


---


# 💬 Notes

This library is optimized for:

IoT projects

Smart home systems

ESP8266 automation

Industrial embedded systems
