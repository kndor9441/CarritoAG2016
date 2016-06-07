

int led1 = 7;
int led2 = 4;
int motorA = 5; 
int motorA1 = 6; 
int motorB = 9; 
int motorB1 = 10; 
            
int estado = '1';         

int echo = 2;            // define el pin 2 como (echo) para el Ultrasonico
int trig = 3;            // define el pin 3 como (trig) para el Ultrasonico
int time , dist;  // para Calcular distacia

void setup()  {           //Todo código se ejecuta solo una vez
  Serial.begin(9600);    // inicia el puerto serial para comunicacion con el Bluetooth
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(motorA, OUTPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(motorB1, OUTPUT);
  
  pinMode(echo, INPUT);   // define el pin 2 como entrada (pecho) 
  pinMode(trig,OUTPUT);   // define el pin 3 como salida  (ptrig) 
  pinMode(13,OUTPUT);
} 

void loop()  { //Todo código se ejecuta hasta que se apague el arduino

  if(Serial.available()>0){        // lee el bluetooth y almacena en estado
    estado = Serial.read();
  }
 /*  if (estado == '2' ){
                      
    }
    else if (estado == '0')
    {
                          digitalWrite(led1, LOW);
                          digitalWrite(led2, LOW);
    }*/
    
    if(estado=='8'){         // Boton desplazar al Frente
    
    digitalWrite(led1, HIGH);
                     
    digitalWrite(led2, HIGH);
    
    analogWrite(motorA1, HIGH);     
    analogWrite(motorB1, HIGH); 
    analogWrite(motorA, LOW);  
    analogWrite(motorB, LOW);       
  }
    if(estado=='6'){          // Boton DER
    analogWrite(motorA1, LOW);     
    analogWrite(motorB1, LOW);
    analogWrite(motorB, LOW);
    analogWrite(motorA, HIGH);  
  } 
    if(estado=='5'){          // Boton Reversa
    analogWrite(motorA, HIGH);    
    analogWrite(motorB, HIGH);
    analogWrite(motorA1, LOW);  
    analogWrite(motorB1, LOW);      
  }
  if(estado=='4'){          // Boton IZQ 
    analogWrite(motorA1, LOW);     
    analogWrite(motorB1, LOW); 
    analogWrite(motorA, LOW);  
    analogWrite(motorB, HIGH);      
  }
  if(estado=='0'){         // Boton Parar
    analogWrite(motorA1, LOW);     
    analogWrite(motorB1, LOW); 
    analogWrite(motorA, LOW);    
    analogWrite(motorB, LOW); 
  }

  

  
  if (estado =='3'){          // Boton ON,  se mueve sensando distancia 
  
     digitalWrite(trig, HIGH);   
     delay(0.01);
     digitalWrite(trig, LOW);
     
     time = pulseIn(echo, HIGH);              // Lee el tiempo del Echo
     dist = (time/2) / 29;            // calcula la distancia en centimetros
     delay(10); 
     
     if (dist <= 40 && dist >=2){    // si la distancia es menor de 40cm
        digitalWrite(13,HIGH);                 // Enciende LED
        
        digitalWrite(motorA1, LOW);                  // Parar los motores por 300 mili segundos
        digitalWrite(motorB1, LOW); 
        digitalWrite(motorA, LOW);    
        digitalWrite(motorB, LOW); 
        delay (300);
        
        digitalWrite(motorA1,  LOW);               // Reversa durante 200 mili segundos
        digitalWrite(motorB1, LOW); 
        delay(200);           
        
        digitalWrite(motorA1, HIGH);                // Girar durante 400 milisegundos   
        digitalWrite(motorB1, LOW); 
        digitalWrite(motorA, LOW);  
        digitalWrite(motorB, HIGH);  
        delay(400);
        
        
        
        digitalWrite(13,LOW);
     }
     else{                   // Si no hay obstaculos se desplaza al frente  
         digitalWrite(motorA1, HIGH);     
         digitalWrite(motorB1, HIGH); 
         digitalWrite(motorA, LOW);  
         digitalWrite(motorB, LOW); 
     }
  }
  if(estado=='0'){          // Boton OFF, detiene los motores no hace nada 
     digitalWrite(motorA1, LOW);     
    digitalWrite(motorB1, LOW); 
    digitalWrite(motorA, LOW);    
    digitalWrite(motorB, LOW); 
  }
}
