/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>
int pino3 = 3;

int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(pino3,OUTPUT);

  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    


   
    
    if( results.value == 4294967295
 ) {
        digitalWrite(pino3,HIGH);
    }
    
    if( results.value == 3782887607
 ) {
      digitalWrite(pino3,LOW);

    }
 
    
    if( results.value == 4294967295
 ) {
        digitalWrite(pino3,HIGH);
    }
    
    if( results.value == 3782912087
 ) {
      digitalWrite(pino3,LOW);

    }
 
 
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
