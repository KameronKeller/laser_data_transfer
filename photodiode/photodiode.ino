const int TIME_DELAY = 6;
const int MIN_LIGHT_INTENSITY = 10;

bool is_idle = true; // RX is idle by default
char rx = 0;
int counter = 0;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}


void loop() {
  int lightIntensity = analogRead(A0); // Store the light intensity from the input pin into a variable
//  Serial.println(lightIntensity);
  bool is_high = lightIntensity > MIN_LIGHT_INTENSITY; // If the light intensity is greater than minimum required light, mark is_high as true
  if (is_idle) { // If no signal received, set rx and counter to 0
    rx = 0;
    counter = 0;
    if (is_high) { // If start signal received, prepare to receive message
      is_idle = false;
      delay(TIME_DELAY + (TIME_DELAY/2));  // Synchronize to the middle of the TX signal
    }
  } else {
      if (counter >= 7) { // If counter is >= 7, we have received an entire byte
         Serial.print(rx); // print this byte to the serial monitor
         is_idle = true; // Return to idle state, waiting for next message
         delay((TIME_DELAY/2)); // Re-synchronize to the TX signal
      } else { // Else if counter < 7, continue receiving individual bits
        rx |= is_high << counter; // Add the next bit to the rx variable, shifted down by the counter
        counter++; // Increment the counter
        delay(TIME_DELAY);  // Delay to remain in sync
    }
  }
}
