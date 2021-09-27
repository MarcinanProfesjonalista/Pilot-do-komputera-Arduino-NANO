#define EI_ARDUINO_INTERRUPTED_PIN // to enable pin states functionality 
#include <EnableInterrupt.h>

String identyfikator = "pilot_2";

int wyslij_button = 2;
int taruj_button = 3;
int cofnij_button = 4;

//LongPressedButttons
bool i_p_active = false;
long buttonTimer = 0;
int longPressTimer = 100;
bool timerPassed = false;


bool cofnij_button_active = false;
bool wyslij_button_active = false;
bool taruj_button_active = false;

void wyslij() {
  //dodałem debouncing bo zliczało nieraz 3 krotnie więcej niż powinno.
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  // If interrupts come faster than 1000ms, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > 1000)
  {
    Serial.print("w\n\r");

  }
  last_interrupt_time = interrupt_time;
}



void taruj() {      //dodałem debouncing bo zliczało nieraz 3 krotnie więcej niż powinno.
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  // If interrupts come faster than 1000ms, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > 1000)
  {
    Serial.print("t\n\r");

  }
  last_interrupt_time = interrupt_time;
}



void cofnij() {
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  // If interrupts come faster than 1000ms, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > 1000)
  {
    Serial.print("c\n\r");

  }
  last_interrupt_time = interrupt_time;
}



void setup() {
  Serial.begin(9600);
  pinMode(wyslij_button, INPUT_PULLUP);
  pinMode(taruj_button, INPUT_PULLUP);
  pinMode(cofnij_button, INPUT_PULLUP);

  //enableInterrupt(wyslij_button, wyslij, RISING);
  //enableInterrupt(taruj_button, taruj, RISING);
  //enableInterrupt(cofnij_button, interruptFunction,CHANGE);

}

void loop() {

  if (Serial.available()) {
    String wiadomosc = Serial.readStringUntil('\n');

    //Serial.println("WIADOMOSC: "+wiadomosc);
    if (wiadomosc == "C1\r") {
      Serial.print("C1 A\r\n");

    }
    if (wiadomosc == "C0\r") {
      Serial.print("C0 A\r\n");

    }
    if (wiadomosc == "NB\r") {
      Serial.print("NB A");
      Serial.print(" \"");
      Serial.print(identyfikator);
      Serial.print("\"");
      Serial.print("\r\n");
      // Serial.print("NB A 999999\r\n");
    }
    if (wiadomosc == "?") {
      Serial.println("Komendy: C0@CRLF; C1@CRLF;  NB@CRLF");
    }
    if (wiadomosc == "?\r\n") {
      Serial.println("Komendy: C0@CRLF; C1@CRLF;  NB@CRLF");
    }
  }

  if (digitalRead(cofnij_button) == HIGH) {  //Tu jest odwróciona logika ze względu na to że został zastosowany CZERWONY przycisk NC.
    if (cofnij_button_active == false) {
      cofnij_button_active = true;
      buttonTimer = millis();
    }//Zapamietuje stan nacisniecia przycisku
    if ((millis() - buttonTimer) > longPressTimer) {
      cofnij();
    } else {}
  } else {//Serial.print(" dp=lo ");
    cofnij_button_active = false;
  }

  if (digitalRead(wyslij_button) == LOW) {
    if (wyslij_button_active == false) {
      wyslij_button_active = true;
      buttonTimer = millis();
    }//Zapamietuje stan nacisniecia przycisku
    if ((millis() - buttonTimer) > longPressTimer) {
      wyslij();
    } else {}
  } else {//Serial.print(" dp=lo ");
    wyslij_button_active = false;


  }
  if (digitalRead(taruj_button) == LOW) {

    if (digitalRead(taruj_button) == LOW) {
      if (taruj_button_active == false) {
        taruj_button_active = true;
        buttonTimer = millis();
      }//Zapamietuje stan nacisniecia przycisku
      if ((millis() - buttonTimer) > longPressTimer) {
        taruj();
      } else {}
    }

  } else {//Serial.print(" dp=lo ");
    taruj_button_active = false;
  }
}
