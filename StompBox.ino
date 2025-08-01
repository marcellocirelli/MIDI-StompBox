#include <MIDIUSB.h>
#include <Bounce2.h>

// Pins
const uint8_t potPins[6] = {A0, A1, A2, A3, A4, A5};
const uint8_t stompPins[2] = {2, 3};

// MIDI CCs
const uint8_t potCCs[6] = {14, 15, 16, 17, 18, 19};
const uint8_t stompCCs[2] = {20, 21};

// Stores last pot values
int lastPotVals[6] = {0, 0, 0, 0, 0, 0};

// MIDI channel and threshold before values change
uint8_t midiChannel = 1;
uint8_t threshold = 2;

// Initialize debouncer
Bounce debouncers[2];

// Sends a MIDI CC message
void sendCC(uint8_t cc, uint8_t val, uint8_t ch) {
  midiEventPacket_t event = {0x0B, uint8_t(0xB0 | (ch - 1)), cc, val};
  MidiUSB.sendMIDI(event);
  MidiUSB.flush();
}

void setup() {
  Serial.begin(115200);

  // Initialize stomp pins/debouncer
  for (int i = 0; i < 2; i++) {
    pinMode(stompPins[i], INPUT_PULLUP);
    debouncers[i].attach(stompPins[i]);
    debouncers[i].interval(20);
  }

  // Initialize last pot values to current readings. Prevents MIDI spam
  for (int i = 0; i < 6; i++) {
    lastPotVals[i] = map(analogRead(potPins[i]), 0, 1023, 0, 127);
  }
}

void loop() {
  // Iterates all analog inputs, maps to MIDI, compares to threshold
  // Sends reversed MIDI values for the pots because I soldered backwards
  for (int i = 0; i < 6; i++) {
    int currentVal = map(analogRead(potPins[i]), 0, 1023, 0, 127);

    if (abs(currentVal - lastPotVals[i]) > threshold) {
      if (i < 4) {
        sendCC(potCCs[i], 127 - currentVal, midiChannel); // reversed
      } else {
        sendCC(potCCs[i], currentVal, midiChannel);       // normal
      }
      lastPotVals[i] = currentVal;
    }
  }

  // Iterates over stomps. Updates debouncer, checks state and sends a 127 message
  // Code is written as such because using old 3PDT latching switches. Want it to act as momentary
  for (int i = 0; i < 2; i++) {
    debouncers[i].update();

    if (debouncers[i].fell() || debouncers[i].rose()) {
      sendCC(stompCCs[i], 127, midiChannel);
      sendCC(stompCCs[i], 0, midiChannel);
    }
  }
}