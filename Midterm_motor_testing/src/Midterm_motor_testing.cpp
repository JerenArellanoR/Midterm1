/* 
 * Project: DYNOMOTOR
 * Author: Jeren A Reeder
 * Date: 6/30/25
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"




SYSTEM_MODE(SEMI_AUTOMATIC);
SYSTEM_THREAD(ENABLED);



SerialLogHandler logHandler(LOG_LEVEL_INFO);

const int buttonPin = D13;

int inputValue; 
void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);

  }


void loop() {
  inputValue = digitalRead(buttonPin);
  Serial.printf("MagnetState=%i\n",inputValue);
   (inputValue == LOW); {
    digitalWrite(buttonPin, HIGH);
    digitalWrite(buttonPin, LOW);

  }
}
