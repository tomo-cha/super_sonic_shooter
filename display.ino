//display

//reload
void reload() {
  M5.Lcd.fillRect(20, 130, 300, 100, 0x0000);
  for (int b = 0; b < bulletNumber; b++) {
    M5.Lcd.fillRect(20 + b * 26, 150, 16, 60, BLUE);
    M5.Lcd.fillTriangle(28 + b * 26, 130, 20 + b * 26, 150, 36 + b * 26, 150, YELLOW);
    M5.Lcd.setTextSize(2);
    M5.Lcd.drawString(String(b), 180, 130, 7);
    delay(150);
    M5.Lcd.fillRect(180, 130, 100, 100, 0x0000);
  }
}
void drawBullet() {
  //setBulletNumberの値によって変更する。
  if (bulletNumber == 5) {
    M5.Lcd.fillRect(20 + (setBulletNumber - 1) * 26, 130, 20, 80, BLACK);
  }
  if (bulletNumber == 4) {
    M5.Lcd.fillRect(20 + (setBulletNumber - 2) * 26, 130, 20, 80, BLACK);
  }
  if (bulletNumber == 3) {
    M5.Lcd.fillRect(20 + (setBulletNumber - 3) * 26, 130, 20, 80, BLACK);
  }
  if (bulletNumber == 2) {
    M5.Lcd.fillRect(20 + (setBulletNumber - 4) * 26, 130, 20, 80, BLACK);
  }
  if (bulletNumber == 1) {
    M5.Lcd.fillRect(20 + (setBulletNumber - 5) * 26, 130, 20, 80, BLACK);
  }
  if (bulletNumber == 0) {
    M5.Lcd.fillRect(20 + (setBulletNumber - 6) * 26, 130, 20, 80, BLACK);
  }
}

void drawBulletNumber() {
  if (bulletNumber == 0 || M5.BtnC.wasReleased() || M5.BtnC.pressedFor(500)) {
    M5.Lcd.fillRect(180, 130, 100, 100, 0x0000);
    bulletNumber = setBulletNumber;
    reload();
  }
  M5.Lcd.setTextSize(2);
  M5.Lcd.drawString(String(bulletNumber), 180, 130, 7);
}

void drawHP() {
  if (hp == 4) {
    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.drawRect(10, 10, 300, 70, 0x001f);
    M5.Lcd.fillRect(20, 20, 280, 50, 0x07ff);
  }
  if (hp == 3) {
    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.fillRect(230, 20, 70, 50, 0x0000);
  }
  if (hp == 2) {
    M5.Lcd.setTextColor(0xffe0);
    M5.Lcd.drawRect(10, 10, 300, 70, 0xffe0);
    M5.Lcd.fillRect(20, 20, 140, 50, 0xffe0);
    M5.Lcd.fillRect(160, 20, 140, 50, 0x0000);
  }
  if (hp == 1) {
    M5.Lcd.setTextColor(0xf800);
    M5.Lcd.drawRect(10, 10, 300, 70, 0xf800);
    M5.Lcd.fillRect(20, 20, 70, 50, 0xf800);
    M5.Lcd.fillRect(90, 20, 210, 50, 0x0000);
  }
  if (hp == 0) {
    M5.Lcd.fillRect(20, 20, 280, 50, 0x0000);
    for (int i = 0; i < 3; i++) {
      M5.Lcd.fillScreen(RED);
      delay(100);
      M5.Lcd.fillScreen(BLACK);
      delay(100);
    }
    M5.Lcd.setCursor(50, 50);
    M5.Lcd.setTextColor(RED);
    M5.Lcd.setTextSize(4);
    M5.Lcd.printf("Game Over!");
    delay(5000);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.drawJpgFile(SD, "/nocopylight_mini.jpg");
    delay(1000);
    playMP3("/end2.mp3");
    delay(5000);
    hp = 4;
    bulletNumber = setBulletNumber;
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setTextSize(1);
    count = 0;
  }
}
