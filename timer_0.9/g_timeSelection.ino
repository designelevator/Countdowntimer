void timeSelection() {
  // Set initial LED color to blue
  int whiteLed = 0; 
  leds[whiteLed] = CRGB::Blue;
  FastLED.show();
  
  // Read the rotary encoder and check if the value has changed
  encoder.tick();
  int value = encoder.getPosition();
  
  if (value != lastEncoderValue) {     
    if (millis() - debounceTimer > debounceDelay) {
      if (value <= lastEncoderValue) { // If the encoder is rotating clockwise
        counter++;
        encdir = 1;
        whiteLed = counter - 1; 
        Serial.print("Led pointer positive: ");
      } else {
        counter--;
        encdir = -1;
        whiteLed = counter; 
        Serial.print("Led pointer negative: ");
      }
       Serial.println(whiteLed);
      
      if (encdir == 1) { // If rotating clockwise
        leds[whiteLed] = CRGB::Blue; // Set LED color to blue
        if (whiteLed == 4 || whiteLed == 9 || whiteLed == 19 || whiteLed == 24 || whiteLed == 34 || whiteLed == 39 || whiteLed == 49 || whiteLed == 54) {
          leds[whiteLed] = CRGB::Aqua; // Set the green LEDs
        }
        else if (whiteLed == 14 || whiteLed == 29 || whiteLed == 44 || whiteLed == 59 ) {
          leds[whiteLed] = CRGB::Purple; // Set the green LEDs
        }
      } else { // If rotating counterclockwise
        leds[whiteLed] = CRGB::Black; // Set all LEDs to black
      }
      
      FastLED.show();
      debounceTimer = millis(); // Start the debounce timer
    }
    
    // Set upper and lower limits for the counter variable
    if (counter > 60) {
      counter = 60;
    } else if (counter < 1) {
      counter = 1;
    }
    
    lastEncoderValue = value; // Update lastEncoderValue with the current value
    Serial.print("Position: ");
    Serial.println(counter);
  }
}
