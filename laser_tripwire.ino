int ldrPin = A0;     // LDR analog input
int greenLed = 8;    // Green LED
int redLed = 7;      // Red LED
int buzzer = 6;     // Active LOW buzzer

int threshold = 900; // Adjust based on your LDR readings

void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  // Turn OFF buzzer initially
  digitalWrite(buzzer, HIGH);     // IMPORTANT for active buzzer

  Serial.begin(9600);
  Serial.println("System Started"); 
}

void loop() {

  int ldrValue = analogRead(ldrPin);

  if (ldrValue < threshold) {
    // Laser NOT detected → Alarm
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
    digitalWrite(buzzer, HIGH);   // BUZZER ONN
    Serial.println("⚠ Laser NOT Detected → RED ON (ALARM)"); 
    
    tone(buzzer, 600);
    delay(1200);                 // buzzer ON for 1.2 sec
    noTone(buzzer);

    digitalWrite(buzzer, LOW);  // buzzer OFF
    digitalWrite(redLed, LOW);   // red OFF
    digitalWrite(greenLed, HIGH);// green ON
    } 
  else {
    // Laser detected → Safe
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzer, LOW);    // BUZZER OFF
    Serial.println("Laser Detected → GREEN ON");
   
  }
}