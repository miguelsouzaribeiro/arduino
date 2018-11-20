/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>
int pino13 = 13;
int pino12 = 12;
int pino11 = 11;

int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(pino13,OUTPUT);
  pinMode(pino12,OUTPUT);
  pinMode(pino11,OUTPUT);
  
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    
    if( results.value == 9 ) {
        digitalWrite(pino13,HIGH);
    }
    
    if( results.value == 65545 ) {
      digitalWrite(pino13,LOW);

    }
    
    if( results.value == 7 ) {
        digitalWrite(pino12,HIGH);
    }
    
    if( results.value == 65543 ) {
      digitalWrite(pino12,LOW);

    }
 
    
    if( results.value == 4 ) {
        digitalWrite(pino11,HIGH);
    }
    
    if( results.value == 65540 ) {
      digitalWrite(pino11,LOW);

    }
 
    
    if( results.value == 55 ) {
      for( int i=0; i<20; ++i ) {
        Serial.println(i);
        digitalWrite(pino12,HIGH);
        delay(100);
        digitalWrite(pino11,HIGH);
        delay(100);
        digitalWrite(pino13,HIGH);
        delay(100);
        digitalWrite(pino12,LOW);
        delay(100);
        digitalWrite(pino11,LOW);
        delay(100);
        digitalWrite(pino13,LOW);
        delay(100);
      }
        
    }
    
    if( results.value == 65591 ) {
      digitalWrite(pino12,LOW);
         delay(100);
      digitalWrite(pino11,LOW);
         delay(100);
      digitalWrite(pino13,LOW);
         delay(100);
    }
 
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
