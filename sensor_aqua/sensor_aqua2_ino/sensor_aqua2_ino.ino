const int analogInPin = A0; 
 
long int sensorValue = 0;
 
void setup() {
 Serial.begin(9600); 
}
 
void loop() {
 sensorValue = analogRead(analogInPin); 
 
 Serial.print("Sensor = " ); 
 Serial.print(sensorValue*100/1024); 
 Serial.println("%");
 Serial.println(sensorValue*100); 
 delay(1000); 
}
