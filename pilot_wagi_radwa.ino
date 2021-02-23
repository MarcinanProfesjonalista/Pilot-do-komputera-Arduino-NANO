#define EI_ARDUINO_INTERRUPTED_PIN // to enable pin states functionality 
#include <EnableInterrupt.h>

int wyslij_button = 2;
int taruj_button = 3;
int cofnij_button = 4;

//LongPressedButttons
bool i_p_active = false;
long buttonTimer = 0;
int longPressTimer = 4000;
bool timerPassed = false; 

void wyslij() {
  Serial.println("w");
}

void taruj() {
  Serial.println("t");
}

void cofnij() {
  Serial.println("c");
}

void setup() {
  pinMode(wyslij_button, INPUT_PULLUP);
  pinMode(taruj_button, INPUT_PULLUP);
  pinMode(cofnij_button, INPUT_PULLUP);

  enableInterrupt(wyslij_button, wyslij, FALLING);
  enableInterrupt(taruj_button, taruj, FALLING);
  //enableInterrupt(cofnij_button, interruptFunction,CHANGE);

}

void loop() {
  if (digitalRead(cofnij_button) == HIGH) {  //Tu jest odwróciona logika ze względu na to że został zastosowany CZERWONY przycisk NC. 
    if (i_p_active == false) {
      i_p_active = true;
      buttonTimer = millis();
    }//Zapamietuje stan nacisniecia przycisku
    if ((millis() - buttonTimer) > longPressTimer) {
      if (timerPassed == false){
        cofnij(); 
        timerPassed = true;
      }
    } else {}
  } else {
    i_p_active = false;
    timerPassed = false;
  }
}
