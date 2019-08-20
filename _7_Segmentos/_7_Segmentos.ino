#define pinBotao 2

#define pinA 10
#define pinB 9
#define pinC 6
#define pinD 7
#define pinE 8
#define pinF 11
#define pinG 12 // Era 12
#define pinPD 5

int numero = 10;

boolean botaoAnt = false;
boolean botaoAtu = false;

void setup() {
  Serial.begin(9600);
  pinMode(pinBotao,INPUT);
  //pinMode(12,OUTPUT);
}

void loop() {
  delay( 1000 );

  /* TESTE UNITARIO
   digitalWrite(pinA,HIGH);
   digitalWrite(pinF,HIGH);
   digitalWrite(pinE,HIGH);
   digitalWrite(pinD,HIGH);
   digitalWrite(pinC,HIGH);
   digitalWrite(pinB,HIGH);
   digitalWrite(pinG,LOW);
   digitalWrite(pinPD,HIGH);
   return;
   */

  /*
  botaoAtu = digitalRead(pinBotao);
  
  if (botaoAtu && !botaoAnt) 
  {
    ++numero;

    if (numero > 9)
    {
      numero = 0;
    }
    Serial.println( "Botao apertado" );
    Serial.println( numero );
  }
  botaoAnt = botaoAtu;
  */

  ++numero;

  switch (numero % 10)
  {
  case 0:
    digitalWrite(pinA,HIGH);
    digitalWrite(pinF,HIGH);
    digitalWrite(pinE,HIGH);
    digitalWrite(pinD,HIGH);
    digitalWrite(pinC,HIGH);
    digitalWrite(pinB,HIGH);
    digitalWrite(pinG,LOW);
    digitalWrite(pinPD,LOW); 
    break;
  case 1:
    digitalWrite(pinA,LOW);
    digitalWrite(pinF,LOW);
    digitalWrite(pinE,LOW);
    digitalWrite(pinD,LOW);
    digitalWrite(pinC,HIGH);
    digitalWrite(pinB,HIGH);
    digitalWrite(pinG,LOW);
    digitalWrite(pinPD,LOW); 
    break;
  case 2:
    digitalWrite(pinA,HIGH);
    digitalWrite(pinF,LOW);
    digitalWrite(pinE,HIGH);
    digitalWrite(pinD,HIGH);
    digitalWrite(pinC,LOW);
    digitalWrite(pinB,HIGH);
    digitalWrite(pinG,HIGH);
    digitalWrite(pinPD,LOW); 
    break;
  case 3:
    digitalWrite(pinA,HIGH);
    digitalWrite(pinF,LOW);
    digitalWrite(pinE,LOW);
    digitalWrite(pinD,HIGH);
    digitalWrite(pinC,HIGH);
    digitalWrite(pinB,HIGH);
    digitalWrite(pinG,HIGH);
    digitalWrite(pinPD,LOW); 
    break;
  case 4:
    digitalWrite(pinA,LOW);
    digitalWrite(pinF,HIGH);
    digitalWrite(pinE,LOW);
    digitalWrite(pinD,LOW);
    digitalWrite(pinC,HIGH);
    digitalWrite(pinB,HIGH);
    digitalWrite(pinG,HIGH);
    digitalWrite(pinPD,LOW); 
    break;
  case 5:
    digitalWrite(pinA,HIGH);
    digitalWrite(pinF,HIGH);
    digitalWrite(pinE,LOW);
    digitalWrite(pinD,HIGH);
    digitalWrite(pinC,HIGH);
    digitalWrite(pinB,LOW);
    digitalWrite(pinG,HIGH);
    digitalWrite(pinPD,LOW); 
    break;
  case 6:
    digitalWrite(pinA,HIGH);
    digitalWrite(pinF,HIGH);
    digitalWrite(pinE,HIGH);
    digitalWrite(pinD,HIGH);
    digitalWrite(pinC,HIGH);
    digitalWrite(pinB,LOW);
    digitalWrite(pinG,HIGH);
    digitalWrite(pinPD,LOW); 
    break;
  case 7:
    digitalWrite(pinA,HIGH);
    digitalWrite(pinF,LOW);
    digitalWrite(pinE,LOW);
    digitalWrite(pinD,LOW);
    digitalWrite(pinC,HIGH);
    digitalWrite(pinB,HIGH);
    digitalWrite(pinG,LOW);
    digitalWrite(pinPD,LOW); 
    break;
  case 8:
    digitalWrite(pinA,HIGH);
    digitalWrite(pinF,HIGH);
    digitalWrite(pinE,HIGH);
    digitalWrite(pinD,HIGH);
    digitalWrite(pinC,HIGH);
    digitalWrite(pinB,HIGH);
    digitalWrite(pinG,HIGH);
    digitalWrite(pinPD,LOW); 
    break;
  case 9:
    digitalWrite(pinA,HIGH);
    digitalWrite(pinF,HIGH);
    digitalWrite(pinE,LOW);
    digitalWrite(pinD,HIGH);
    digitalWrite(pinC,HIGH);
    digitalWrite(pinB,HIGH);
    digitalWrite(pinG,HIGH);
    digitalWrite(pinPD,LOW); 
    break;
  default:
    digitalWrite(pinA,LOW);
    digitalWrite(pinF,LOW);
    digitalWrite(pinE,LOW);
    digitalWrite(pinD,LOW);
    digitalWrite(pinC,LOW);
    digitalWrite(pinB,LOW);
    digitalWrite(pinG,LOW);
    digitalWrite(pinPD,HIGH); 
    break;
  }
}



