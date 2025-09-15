#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <image.h>

// Exercice 1 : Prenez une image noir et blanc de 100 x 64 pixels maximum et transformez la en 'bmp' avec cet outil 
// en ligne https://projedefteri.com/en/tools/lcd-assistant/ (ou un autre convertisseur d'image)
// Exercice 2 : Déplacez l'image
// Exercice 3 : Ajoutez un décompte et des lignes

///////// ÉCRAN ////////
#define SCREEN_WIDTH 128 // Largeur de l'écran OLED, en pixels
#define SCREEN_HEIGHT 64 // Hauteur de l'écran OLED, en pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int pot1 = 0;
int pot2 = 0;
int myStateMachine = 1;
int pot1x = 0;
int pot2x = 0;

void setup() {
  ///////////// ÉCRAN /////////////  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Le code va s'arrêter ici si l'écran n'est pas reconnu
  }
  
  display.clearDisplay();
  display.setTextSize(1);           
  display.setTextColor(1);        
  display.setCursor(0, 0); // Coordonnées d'affichage du texte
  display.print(F("0.1.3 Ecran image")); // Affiche le message entre guillemets
  display.display();
  delay(2000); // Pause de 2 secondes
}

void loop() {
  display.clearDisplay();
  pot1x = map(pot1, 0, 4095, 0, 128);
  pot2x = map(pot2, 0, 4095, 0, 64);
  pot1 = analogRead(25);
  pot2 = analogRead(26);
  display.setCursor(30,10);
  display.printf("pot1x: ");
  display.setCursor(30,50);
  display.printf("pot2x: "); // Example pour Adafruit GFX
  display.display();
  delay(50);
}
