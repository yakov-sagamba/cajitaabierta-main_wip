#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Exercice 1 : Changez l'endroit ou le texte s'affiche 
// Exercice 2 : Trouvez comment changer la taille d'affichage du texte et inversez le mode d'affichage
// Exercice 3 : Faites déplacer le texte selon un axe, x ou y
// Exercice 4 : Faites interagir le texte avec les potentiometres ou le bouton

int pot1 = 0;
int pot2 = 0;

///////// ÉCRAN ////////
#define SCREEN_WIDTH 128 // Largeur de l'écran OLED, en pixels
#define SCREEN_HEIGHT 64 // Hauteur de l'écran OLED, en pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  ///////////// ÉCRAN /////////////  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Le code va s'arrêter ici si l'écran n'est pas reconnu
  }
  
  display.clearDisplay();
  display.setTextSize(1);             
  display.setTextColor(WHITE);        
  display.setCursor(0, 0); // Coordonnées d'affichage du texte
  display.print(F("0.1_Ecran")); // Affiche le message entre guillemets
  display.display();
  delay(2000); // Pause de 2 secondes
}

void loop() {
  display.clearDisplay();
  display.setCursor(0, 0); // position du début d'affichage du texte
  display.draw
  display.display();
  delay(5);
}