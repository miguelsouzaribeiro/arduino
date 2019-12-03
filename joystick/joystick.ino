#include <Servo.h> //inclui blibioteca
Servo meuservo1; //
Servo meuservo2; //
const int portaW = 8;
const int portaX = A1;//
const int portaY = A0;//
const int portaPWMmotor1 = 9;
const int portaPWMmotor2 = 10;

void setup(){
  Serial.begin(9600);//
  meuservo1.attach(portaPWMmotor1);//
  meuservo2.attach(portaPWMmotor2);//

}

void loop(){
  int w = digitalRead(portaW);
  int x = analogRead(portaX);//
  int y = analogRead(portaY);//
  int angulo1 = map(x, 0, 1023, 1, 180);//
  int angulo2 = map(y, 0, 1023, 1, 180);//

  meuservo1.write(angulo1); //
  meuservo2.write(angulo2); //

  Serial.print( " valor em x: " );//
  Serial.print( x );//
  Serial.print( "   valor em y: " );//
  Serial.print( y );
  Serial.print( "   botao: " );//
  Serial.println( w );

  delay(100);
}






