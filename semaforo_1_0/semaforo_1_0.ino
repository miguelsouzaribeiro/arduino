// ==================================================================
// Projeto: Semaforo
// Autor: Miguel Ribeiro
// ==================================================================

//      |   | |
//      |   v |
//      |   C |
// -----+     +----
//  <--D
//             B-->
// -----+     +----
//      | A   |
// :::: |     |
//

int pino_vermelho_a = 13;
int pino_amarelo_a  = 12;
int pino_verde_a    = 11;

int pino_vermelho_b = 10;
int pino_amarelo_b  = 8; // fio trocado com B verde
int pino_verde_b    = 9; // fio trocado com B amarelo

int pino_vermelho_c = 7;
int pino_amarelo_c  = 6;
int pino_verde_c    = 5;

int pino_vermelho_d = 4;
int pino_amarelo_d  = 3;
int pino_verde_d    = 2;

// Tempo para cada cor permanecer acesa
int tempo_vermelho = 3000; // milisegundos
int tempo_amarelo  = 2000; // milisegundos
int tempo_verde    = 3000; // milisegundos

// ----------------------------------------------------------------------
// Inicialização
// ----------------------------------------------------------------------
void setup()
{
  pinMode( pino_vermelho_a, OUTPUT );
  pinMode( pino_amarelo_a, OUTPUT );
  pinMode( pino_verde_a, OUTPUT );

  pinMode( pino_vermelho_b, OUTPUT );
  pinMode( pino_amarelo_b, OUTPUT );
  pinMode( pino_verde_b, OUTPUT );

  pinMode( pino_vermelho_c, OUTPUT );
  pinMode( pino_amarelo_c, OUTPUT );
  pinMode( pino_verde_c, OUTPUT );

  pinMode( pino_vermelho_d, OUTPUT );
  pinMode( pino_amarelo_d, OUTPUT );
  pinMode( pino_verde_d, OUTPUT );
}

// ----------------------------------------------------------------------
// Funcao para verificacao de um pino
// ----------------------------------------------------------------------
void teste_pisca_led( int pino )
{
  digitalWrite( pino, HIGH );
  delay( 100 );
  digitalWrite( pino, LOW );
  delay( 100 );
}

// ----------------------------------------------------------------------
// Funcao para verificacao de todos os pinos
// ----------------------------------------------------------------------
void teste_pisca_todos_os_leds()
{
  teste_pisca_led( pino_vermelho_a );
  teste_pisca_led( pino_vermelho_b );
  teste_pisca_led( pino_vermelho_c );
  teste_pisca_led( pino_vermelho_d );

  teste_pisca_led( pino_amarelo_a );
  teste_pisca_led( pino_amarelo_b );
  teste_pisca_led( pino_amarelo_c );
  teste_pisca_led( pino_amarelo_d );

  teste_pisca_led( pino_verde_a );
  teste_pisca_led( pino_verde_b );
  teste_pisca_led( pino_verde_c );
  teste_pisca_led( pino_verde_d );
}

// ----------------------------------------------------------------------
//
// ----------------------------------------------------------------------
void set_semaforo_a( bool estado_vermelho, bool estado_amarelo, bool estado_verde )
{
  digitalWrite( pino_vermelho_a, estado_vermelho );
  digitalWrite( pino_amarelo_a, estado_amarelo );
  digitalWrite( pino_verde_a, estado_verde );
}

// ----------------------------------------------------------------------
//
// ----------------------------------------------------------------------
void set_semaforo_b( bool estado_vermelho, bool estado_amarelo, bool estado_verde )
{
  digitalWrite( pino_vermelho_b, estado_vermelho );
  digitalWrite( pino_amarelo_b, estado_amarelo );
  digitalWrite( pino_verde_b, estado_verde );
}

// ----------------------------------------------------------------------
//
// ----------------------------------------------------------------------
void set_semaforo_c( bool estado_vermelho, bool estado_amarelo, bool estado_verde )
{
  digitalWrite( pino_vermelho_c, estado_vermelho );
  digitalWrite( pino_amarelo_c, estado_amarelo );
  digitalWrite( pino_verde_c, estado_verde );
}

// ----------------------------------------------------------------------
//
// ----------------------------------------------------------------------
void set_semaforo_d( bool estado_vermelho, bool estado_amarelo, bool estado_verde )
{
  digitalWrite( pino_vermelho_d, estado_vermelho );
  digitalWrite( pino_amarelo_d, estado_amarelo );
  digitalWrite( pino_verde_d, estado_verde );
}

// ----------------------------------------------------------------------
//
// ----------------------------------------------------------------------
void modo_amarelo_piscante()
{
  set_semaforo_a( LOW, HIGH, LOW );
  set_semaforo_b( LOW, HIGH, LOW );
  set_semaforo_c( LOW, HIGH, LOW );
  set_semaforo_d( LOW, HIGH, LOW );
  delay( 1000 );
  set_semaforo_a( LOW, LOW, LOW );
  set_semaforo_b( LOW, LOW, LOW );
  set_semaforo_c( LOW, LOW, LOW );
  set_semaforo_d( LOW, LOW, LOW );
  delay( 1000 );
}

// ----------------------------------------------------------------------
//
// ----------------------------------------------------------------------
void modo_normal()
{  
  set_semaforo_a( HIGH, LOW, LOW );
  set_semaforo_c( HIGH, LOW, LOW );
  set_semaforo_b( LOW, LOW, HIGH );
  set_semaforo_d( LOW, LOW, HIGH );
  delay( tempo_vermelho );
  
  set_semaforo_b( LOW, HIGH, LOW );
  set_semaforo_d( LOW, HIGH, LOW );
  delay( tempo_amarelo );

  set_semaforo_b( HIGH, LOW, LOW );
  set_semaforo_d( HIGH, LOW, LOW );
  set_semaforo_a( LOW, LOW, HIGH );
  set_semaforo_c( LOW, LOW, HIGH );
  delay( tempo_verde );
  
  set_semaforo_a( LOW, HIGH, LOW );
  set_semaforo_c( LOW, HIGH, LOW );
  delay( tempo_amarelo );

  set_semaforo_a( HIGH, LOW, LOW );
  set_semaforo_c( HIGH, LOW, LOW );
  set_semaforo_b( LOW, LOW, HIGH );
  set_semaforo_d( LOW, LOW, HIGH );
  delay( tempo_verde );
}

// ----------------------------------------------------------------------
//
// ----------------------------------------------------------------------
void loop()
{
  //teste_pisca_todos_os_leds();
  //modo_amarelo_piscante();
  modo_normal();
}
