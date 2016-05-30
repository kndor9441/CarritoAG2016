#include <IRremote.h>

int RECV_PIN = 7; //define input pin on Arduino

int motorA = 12;
int motorA1 = 11;
int motorB = 10;
int motorB1 = 9;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  pinMode(motorA, OUTPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(motorB1, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value );
    irrecv.resume(); // Receive the next value
  }
  if (results.value ==3255005345) //Tecla de arriba
  {
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorB1,HIGH);
    

  } //HACIA ADELANTE


  if (results.value == 2173897225) //Tecla de arriba
  {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorB1,LOW);

    digitalWrite(motorA, HIGH);
    digitalWrite(motorB,HIGH);

   
 }//HACIA ATRAS


 if (results.value == 553866289) //Tecla de arriba
  {
    digitalWrite(motorA1,  HIGH);
    digitalWrite(motorB1,HIGH);

    digitalWrite(motorA, LOW);
    digitalWrite(motorB,LOW);
    
  }//hacia la derecha


  
 if (results.value == 2553984193) //Tecla de arriba
  {
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorB1,HIGH);

    digitalWrite(motorA, LOW);
    digitalWrite(motorB,LOW);

  }//hacia la izquierda


  

 if (results.value == 3138312673) //Tecla de arriba
  {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorB1,LOW);

    digitalWrite(motorA, LOW);
    digitalWrite(motorB,LOW);

  }





  
  /*if (results.value == 284106975) 
  {
  digitalWrite(motorA, LOW);
  }*/
}

