#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <image.h>
#include <ysl_court.h>

// Devoir 01
// https://www.youtube.com/watch?v=rQcDVL15GIo
/*
Nigga, hustlers don't stop, they keep goin' (Yeah)
You can lose your life but it gon' keep goin' (Yeah)
Why not risk life when it's gon' keep goin'? (Yeah)
When you die somebody else was born
But at least we got to say…
*/

///////// ÉCRAN ////////
#define SCREEN_WIDTH 128 // Largeur de l'écran OLED, en pixels
#define SCREEN_HEIGHT 64 // Hauteur de l'écran OLED, en pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int x = 0;
int y = 0;
int myStateMachine = 1;
int compteur = 0; // int pour faire anime qui change d'écran

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
  display.print(F("Devoir 1 - Running horses Young Thug")); // Affiche le message entre guillemets
  display.display();
  delay(2000); // Pause de 2 secondes
}

void loop() {
  display.clearDisplay();
  if (compteur == 0){
  display.setTextSize(1,2);
  display.setTextColor(1);
  display.setCursor(64,0);
  display.printf("Nigga,"); // Afficher les lyrics sur plusieurs lignes en decoupant les paroles
  display.setCursor(64,14);
  display.printf("hustlers");
  display.setCursor(64,26);
  display.printf("don't stop");
  display.setCursor(64,38);
  display.printf("they keep");
  display.drawBitmap(x,y,My_bitmaphorse_running_yt,64,64,1); // Image cheval sur la moitie gauche du screen
  } else if(compteur == 1){
  display.setTextSize(3,8);
  display.setTextColor(1);
  display.setCursor(0,0);
  display.printf("GOIIING");
  display.drawBitmap(x,y,My_bitmaphorse_running_yt,64,64,1);
  } else if(compteur == 2){ // 2eme ecran
    display.setTextSize(1,2);
    display.setTextColor(1);
    display.setCursor(0,0);
    display.printf("You can");
    display.setCursor(0,14);
    display.printf("lose your life");
    display.setCursor(0,26);
    display.printf("but it gon'");
    display.setCursor(0,38);
    display.printf("keep goin'");
    display.drawBitmap(64,y,My_bitmaphorse_running_yt,64,64,1);
  } else if(compteur == 3){ // 3eme ecran
    display.setTextSize(1,3);
    display.setTextColor(1);
    display.setCursor(30,0);
    display.printf("Why not risk");
    display.setCursor(10,20);
    display.printf("life when it's gon");
    display.setCursor(30,40);
    display.printf("keep goin'?");
  } else if(compteur == 4){ // 4eme ecran
    display.drawBitmap(0,0, My_bitmapysl_court_invert,64,64,1); // young thug in court
    display.drawBitmap(64,0, My_bitmapysl_court_invert,64,64,1);
  }
  display.display();
  compteur = compteur + 1; // Compteur pour afficher les ecrans
  if (compteur == 5){
    compteur = 0;
  }
  delay(5000); // 5 secondes par screen
}
