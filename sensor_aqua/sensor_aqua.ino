const int sensorPin= 0;
 
void setup(){
Serial.begin(9600);
pinMode(sensorPin,INPUT);

}

void loop(){

int liquid_level= analogRead(sensorPin);
Serial.println(liquid_level);
delay(100);
}
