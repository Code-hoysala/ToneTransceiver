# ToneTransceiver

`ToneTransceiver` is a lightweight, non-blocking full-duplex acoustic communication library for Arduino. It enables simultaneous sound output generation (transmitting tones via `tone()`) and audio signal input analysis (`analogRead()`) without halting your main loop execution.

## Features
- **Full-Duplex Capability:** Transmit tones and monitor incoming audio amplitudes concurrently.
- **Non-Blocking Architecture:** Timed tone playback and sampling windows that don't rely on blocking `delay()` calls.
- **Lightweight Design:** Optimized for low-memory AVR and ARM microcontrollers, requiring zero dynamic memory allocation (`malloc`-free).
- **Simple API:** Intuitive methods tailored for acoustic signaling, smart devices, and interactive projects.

---

## Hardware Requirements
- **TX Pin:** Connected to a piezo buzzer, speaker, or audio amplifier module (Digital PWM pin).
- **RX Pin:** Connected to a sound sensor module, microphone amplifier (like MAX9814 or similar), or audio input line (Analog pin).

---
