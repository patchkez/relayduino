

#include "MainBoard.h"
#include "Arduino.h"
#include "Globals.h"

/*
  TODO:
  dip switch pins: 52,50,48,46
  led pins: 36 (red), 28 (blue)
*/

MainBoard::MainBoard() {
  // TODO read address dip switch
  id = 0;
  pinMode(BLUE_LED_PIN, OUTPUT);
  digitalWrite(BLUE_LED_PIN, LOW);
  pinMode(RED_LED_PIN, OUTPUT);
  digitalWrite(RED_LED_PIN, LOW);
}

int MainBoard::getId() {
  return id;
}

void MainBoard::setRedLed(bool value) {
  digitalWrite(RED_LED_PIN, value ? HIGH : LOW);
}


void MainBoard::blinkBlueLed(int timeMs) {
  digitalWrite(BLUE_LED_PIN, HIGH);
  blueLedTimer.sleep(timeMs);
}

void MainBoard::loop() {

  if(blueLedTimer.isOver()) {
    digitalWrite(BLUE_LED_PIN, LOW);
  }


}