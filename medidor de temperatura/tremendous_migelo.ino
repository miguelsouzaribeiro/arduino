#include <LiquidCrystal.h>

int pinoDoSensor = A0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte grau[8] ={
  
  B00001100,  //       _
  B00010010,  //      | |
  B00010010,  //      |_|
  B00001100,  //       
  B00000000,  //      
  B00000000,  //      
  B00000000,  //      
  B00000000,  //      
};


float temperatura = 0.0;
float sensibilidade = 0.010; // mV / C
 
void setup() 
{ 
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.createChar( 0, grau );
}

void loop() 
{
  lcd.clear();
  //lcd.setCursor(0, 0);
  //lcd.print("Ola LCD");
  temperatura = analogRead( A0 ) * 5.0 / 1024.0 / sensibilidade;
    
  float mV_por_divisao = 5.00 / 1024.00;
  int saida_do_ad      = analogRead( pinoDoSensor );

  float temperatura = saida_do_ad * mV_por_divisao / 0.010;
  Serial.print( temperatura );
  Serial.println(" C");
  
  Serial.print("Temperatura - ");  //Send a text to serial
  Serial.print( temperatura ); 
  Serial.println(" C  - ");
  lcd.print("Temp ");
  lcd.print( temperatura );
  lcd.write( (byte)0 );
  lcd.print( "C" );
  delay(1000);
  
}
