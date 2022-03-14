int trig_pin = 5;
int echo_pin = 4;
long echotime; 

void setup() {
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT); 
  pinMode(echo_pin, INPUT);
  digitalWrite(trig_pin, LOW);  
}

void loop() {
  float tinggi_gelas;
  
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  echotime= pulseIn(echo_pin, HIGH);
  
  tinggi_gelas = 0.0001*((float)echotime*340)/2;
  
  Serial.print("Tinggi gelas = ");
  Serial.print(tinggi_gelas);
  Serial.println(" cm");
  Serial.println("=========================");
  
  delay (2000);
 }
