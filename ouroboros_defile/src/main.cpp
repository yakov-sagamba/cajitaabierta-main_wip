#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//#include <image.h>
#include <custom_image.h>

// X Exercice 1 : Prenez une image noir et blanc de 100 x 64 pixels maximum et transformez la en 'bmp' avec cet outil 
// en ligne https://projedefteri.com/en/tools/lcd-assistant/ (ou un autre convertisseur d'image)
// X Exercice 2 : Déplacez l'image
// Exercice 3 : Ajoutez un décompte et des lignes

///////// ÉCRAN ////////
#define SCREEN_WIDTH 128 // Largeur de l'écran OLED, en pixels
#define SCREEN_HEIGHT 64 // Hauteur de l'écran OLED, en pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int x = 64;
int y = 0;
int i = 0;
int a = -64;

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
  display.print(F("0.1.3 Ecran image")); // Affiche le message entre guillemets
  display.display();
  delay(500); // Pause de 0.5 seconde
}

void loop() {
  display.clearDisplay();
  //display.invertDisplay(i);
  display.drawBitmap(x,y,My_bitmapOuroboros,64,64,1); // Example pour Adafruit GFX
  display.display();
x = x + 1;
if (x > 128){
  x = -64;
} 
display.drawBitmap(i,y,My_bitmapOuroboros,64,64,1);
display.display();
i = i + 1;
if (i > 128){
  i = 0;
}
display.drawBitmap(a,y,My_bitmapOuroboros,64,64,1);
display.display();
a = a + 1;
if (a > 128){
  a = -64;
}
  delay(10);
}