
// DICE
// for M5StickC
// PRESS TOP BUTTON TO ROLL
// SCREEN OFF AFTER 15 SECONDS TO SAVE BATTERY
// WAKES WHEN MOVED

#include <M5StickC.h>
#define btnTop 37

bool dnum = 0;
uint8_t d1,d2;
unsigned long lastSleepTime;
// sleep after 15 seconds
int sleepInterval = 15000;
bool sleepMode = 0;

void setup() {
  M5.MPU6886.Init();
  M5.begin();
  M5.Lcd.setRotation(1);
  M5.Lcd.fillScreen(BLACK);

  // RECTANGLE x,y,w,h,colour
  M5.Lcd.drawRect(5, 5, 70, 70, WHITE);
  M5.Lcd.drawRect(85, 5, 70, 70, WHITE);
  
  // CIRCLE x,y,size,colour
  // D1
  M5.Lcd.fillCircle(20, 20, 7, TFT_GREEN);
  M5.Lcd.fillCircle(20, 60, 7, TFT_GREEN);
  M5.Lcd.fillCircle(60, 20, 7, TFT_GREEN);
  M5.Lcd.fillCircle(60, 60, 7, TFT_GREEN);
  // D2
  M5.Lcd.fillCircle(100, 20, 7, TFT_GREEN);
  M5.Lcd.fillCircle(100, 60, 7, TFT_GREEN);
  M5.Lcd.fillCircle(140, 20, 7, TFT_GREEN);
  M5.Lcd.fillCircle(140, 60, 7, TFT_GREEN);
  // STARTUP SCREEN
  M5.Lcd.setTextSize(3);
  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.setCursor(20, 30);
  M5.Lcd.print("D I C E");
}

void loop() {

  
  if (!sleepMode) {
    // SLEEP TIMER
    if (millis() - lastSleepTime > sleepInterval) {
      sleepMode = true;
      // turn screen off
      M5.Axp.ScreenBreath(0);
    } else {
      // BUTTON PRESS TO ROLL
      if (digitalRead(btnTop) == LOW) {
        // reset sleep timer before roll
        // so doesent go to sleep during roll
        lastSleepTime = millis();
        doRoll();
        // reset sleep timer after roll
        lastSleepTime = millis();
      }
      // keep it random
      d1 = random(1, 7);
      d2 = random(1, 7);
    }
  } else {
    // test for movement
    float gyroX_f, gyroY_f, gyroZ_f;
    M5.MPU6886.getGyroData(&gyroX_f, &gyroY_f,&gyroZ_f); 
    if (gyroX_f > 20) {
      // WAKE
      // turn screen ON
      M5.Axp.ScreenBreath(15);
      sleepMode = false;
      lastSleepTime = millis();
    }
  }
  
}

void doRoll() {
  // 4 to 6 seconds
  int rollTime = random(3000, 6000);
  unsigned long startTime = millis();
  int delayTime = 100;
  while (millis() < startTime + rollTime) {
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.drawRect(5, 5, 70, 70, RED);
    M5.Lcd.drawRect(85, 5, 70, 70, RED);
    d1 = random(1, 7);
    d2 = random(1, 7);
    doDisplay(d1); 
    dnum = !dnum;
    doDisplay(d2); 
    delay(delayTime);
    delayTime += 10;
  }
  M5.Lcd.drawRect(5, 5, 70, 70, WHITE);
  M5.Lcd.drawRect(85, 5, 70, 70, WHITE);
}

void doDisplay(int v) {
  switch (v) {
    case 1:
      if (!dnum) {
      // D1
      M5.Lcd.fillCircle(40, 40, 7, TFT_GREEN); 
      } else {
      // D2
      M5.Lcd.fillCircle(120, 40, 7, TFT_GREEN);
      }
      break;
    case 2:
      if (!dnum) {
      // D1
      M5.Lcd.fillCircle(20, 20, 7, TFT_GREEN);
      M5.Lcd.fillCircle(60, 60, 7, TFT_GREEN);
      } else {
      // D2
      M5.Lcd.fillCircle(100, 20, 7, TFT_GREEN);
      M5.Lcd.fillCircle(140, 60, 7, TFT_GREEN);
      }
      break;
    case 3:
      if (!dnum) {
      // D1
      M5.Lcd.fillCircle(20, 20, 7, TFT_GREEN);
      M5.Lcd.fillCircle(40, 40, 7, TFT_GREEN); 
      M5.Lcd.fillCircle(60, 60, 7, TFT_GREEN);
      } else {
      // D2
      M5.Lcd.fillCircle(100, 20, 7, TFT_GREEN);
      M5.Lcd.fillCircle(120, 40, 7, TFT_GREEN);
      M5.Lcd.fillCircle(140, 60, 7, TFT_GREEN);
      }
      break;
    case 4:
      if (!dnum) {
      // D1
      M5.Lcd.fillCircle(20, 20, 7, TFT_GREEN);
      M5.Lcd.fillCircle(20, 60, 7, TFT_GREEN);
      M5.Lcd.fillCircle(60, 20, 7, TFT_GREEN);
      M5.Lcd.fillCircle(60, 60, 7, TFT_GREEN);
      } else {
      // D2
      M5.Lcd.fillCircle(100, 20, 7, TFT_GREEN);
      M5.Lcd.fillCircle(100, 60, 7, TFT_GREEN);
      M5.Lcd.fillCircle(140, 20, 7, TFT_GREEN);
      M5.Lcd.fillCircle(140, 60, 7, TFT_GREEN);
      }
      break;
    case 5:
      if (!dnum) {
      // D1
      M5.Lcd.fillCircle(20, 20, 7, TFT_GREEN);
      M5.Lcd.fillCircle(20, 60, 7, TFT_GREEN);
      M5.Lcd.fillCircle(40, 40, 7, TFT_GREEN); 
      M5.Lcd.fillCircle(60, 20, 7, TFT_GREEN);
      M5.Lcd.fillCircle(60, 60, 7, TFT_GREEN);
      } else {
      // D2
      M5.Lcd.fillCircle(100, 20, 7, TFT_GREEN);
      M5.Lcd.fillCircle(100, 60, 7, TFT_GREEN);
      M5.Lcd.fillCircle(120, 40, 7, TFT_GREEN); 
      M5.Lcd.fillCircle(140, 20, 7, TFT_GREEN);
      M5.Lcd.fillCircle(140, 60, 7, TFT_GREEN);
      }
      break;
    case 6:
      if (!dnum) {
      // D1
      M5.Lcd.fillCircle(20, 20, 7, TFT_GREEN);
      M5.Lcd.fillCircle(20, 40, 7, TFT_GREEN);
      M5.Lcd.fillCircle(20, 60, 7, TFT_GREEN);
      M5.Lcd.fillCircle(60, 20, 7, TFT_GREEN);
      M5.Lcd.fillCircle(60, 40, 7, TFT_GREEN);
      M5.Lcd.fillCircle(60, 60, 7, TFT_GREEN);
      } else {
      // D2
      M5.Lcd.fillCircle(100, 20, 7, TFT_GREEN);
      M5.Lcd.fillCircle(100, 40, 7, TFT_GREEN);
      M5.Lcd.fillCircle(100, 60, 7, TFT_GREEN);
      M5.Lcd.fillCircle(140, 20, 7, TFT_GREEN);
      M5.Lcd.fillCircle(140, 40, 7, TFT_GREEN);
      M5.Lcd.fillCircle(140, 60, 7, TFT_GREEN);
      }
      break;
  }
}

