#define LASER_PIN (4) // Set the pin the Arduino will use
#define SEND_DELAY (5) // In milliseconds

const int DELAY_BETWEEN_BYTES = 10;

void setup() {
  pinMode(LASER_PIN, OUTPUT);
  Serial.begin(9600);
  sendByte(0x7); // Make sure the arduino is working
}

void loop() {
  while(Serial.available()) {
    char msg = Serial.read(); // gets one byte at a time from the serial port
    Serial.write(msg);
    sendByte(msg);
  }
}

void sendString(String str) {
  for(int i = 0; i < str.length(); i++) {
    sendByte(str.charAt(i));
  }
}

void sendByte(char byte_to_send) {
  digitalWrite(LASER_PIN, HIGH); // Send an initial start signal
  delay(SEND_DELAY); // Delay the signal
  for(int i = 0; i < 8; i++) { // Begin signal transmission
    char bit_value = (byte_to_send >> i) & 1; // Clear all bits except the one we want https://stackoverflow.com/questions/41708333/turn-byte-into-array-of-bits-c
    digitalWrite(LASER_PIN, bit_value ? HIGH : LOW); // Send either a high or low value
    delay(SEND_DELAY); // Delay between bits
  }
  digitalWrite(LASER_PIN, LOW); // Stop signal transmission
 delay(DELAY_BETWEEN_BYTES); // Leave a gap between each byte
}
