void setup() {
  Serial.begin(115200);
  delay(2000);
  FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  gPal = CRGBPalette16(CRGB::Red, CRGB::Yellow, CRGB::White, CRGB::Aqua);
  timedownPal = CRGBPalette16(CRGB::OrangeRed, CRGB::Yellow, CRGB::YellowGreen, CRGB::OrangeRed);
  pinMode(SWpin, INPUT_PULLUP);
  Serial.println("Setup done");
}
