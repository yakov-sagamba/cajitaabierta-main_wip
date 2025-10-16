#include <Arduino.h>


// Variables
int machine = 0;
int mappedmachine = 0;

void setup() {
  Serial.begin(115200); // Initialisation de la communication sérielle
}

void loop() {

    machine = analogRead(33);
    mappedmachine = map(machine, 0, 4095, 0 , 1);

    Serial.println(mappedmachine);

  delay(100);

}