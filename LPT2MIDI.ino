/* remember to chage SERIAL_TX_BUFFER_SIZE 512 in HardwareSerial.h so large sysex's go through as well */
void receive() {
  Serial.write((PIND>>3) + (PINB<<5));
}

void setup() {
  DDRB = 0;
  DDRD = 0;
  Serial.begin(31250);
  attachInterrupt(digitalPinToInterrupt(2), receive, RISING);
}

void loop() {
}
