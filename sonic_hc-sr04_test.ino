int buttonPin = 2;
int trigPin = 8;
int echoPin = A0;
int ledPin = 12;
int lastStatus = 0;
int buttonStatus = 0;


void setup(){
  pinMode(buttonPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  int sonicVal = analogRead(echoPin);
  Serial.print("sonicVal:");
  Serial.println(sonicVal);
  int count = 0;
  buttonStatus = digitalRead(buttonPin);
  if(buttonStatus == LOW){
    count += 1;
    delay(100);
  }
  
  if(count >= 1){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    count -= 1;
  }
  int duration = pulseIn(echoPin, HIGH);
    Serial.print("duration:");
    Serial.println(duration);
    
    int check = 0;
  if (0 < duration && duration <= 1000){
    check += 1;
    delay(100);
  }
  Serial.print("check:");
  Serial.println(check);
  if(check >= 1){
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
    check -= 1;
    delay(100);
  }
  delay(500);
}
