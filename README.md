# Homecoming Float 2022 - Clemson University

This repository contains the code used to automate and bring the Back to the Future themed float to life for Clemson University homecoming in Fall 2022.

---

## Table of Contents
- [Example / Screenshots](#example--screenshots)
- [How It Works](#how-it-works)
  - [homecoming\_iotrelaycontrol.ino](#homecoming_iotrelaycontrolino)
  - [ListenAndPlay.py](#listenandplaypy)
  - [PlaySound.py](#playsoundpy)
  - [LEDCode.ino](#ledcodeino)
- [License](#license)

---


## Example / Screenshots

## How It Works

### homecoming_iotrelaycontrol.ino
This Arduino program combines **relay control, a buzzer / speakers, and dynamic LED effects** using the FastLED library.  

- **Relay Control**: Toggles an IoT relay (`IOTRELAY`) via the `TurnOnMotors()` function to activate connected devices for a set duration.  
- **Buzzer**: Generates a 1 kHz tone for 1 second, alternating with 1 second of silence. Useful for debugging communication and sound sequences.
- **LED Effects**:  
  - **ElectricScatter**: Lights LEDs in yellow and blue tones at random positions, creating a scattered flicker effect.  
  - **ElectricSpark**: Sequentially lights groups of LEDs in random colors, producing a spark-like motion along the strip.  
  - **ElectricTrail**: Creates a moving trail of light that fades as it advances, simulating electrical discharge.  
- **Power Management**: Caps LED power at **500 mA @ 5V** and limits brightness to reduce strain on the hardware.  

This is useful for interactive projects that need synchronized **light, sound, and motor/relay effects**.

### ListenAndPlay.py
This Python script, runs on Raspberry PI, listens to serial input (e.g., from an Arduino) and plays specific sound effects using Pygame. Commands like `"GIGAWATTS"`, `"ROADS"`, and `"STOP"` determine which audio file is played or stopped, allowing hardware events / LED sequences to trigger sounds.

### PlaySound.py
This script continuously loops two audio effects using Pygame. It alternates between applause and electric sounds with pauses based on their durations, making it useful for demonstrations or automated sound playback.

### LEDCode.ino
This Arduino program uses the **FastLED** library to drive a strip of WS2812B LEDs with power and brightness limits. Useful for testing different LED patterns without the need to setup the rest of the system.

- In the main `loop()`, LEDs are randomly assigned **yellow** or **blue** shades with varying brightness to create a flickering effect.  
- The optional `ElectricTrail()` function produces a moving trail of light, where groups of LEDs light up in random colors and fade out as the trail advances, simulating an electric spark effect.  
- Power is limited to **500 mA at 5V** to protect the LEDs and connected hardware.  


## License
This project is licensed under the Apache 2.0 License. See the LICENSE file for details.
