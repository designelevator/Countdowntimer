// Loop function
void loop() {
  
  // Set the first LED to blue to show that the program is running
  int whiteLed = 0;
  leds[whiteLed] = CRGB::Blue;
  FastLED.show();
  
  // Generate a random number for the LED animation
  random16_add_entropy(random8());
  
  // Check the button state
  buttonStats();
  
  switch(buttonState) {
    case 0:
      // If the button state is 0, enter time selection mode
      timeSelection();
      break;
    case 1:
      // If the button state is 1, start the timer
      timercode();
      break;
    case 2:
      // If the button state is 2, enter LED animation mode
      // Add randomness to the animation
      random16_add_entropy(random8()); 
      // Run the LED animation function
      ledAnimation();
      // Update the button state
      buttonStats();
      // Show the current LED frame
      FastLED.show();
      // Delay for a frame to maintain the specified frame rate
      FastLED.delay(1000 / FRAMES_PER_SECOND);
      counter = 0; // Set counter to desired initial value
      lastEncoderValue = 0; // Reset lastEncoderValue to 0 to prevent immediate increment/decrement
           
break;
    case 3:
      // Clear all LEDs
     FastLED.clear();
     buttonState = 0;
      buttonStats();
      // Set the LEDs to blue one by one with a delay
      /* for (int  whiteLed = 0;  whiteLed < counter;  whiteLed++) {
        // Turn on the current LEDf
        leds[whiteLed] = CRGB::Blue;
        // Delay for a short period to show the LED
        delay(20);
        // Show the current LED
        FastLED.show();
      }
      // Increment the button state to exit the reset mode
      // 
      whiteLed = 0; // Set the first LED to blue
      leds[whiteLed] = CRGB::Blue;
      FastLED.show();*/ 
      break;
    default:
      // Handle unexpected button states here
      break;
  }
}
