/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>
int pino13 = 13;
int pino2 = 2;
int pino7 = 7;

int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(pino13,OUTPUT);
  pinMode(pino2,OUTPUT);
  pinMode(pino7,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    


 digitalWrite(pino7,HIGH);
    
    if( results.value == 2534850111

 ) {
        digitalWrite(pino13,HIGH);
    }
    
    if( results.value == 4294967295
 ) {
      digitalWrite(pino13,LOW);

    }
  

    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
