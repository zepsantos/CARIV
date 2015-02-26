#include <IRremote.h>
//MOTOR 1
int dir1PinA = 3;
int dir2PinA = 4;
//MOTOR 2
int dir1PinB = 5;
int dir2PinB = 6;

int RECV_PIN = 10;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {  

  Serial.begin(9600);

  pinMode(dir1PinA,OUTPUT);
  pinMode(dir2PinA,OUTPUT);
  pinMode(dir1PinB,OUTPUT);
  pinMode(dir2PinB,OUTPUT);
  irrecv.enableIRIn();

}

void loop() {
  if (irrecv.decode(&results)) {
    switch(results.value)

    {

    case 0x20DF02FD:  // SETA CIMA
      digitalWrite(dir1PinA, LOW);
      digitalWrite(dir2PinA, HIGH);
      Serial.println("Motor 1 Forward");
      break;

    case 0x20DF827D: //SETA BAIXO
      digitalWrite(dir1PinA, HIGH);
      digitalWrite(dir2PinA, LOW);
      Serial.println("Motor 1 Reverse");  
      break;
    case 0x20DF609F:    //SETA DIREITA
      digitalWrite(dir1PinB, LOW);
      digitalWrite(dir2PinB, HIGH);
      Serial.println("Motor 2 Forward");  
      break;
    case 0x20DFE01F:            //SETA ESQUERDA
      digitalWrite(dir1PinB, HIGH);
      digitalWrite(dir2PinB, LOW);
      Serial.println("Motor 2 Reverse");
      break;
    case 0x20DF22DD:  //BOTAO OK
      for (int thisPin = 2; thisPin < 11; thisPin++) {
        digitalWrite(thisPin, LOW); 
    

      }

      delay(500);
    }
    irrecv.resume();
  }
}



