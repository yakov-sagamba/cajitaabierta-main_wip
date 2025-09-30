#include <Arduino.h>


// Variables
int machine = 0;

void setup() {
  Serial.begin(115200); // Initialisation de la communication sérielle
}

void loop() {

    machine = analogRead(33);

    Serial.print(">pot1:");Serial.println(machine);
    

  delay(100);

}