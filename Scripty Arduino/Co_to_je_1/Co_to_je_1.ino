const int leds[] = {8,9,10,11};
const int button = 2;

bool lastState = HIGH;

const int min = //(nejnižší číslo, co jsme mohli mít na binárním čítači)
const int max = //(nejvyšší číslo, co jsme mohli mít na binárním čítači) + 1

void setup() {
// DOPLNIT SETUP pinMode();

  randomSeed(analogRead(A0));
}

void loop() {
  bool currentState = digitalRead(button);

  if(lastState == HIGH && currentState == LOW){
    int num = random(min, max);

    for(int i = 0; i < 4; i++){
      digitalWrite(leds[i], (num >> i) & 1);
    }

    delay(200);
  }

  lastState = currentState;
}