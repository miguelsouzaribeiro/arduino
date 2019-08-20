#include <Servo.h>
Servo meuservo1; 
Servo meuservo2; 
const int portaX = A1;
const int portaY = A0;

void setup(){
  Serial.begin(9600);
  meuservo1.attach(9);
  meuservo2.attach(10);

}

void loop(){
  int x = analogRead(portaX);
  int y = analogRead(portaY);
  int angulo1 = map(x, 0, 1023, 1, 180);
  int angulo2 = map(y, 0, 1023, 1, 180);

  meuservo1.write(angulo1); 
  meuservo2.write(angulo2); 

  Serial.print( " valor em x: " );
  Serial.print( x );
  Serial.print( "   valor em y: " );
  Serial.println( y );
  delay(100);
}






