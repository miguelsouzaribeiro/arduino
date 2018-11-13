#include <Wire.h>
#include <LiquidCrystal_I2C.h>

uint8_t endereco_i2c_do_lcd = 0x27;
uint8_t En = 2;
uint8_t Rw = 1;
uint8_t Rs = 0;
uint8_t d4 = 4;
uint8_t d5 = 5;
uint8_t d6 = 6;
uint8_t d7 = 7;
uint8_t backlighPin = 3;
t_backlighPol backlighPol = POSITIVE;
  
LiquidCrystal_I2C lcd( endereco_i2c_do_lcd, En, Rw, Rs, d4, d5, d6, d7, backlighPin, backlighPol );
//LiquidCrystal_I2C lcd( 0x27, 2, 1, 0, 4 ,5, 6 ,7, 3, POSITIVE );

int um_segundo = 1000;
int contador = 0;

void setup()
{
  lcd.begin( 16, 2, LCD_5x8DOTS );
  Serial.begin(9600);
}

void loop()
{
  lcd.clear();
  lcd.setBacklight(HIGH);
  lcd.setCursor(0, 0);
  lcd.print("Vou servir cafe");
  lcd.setCursor(0, 1);
  lcd.print("Para o senhor ja");
  delay(um_segundo);
  //lcd.setBacklight(LOW);
  delay(um_segundo);
  Serial.println(++contador);
}

