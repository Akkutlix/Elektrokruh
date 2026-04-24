const int ledPins[4] = {8, 9, 10, 11};
const int buttonPin = 2;

int counter = 0;

bool lastButtonState = HIGH;
bool currentButtonState;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
// DOPLNIT SETUP
}

void loop() {
  bool reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != currentButtonState) {
      currentButtonState = reading;

      if (currentButtonState == LOW) {
        counter++;
        if (counter > 15) counter = 0;

        updateLEDs();
      }
    }
  }

  lastButtonState = reading;
}

void updateLEDs() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], (counter >> i) & 1);
  }
}