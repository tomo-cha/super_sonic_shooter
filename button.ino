//Button
void buttonAction() {
  if (isShooting == true) {
    M5.Lcd.fillRect(180, 130, 100, 100, 0x0000);
    sendPulse();
    trig();
    bulletNumber -= 1;
  } else {
    stopPulse();
  }
}

void readButtonVal() {
  isShooting = false; //単発モード
  int buttonState = digitalRead(buttonPin);
  if (lastButtonState == HIGH && buttonState == LOW) {
    int now = millis();
    if ( (now - lastDebounceTime) > debounceDelay ) {
      onPress();
    }
    lastDebounceTime = now;
  }
  //  else{ //連射モード
  //    isShooting = false;
  //    lastButtonState = buttonState;
  //  }
  lastButtonState = buttonState; //単発モード
}

void onPress() {
  isShooting = true;
}
