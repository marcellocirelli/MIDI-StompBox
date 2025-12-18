# MIDI Stompbox Controller

A **USB MIDI stompbox controller** built for hands-free control of effects, samples, and parameters in live performance and studio workflows.

This project focuses on reliable foot-operated MIDI control using a compact enclosure, momentary switches, and a microcontroller-based USB MIDI interface.

## Overview

This stompbox was designed as a flexible MIDI control surface for musicians who need simple, durable foot control without relying on large pedalboards or proprietary hardware.

The unit connects directly over **USB MIDI** and can be used with DAWs, virtual instruments, effects processors, and hardware that supports USB MIDI input.

## Features

- **USB MIDI output**
- Multiple **momentary footswitches**
- Sends configurable MIDI messages:
  - Control Change (CC)
  - Program Change
  - Note On / Off
- Designed for live performance reliability
- Compact and portable enclosure format

## Hardware Components

- **Arduino Micro**
  - USB-native microcontroller
- Momentary footswitches
- Custom wiring and signal conditioning
- Stompbox-style enclosure
- USB connection for power and MIDI data

## Software / Firmware

- Developed using the **Arduino IDE**
- Uses standard Arduino MIDI and USB libraries
- Firmware handles:
  - Footswitch scanning
  - Debouncing
  - MIDI message generation
  - Configurable control mappings

The firmware is structured to allow reassignment of switches to different MIDI messages with minimal changes.

## MIDI Capabilities

The controller can send:
- MIDI Control Change (CC)
- MIDI Program Change
- MIDI Note messages

This allows the stompbox to function as:
- An effects toggle controller
- A program / preset switcher
- A sample or loop trigger
- A general-purpose MIDI foot controller

## Technologies Used

- **Arduino Micro**
- Arduino IDE
- USB MIDI
- MIDI protocol
- Embedded C / C++
- Hardware interfacing and debouncing

## Purpose

This project demonstrates:
- Embedded systems development using Arduino
- USB MIDI implementation
- Hardware–software integration
- Design for live music performance
- Practical control-surface development

## Status

- Core functionality complete and tested
- Actively usable in live and studio contexts
- Future revisions may add additional switches or configuration options

## Notes

This project was developed independently as a personal music technology build and is included as an example of embedded programming, MIDI systems, and hardware control design.
