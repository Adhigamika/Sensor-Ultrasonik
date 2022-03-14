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
  float luas_alas    = 38.5;                      
  float tinggi_gelas = 10.64;                     
  float volume, tinggi_air,jarak_pantul;          
  
  digitalWrite(trig_pin, HIGH);      
  delayMicroseconds(10);             
  digitalWrite(trig_pin, LOW);       
  echotime= pulseIn(echo_pin, HIGH); 
  
  jarak_pantul = (0.034*(float)echotime)/2;   
  tinggi_air   = tinggi_gelas - jarak_pantul; 
  volume       = luas_alas*tinggi_air;        
  
  Serial.print("Jarak Permukaan = ");         
  Serial.print(jarak_pantul);
  Serial.println(" cm");
  Serial.print("Tinggi_air      = ");
  Serial.print(tinggi_air);
  Serial.println(" cm");
  Serial.print("Volume          = ");
  Serial.print(volume);
  Serial.println(" cm3");
  Serial.println("=========================");
  
  delay (2000); 
}
