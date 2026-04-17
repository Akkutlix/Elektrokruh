int redPin = 11;
int greenPin = 9;
int bluePin = 10;

int button = 2;
int mode = 0;
const int modeMax = 6;

bool lastButtonState = HIGH;

unsigned long previousMillis = 0;
const int interval = 10;

int phase = 0;
int value = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(button, INPUT_PULLUP);
}

void setColor(int r, int g, int b) {
  analogWrite(redPin, r); //analogWrite(redPin, 255 - r);     pokud je dioda common anode (255 - x)
  analogWrite(greenPin, g); //analogWrite(greenPin,255 - g);  pokud je dioda common cathode (x)
  analogWrite(bluePin, b); //analogWrite(bluePin, 255 - b);
}

void Switch() {

  bool buttonState = digitalRead(button);

  if (lastButtonState == HIGH && buttonState == LOW) {

    if (mode == modeMax) {
      mode = 0;
    } 
    else {
      mode++;
    }

    delay(50); // jednoduchý debounce
  }

  lastButtonState = buttonState;
}

void loop() {

  Switch();

  switch (mode) {

    case 0:
      setColor(0,0,0);
      break;

    case 1:
      setColor(255,0,0);
      break;

    case 2:
      setColor(0,255,0);
      break;

    case 3:
      setColor(0,0,255);
      break;

    case 4:
      setColor(255,255,0);
      break;

    case 5:
      setColor(255,255,255);
      break;

    case 6:
      rainbow();
      break;
  }
}

void rainbow() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {

    previousMillis = currentMillis;

    switch (phase) {

      case 0: setColor(255, value, 0); break;
      case 1: setColor(255 - value, 255, 0); break;
      case 2: setColor(0, 255, value); break;
      case 3: setColor(0, 255 - value, 255); break;
      case 4: setColor(value, 0, 255); break;
      case 5: setColor(255, 0, 255 - value); break;
    }

    value++;

    if (value > 255) {
      value = 0;
      phase++;

      if (phase > 5) {
        phase = 0;
      }
    }
  }
}