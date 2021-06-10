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
      //dodałem debouncing bo zliczało nieraz 3 krotnie więcej niż powinno.
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    // If interrupts come faster than 1000ms, assume it's a bounce and ignore
    if (interrupt_time - last_interrupt_time > 1000)
    {
      Serial.println("w");

    }
    last_interrupt_time = interrupt_time;
  }
  


void taruj() {      //dodałem debouncing bo zliczało nieraz 3 krotnie więcej niż powinno.
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    // If interrupts come faster than 1000ms, assume it's a bounce and ignore
    if (interrupt_time - last_interrupt_time > 1000)
    {
      Serial.println("t");

    }
    last_interrupt_time = interrupt_time;
  }
  


void cofnij() {    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    // If interrupts come faster than 1000ms, assume it's a bounce and ignore
    if (interrupt_time - last_interrupt_time > 1000)
    {
      Serial.println("c");

    }
    last_interrupt_time = interrupt_time;
  }
  


void setup() {
  Serial.begin(9600);
  pinMode(wyslij_button, INPUT_PULLUP);
  pinMode(taruj_button, INPUT_PULLUP);
  pinMode(cofnij_button, INPUT_PULLUP);

  enableInterrupt(wyslij_button, wyslij, RISING);
  enableInterrupt(taruj_button, taruj, RISING);
  //enableInterrupt(cofnij_button, interruptFunction,CHANGE);

}

void loop() {
  //Serial.println("d");
  if (digitalRead(cofnij_button) == HIGH) {  //Tu jest odwróciona logika ze względu na to że został zastosowany CZERWONY przycisk NC. 
    
        cofnij(); 

  }
}
