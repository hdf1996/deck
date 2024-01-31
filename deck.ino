
#include "Keyboard.h"

const int buttonPin = 8;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Keyboard.begin();
}

bool alreadyActed = false;
void loop() {
  int buttonState = digitalRead(buttonPin);
    Serial.println(buttonState);
  if (alreadyActed){
    if (buttonState == HIGH) {

      alreadyActed = false;
    }
  } else {
    if (buttonState == LOW) {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('n');
      Keyboard.releaseAll();

      alreadyActed = true;
    }
  }
}
