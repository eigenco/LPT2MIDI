#include "Fifo.h"

static Fifo<byte, 192> fifo;

void setup() {
  static byte MASKB = B00000111; // Using lower 3 bits of the B port
  static byte MASKD = B11111000; // Using upper 5 bits of the D port
  // Set only the required bits to input, leaving all the other bits unchanged
  DDRB &= ~MASKB;
  DDRD &= ~MASKD;
  Serial.begin(31250);
  auto recieve = []() { fifo.push(((PIND & MASKD) >> 3) | ((PINB & MASKB) << 5)); };
  attachInterrupt(digitalPinToInterrupt(2), recieve, RISING);
}

void loop() {
  // TODO: we could check here for fifo overflow using the fifo.full()
  //       function and notifying somehow the user. May be by blinking
  //       the LED?
  if (!fifo.empty()) {
    Serial.write(fifo.pop());
  }
}
