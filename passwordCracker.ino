//UP and DOWN, hold for 3s
//UP or DOWN x times
//ENTER


// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int ledIn = 5;
int relay1 = 4;
int relay2 = 2;
int relay3 = 3;
int photo = A0;  //define a pin for Photo resistor
int start_count = 1000;
int finish_count = 9999;
int count_length = 8999;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(ledIn, OUTPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);    
  Serial.begin(9600);
}

void pressEnter() {
    digitalWrite(relay1, HIGH);
    delay(100);
    digitalWrite(relay1, LOW);
    delay(50);
}

void holdDown(int holdTime) {
    digitalWrite(relay2, HIGH); 
    Serial.println("Holding");
    delay(holdTime);
    digitalWrite(relay2, LOW);    
}

void pressUP() {
    digitalWrite(relay3, HIGH); 
     delay(90);
    digitalWrite(relay3, LOW); 
}

void pressDOWN() {
    digitalWrite(relay2, HIGH); 
     delay(90);
    digitalWrite(relay2, LOW); 
}

void enterConfig() {
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  delay(3500);
  digitalWrite(relay2, LOW); //release DOWN
  digitalWrite(relay3, LOW); //release UP
}

// the loop routine runs over and over again forever:
void loop() {
  for (int k = start_count; k <= finish_count; k++) {
  Serial.println(k);
  enterConfig();
  pressEnter();
  for (int i=0; i <= k-start_count; i++){
     pressUP();
     delay(50);
  }
   delay(100);
   pressEnter();   
  
  int phot = analogRead(photo);
  Serial.println("Photoresistor value: ");
  Serial.println(phot+1);
  if (phot > 300) {
    Serial.println("ON!");
    break;
    break;  
  }
}
while(1);
}


