#  Smart Braille Learning System

## 📌 Project Overview
The **Smart Braille Learning System** is an assistive technology project designed to help visually impaired individuals learn Braille through **speech-to-Braille conversion**. The system listens for spoken words or letters, converts them into corresponding Braille patterns, and uses **vibration motors** to simulate the tactile Braille dots.

This project aims to make Braille learning more **interactive, portable, and accessible**, without the need for large mechanical displays.

---

## 🚀 Features
- 🎙 **Offline Speech Recognition** — Detects specific spoken letters/words (e.g., A–Z, numbers).
- ⠿ **Braille Pattern Generation** — Maps detected speech to the correct **6-dot Braille pattern**.
- 🔔 **Vibration Feedback** — Activates vibration motors to simulate Braille dots.
- 🛠 **ESP32-based Control** — Handles motor control and speech recognition processing.
- 🎯 **Focused Word Detection** — Ignores unwanted sounds; detects only pre-trained words.

---

## 🛠 Hardware Components
- **ESP32** (Microcontroller)
- **INMP441** MEMS High Precision Omnidirectional Microphone Module (I2S interface)
- **6 Vibration Motors** (One per Braille dot)
- **MOSFET Driver Circuit** (for motor control)
- Breadboard & Jumper Wires
- USB Cable (for ESP32 programming)
- Power Supply (5V)

---

## 🧠 Software & Tools
- **Arduino IDE** (ESP32 programming)
- **TensorFlow Lite for Microcontrollers** (Keyword detection)
- **Python** (Dataset processing & model training)
- **Braille Mapping Logic** (A–Z, Numbers)
- **Embedded C/C++** (ESP32 firmware)

---

## ⚙️ Working Principle
1. **Audio Capture** → The INMP441 microphone captures the spoken input.
2. **Speech Recognition** → ESP32 processes the sound using a **TFLite model** for keyword detection.
3. **Braille Mapping** → Recognized letter/word is mapped to its corresponding Braille pattern.
4. **Motor Activation** → Specific vibration motors are triggered to simulate Braille dots.
5. **User Feedback** → Learner can feel the Braille representation through vibrations.

---

## 🔌 Circuit Diagram
