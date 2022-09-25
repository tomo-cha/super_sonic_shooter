#include <M5Stack.h>
#include <WiFi.h>
#include "AudioFileSourceSD.h"
#include "AudioFileSourceID3.h"
#include "AudioGeneratorMP3.h"
#include "AudioOutputI2S.h"

// sound
AudioGeneratorMP3 *mp3;
AudioFileSourceSD *file;
AudioOutputI2S *out;
AudioFileSourceID3 *id3;


//pin
int buttonPin = 16;
int trigPin = 17;
int echoPin = 35;
int ledPin = 3;
const int EMS_PIN = 5;

//button
int lastStatus = 0;
int buttonStatus = 0;
boolean isShooting = false;
int lastButtonState = LOW;
long lastDebounceTime = 0;
long debounceDelay = 3;

// echoSmoothing
const int numReadings = 5;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

// display
int hp = 4;
int setBulletNumber = 6;
int bulletNumber = setBulletNumber;


// display condition
int count = 0;

//setup
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(EMS_PIN, OUTPUT);

  M5.begin();
  WiFi.mode(WIFI_OFF);
  M5.Speaker.setVolume(1);
  M5.Lcd.setBrightness(200);
}

//loop
void loop() {
  M5.update();
digitalWrite(ledPin, LOW);
  if (M5.BtnA.wasReleased() || M5.BtnA.pressedFor(500)) {
    count += 1;
  }

  if (count == 0) { // sleep condition
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.printf("please push A button");
  }

  if (count == 1) { // loading
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.printf("setup completed...");
    playMP3("/opening4/Cyber11-1.mp3");
    playMP3("/loading1.mp3");
    for(int i=0; i<2; i++){
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.printf("setup completed.");
    delay(300);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.printf("setup completed..");
    delay(300);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.printf("setup completed...");
    delay(300);
    }
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setTextColor(BLUE);
    reload();
    count += 1; //自動的に画面が切り替わる
  }

  if (count > 1) { // setup all green & game start
    
    for (int i = 0; i < numReadings; i++) {
      echoSmoothing(analogRead(echoPin));
    }
    average = total / numReadings;
    if (average > 700) { // attacked
      digitalWrite(ledPin, HIGH);
      hp -= 1;
      sendShock();
    }
    digitalWrite(ledPin, LOW);
    //button status
    readButtonVal();
    buttonAction();

    
    drawBullet();//bulet
    drawBulletNumber();// bulletnumber
    drawHP();//HP
  }
}
