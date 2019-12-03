#include <Stepper.h>

int numeroDePassosPorVolta = 2280;
int velocidade = 6;

Stepper lastro(numeroDePassosPorVolta, 8,9,10,11);

byte HOR[4] = {
  0x09,0x03,0x06,0x0C};    // Matriz dos bytes das Fases do Motor - sentido Horário Full Step
byte AHO[4] = {
  0x0C,0x06,0x03,0x09};    // Matriz dos bytes das Fases do Motor - sentido Anti-Horário Full Step
int atraso_fase = 2 ;                   // Intervalo de tempo entre as fases em milisegundos - min 2 para Full Step 
int intervalo = 1000 ;                  // Intervalo de tempo entre os movimentos do motor em ms

int passoAtual = 0;

// https://blog.eletrogate.com/guia-completo-do-motor-de-passo-28byj-48-driver-uln2003/

void umPassoPraFrente()
{
  for
}


void Motor_AHO()                    // Movimento no sentido anti-horário 
{
  for(int i = 0; i < 512; i++)      // incrementa o contador i de 0 a 511 - uma volta

    for(int j = 0; j < 4; j++)      // incrementa o contador j de 0 a 3 
    {
      PORTB = AHO[j];               // Carrega bytes da Matriz AHO na Porta B 
      delay (atraso_fase);          // Atraso de tempo entre as fases em milisegundos
    }    
}

void Motor_HOR()                    // Movimento no sentido horário 
{
  for(int i = 0; i < 512; i++)      // incrementa o contador i de 0 a 511 - uma volta

    for(int j = 0; j < 4; j++)      // incrementa o contador j de 0 a 3 
    {
      PORTB = HOR[j];               // Carrega bytes da Matriz HOR na Porta B 
      delay (atraso_fase);          // Atraso de tempo entre as fases em milisegundos
    }
}

void setup(){
  DDRB = 0x0F;           // Configura Portas D08,D09,D10 e D11 como saída 
  PORTB = 0x00;          // Reset dos bits da Porta B (D08 a D15) 

  lastro.setSpeed(velocidade);
  Serial.begin(9600);
}

bool primeiraVolta = true;

void loop(){  

  if( primeiraVolta ) {
    lastro.step( numeroDePassosPorVolta );
    primeiraVolta = false;
  }

  char letra = Serial.read();

  if( letra == '+' ) {
    numeroDePassosPorVolta += 10;
    Serial.print( "Aumentando o numero de passos para " );
    Serial.println( numeroDePassosPorVolta );
    lastro.step( 10 );
  }
  else if( letra == '-' ) {
    numeroDePassosPorVolta -= 10;
    Serial.print( "Reduzindo o numero de passos para " );
    Serial.println( numeroDePassosPorVolta );
    lastro.step( 10 );
  }
  //else if( letra == '1' ) {
  //  Serial.println( " Dando uma volta completa para testar " );
  //  lastro.step( numeroDePassosPorVolta );
  //}
  else if( letra == '3' ) {
    Serial.println( "  tras" );
    lastro.step( -numeroDePassosPorVolta );
  }
  else if( letra == '5' ) {
    Serial.println( "  frente" );
    lastro.step( numeroDePassosPorVolta );
  }
  else if( letra == 'G' ) {
    velocidade++;
    Serial.print( "Acelerando para " );
    Serial.println( velocidade );
    lastro.setSpeed(velocidade);
    lastro.step( numeroDePassosPorVolta );
  }
  else if( letra == 'S' ) {
    velocidade--;
    Serial.print( "desacelerando para " );
    Serial.println( velocidade );
    lastro.setSpeed(velocidade);
    lastro.step( numeroDePassosPorVolta );
  }
  else {
  }

  delay(100);
}









