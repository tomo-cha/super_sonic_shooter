// ems

void sendShock() {//被弾時反動
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(EMS_PIN, HIGH);
    delay(10);
    digitalWrite(EMS_PIN, LOW);
    delay(50);
    digitalWrite(EMS_PIN, HIGH);
    delay(10);
    digitalWrite(ledPin, LOW);
    digitalWrite(EMS_PIN, LOW);
    delay(50);
  }
  playMP3("/damage1.mp3");
}


void sendPulse() { //射撃時反動
  digitalWrite(ledPin, HIGH);
  playMP3("/sendSonic2.mp3");
  digitalWrite(EMS_PIN, HIGH);
  delay(1);
  digitalWrite(EMS_PIN, LOW);
  delay(140);
  digitalWrite(EMS_PIN, HIGH);
  delay(1);
  digitalWrite(EMS_PIN, LOW);
  delay(140);

  digitalWrite(ledPin, LOW);
}

void stopPulse() { //反動おわり
  digitalWrite(EMS_PIN, LOW);
}
