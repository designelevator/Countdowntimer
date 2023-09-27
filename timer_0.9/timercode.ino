void timercode() {
  static byte heat[NUM_LEDS];
  timer = counter * 1000;
  Serial.print("Timer: ");
  Serial.println(timer);
  unsigned long startMillis = millis();
   

  for (int redLed = 0; redLed < NUM_LEDS; redLed++) {
    byte colorindex = scale8(heat[redLed], 240);
    CRGB color = ColorFromPalette(timedownPal, colorindex);
    int pixelnumber = redLed;
    leds[pixelnumber] = color;
    delay(15);
    FastLED.show();
  }
  
  delay(20);

  for (int blackLed = NUM_LEDS - 1; blackLed >= 0; blackLed--) {
    leds[blackLed] = CRGB::Black;
    unsigned long waitMillis = millis();
    
    while ((millis() - waitMillis) < timer) {
      buttonStats();
      int adjustLed = blackLed -1;

      // begining of code to read encoder and adjust
       encoder.tick();
        int value = encoder.getPosition();

        if (value != lastEncoderValue) {     
          if (millis() - debounceTimer > debounceDelay) {
            if (value <= lastEncoderValue) { // If the encoder is rotating clockwise
              blackLed++;
              leds[adjustLed] = CRGB::Teal;
              FastLED.show();
              delay(5);

          
            } 
            else {
              blackLed--;
              leds[adjustLed] = CRGB::Black;
              FastLED.show();
              Serial.print("removing time");
            }
            lastEncoderValue = value; 
            debounceTimer = millis();
            Serial.print("adding time: ");
            Serial.println(blackLed);
            Serial.print("To be lit led value");
            Serial.println(adjustLed);
            if (blackLed > 60) {blackLed=60;
             Serial.print("BlackLed was adjusted to 60");}
           
          }
        }
        // end of the code to read encoder and adjust
      //delay(20); //trying to remove this to see if the readings are better on the encoder while not compromising the button --> no it crashes the program.
      if (buttonState != 1) {
        timer = 20; //this defines how quickly the led will switch off.
        break;
      }
      else {
       
      } 
      
      delay(5);
    }
    FastLED.show();
    waitMillis = millis();
  }

  delay(100);
  buttonState = 2; // this ensures both cases either with a click interrupt to animation or code runs smooth
}
