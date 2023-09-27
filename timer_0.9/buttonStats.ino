void buttonStats() {
  static unsigned long lastDebounceTime = 0;    // the last time the button was toggled
  const unsigned long debounceDelay = 500;       // the debounce time; increase if the output flickers
  
  if (digitalRead(SWpin) == LOW) {          // check if button was pressed
    if ((millis() - lastDebounceTime) > debounceDelay) {   // debounce the button
      buttonState++;                  // increment buttonPresses count
      if (buttonState >=4) buttonState = 0;    // rollover every 2nd press
     // counter = 0; // Set counter to desired initial value
   // lastEncoderValue = 0; // Reset lastEncoderValue to 0 to prevent immediate increment/decrement
   //   FastLED.clear();
      lastDebounceTime = millis();    // update the debounce time
    }
  }

  if (lastbuttonState != buttonState) {           // if it changed
    lastbuttonState = buttonState;    // track last press count
    Serial.print("Button State: ");            // out to serial
    Serial.println(buttonState);
  }
}
