int passoAtual = 0;
int tempoEntrePassos = 2;

const byte sentidoHora2Bobinas[4] = {
  B00001001,
  B00000011,
  B00000110,
  B00001100
};

const byte sentidoAntiHora2Bobinas[4] = {
  B00001100,
  B00000110,
  B00000011,
  B00001001
};

const byte sentidoHora1Bobina[4] = {
  B00000001,
  B00000010,
  B00000100,
  B00001000
};

const byte sentidoAntiHora1Bobina[4] = {
  B00001000,
  B00000100,
  B00000010,
  B00000001
};

void rodaHorario2Bobinas (int numeroDePassos) 
{
  for(int i = 0;i < numeroDePassos; i++)
  {
    PORTB = sentidoHora2Bobinas[ passoAtual % 4];
    passoAtual++;
    delay (tempoEntrePassos);  
  }

}

void rodaAntiHorario2Bobinas (int numeroDePassos) 
{
  for(int i = 0;i < numeroDePassos; i++)
  {
    PORTB = sentidoAntiHora2Bobinas[ passoAtual % 4];
    passoAtual++;
    delay (tempoEntrePassos);
  }

}

void rodaHorario1Bobina (int numeroDePassos) 
{
  for(int i = 0;i < numeroDePassos; i++)
  {
    PORTB = sentidoHora1Bobina[ passoAtual % 4];
    passoAtual++;
    delay (tempoEntrePassos);  
  }

}

void rodaAntiHorario1Bobina (int numeroDePassos) 
{
  for(int i = 0;i < numeroDePassos; i++)
  {
    PORTB = sentidoAntiHora1Bobina[ passoAtual % 4];
    passoAtual++;
    delay (tempoEntrePassos);
  }

}

void setup(){

  DDRB = 0x0F;           // Configura Portas D08,D09,D10 e D11 como saída 
  PORTB = 0x00;          // Reset dos bits da Porta B (D08 a D15) 

  Serial.begin(9600);


}

void loop(){

  rodaHorario1Bobina(512);
  delay (2000);
  rodaAntiHorario1Bobina(512);
  delay (2000);
}







