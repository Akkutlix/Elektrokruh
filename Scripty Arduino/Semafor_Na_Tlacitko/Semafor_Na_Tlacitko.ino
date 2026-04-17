int red = 12;
int yellow = 11;
int green = 10;
int button = 13;

bool mode = 0;
unsigned long lastTime = 0;
int trafficState = 0;

const unsigned long redTime = 5000;
const unsigned long yellowTime = 2000;
const unsigned long greenTime = 5000;

bool lastButtonState = HIGH;
bool blinkState = false;

void setup()
{
  pinMode(green, OUTPUT); //zelena
  pinMode(yellow, OUTPUT); //zluta
  pinMode(red, OUTPUT); //cervena
  pinMode(button, INPUT_PULLUP); //tlacitko
}

void loop()
{
  handleButton();

  if (mode == 0) {
    Active();
  }
  else {
    Inactive();
  }
}

void handleButton() {
  bool buttonState = digitalRead(button);

  if (lastButtonState == HIGH && buttonState == LOW){
    mode = !mode;
    trafficState = 0;
    lastTime = millis();
  }

  lastButtonState = buttonState;
}

void Active() {
  unsigned long now = millis();

  switch (trafficState) {

    case 0:
      setLights(HIGH, LOW, LOW);
      if (now - lastTime >= redTime) {
        trafficState = 1;
        lastTime = now;
      }
      break;

    case 1:
      setLights(HIGH, HIGH, LOW);
      if (now - lastTime >= yellowTime) {
        trafficState = 2;
        lastTime = now;
      }
      break;

    case 2:
      setLights(LOW, LOW, HIGH);
      if (now - lastTime >= greenTime) {
        trafficState = 3;
        lastTime = now;
      }
      break;

    case 3:
      setLights(LOW, HIGH, LOW);
      if (now - lastTime >= yellowTime) {
        trafficState = 0;
        lastTime = now;
      }
      break;
  }
}

void Inactive() {
  unsigned long now = millis();

  setLights(LOW, blinkState, LOW);

  if (now - lastTime >= 1000) {
    blinkState = !blinkState;
    lastTime = now;
  }
}

void setLights(bool r, bool y, bool g) {
  digitalWrite(red, r);
  digitalWrite(yellow, y);
  digitalWrite(green, g);
}