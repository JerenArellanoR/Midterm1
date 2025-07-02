/* 
 * Project: DYNOMOTOR
 * Author: Jeren A Reeder
 * Date: 6/30/25
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "Button.h"
const int OLED_RESET=-1;
Adafruit_SSD1306 display(OLED_RESET);

SYSTEM_MODE(SEMI_AUTOMATIC);
char number = 164;
SYSTEM_THREAD(ENABLED);
SerialLogHandler logHandler(LOG_LEVEL_INFO);

const int hallPin = D13;

Button hallSensor(hallPin,true);

const int ROTATIONS = 20;
int inputValue; 
int prevState = HIGH;
int rotationCount = 0;
int lastSecond = 0;
int lastRotationTime = 0;
int count = 0;
int startTime;
int endTime;
int RPM;
int RPS;

void setup() {
  Serial.begin(9600);
  waitFor(Serial.isConnected, 5000);
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  //pinMode(hallPin, INPUT);
}
void loop() {

  Serial.printf("MagnetState=%i\n",inputValue);
  Serial.printf("RPS: %d\n", RPS);

rotationCount = 0;
startTime = micros();

  while ( rotationCount < ROTATIONS) {
    if (hallSensor.isClicked()) {
      rotationCount++;
      Serial.printf(".");
    }
 
    endTime= micros();
    RPS = (ROTATIONS/((endTime-startTime)/1000000.0));
    RPM = (ROTATIONS/((endTime-startTime)/1000000.0)) * 60;
  }

  {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(1,1);
  display.printf("RPS: %d\nRPM: %d\n", RPS, RPM);
  display.display();
}

  }

  


