const int leds[] = {8,9,10,11};
const int button = 2;

int index = 0;
int direction = 1;

void setup() {
// DOPLNIT SETUP
}

void loop() {
  if(digitalRead(button) == LOW){
    direction *= -1;
    delay();
  }

  for(int i=0;i<4;i++) digitalWrite(leds[i], LOW);
  digitalWrite(leds[index], HIGH);

  index += direction;
  if(index > 3) index = 0;
  if(index < 0) index = 3;

  delay();
}