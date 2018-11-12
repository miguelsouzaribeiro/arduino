
int pinoDoSensor = A0;

void setup() {
  Serial.begin(9600);
}


void loop() {
  
  float mV_por_divisao = 5.00 / 1024.00;
  int saida_do_ad = analogRead( pinoDoSensor );
  float temperatura = saida_do_ad * mV_por_divisao / 0.010;
  Serial.print( temperatura );
  Serial.println(" C");
}
