/* Affiche la valeur du potentiomètre à l'écran et l'envoi sur le port série*/

#include <Arduino.h>
#include <Adafruit_GFX.h> // Librairie graphique pour l'écran
#include <Adafruit_SSD1306.h> // On ajoute la librairie de l'écran SSD1306

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Déclaration de variable
int pot1 = 0;
float normalisePot1;

/// WiFi ///
#include <WiFi.h>
#include <WiFiUdp.h>
#include <MicroOsc.h>
#include <MicroOscUdp.h>

WiFiUDP myUdp; // start wifi instance
unsigned int myReceivePort = 8001;
IPAddress mySendIp(192, 168, 0, 108); // Adresse du serveur
unsigned int mySendPort = 8000; // Port de réception Udp

MicroOscUdp<1024> myOsc(&myUdp, mySendIp, mySendPort);

const char* ssid     = "link";
const char* password = "nidieunimaitre";

// Définition des broches
const int brocheBouton = 0;    // Broche à laquelle le bouton est connecté
const int ledPin = 2;       // Broche à laquelle la LED est connectée (LED intégrée sur GPIO 2)
// Variables
int etatBouton = 0;        // Variable pour lire l'état du bouton

char packetBuffer[255];

// FUNCTION THAT WILL BE CALLED WHEN AN OSC MESSAGE IS RECEIVED:
void myOscMessageParser( MicroOscMessage& receivedOscMessage) {
   // DO MESSAGE ADDRESS CHECKING AND ARGUMENT GETTING HERE
   if ( receivedOscMessage.checkOscAddress("/pot") ) {
  Serial.println("hey!");
}
}

void setup() {
    Serial.begin(115200);
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
        Serial.println("SSD1306 allocation failed");
    }

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connecté !");
    Serial.print("Adresse IP ESP32 : ");
    Serial.println(WiFi.localIP());

    myUdp.begin(myReceivePort);

      // Initialisation du bouton comme entrée avec un pullup interne
  pinMode(brocheBouton, INPUT_PULLUP);

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.println(F("1.1.5 WiFI client"));
    display.display();      // Show initial text
    delay(1500);
}

void loop() {

  // TRIGGER myOnOscMessageReceived() IF AN OSC MESSAGE IS RECEIVED :
  myOsc.onOscMessageReceived( myOscMessageParser );

    //pot1 = analogRead(33); // Lecture de la broche 25 sur le ESP32 // ADC2 weirdness while using WIFI
    //normalisePot1 = pot1/4095.0;
    //Serial.println(normalisePot1);
    // myOsc.sendFloat("/pot", normalisePot1);
    //myOsc.sendInt("/bouton", etatBouton);  
    //myOsc.sendString("/messageAdresse", "horses dont stop they keep going");
    etatBouton = digitalRead(brocheBouton);
    Serial.println(etatBouton);

    display.clearDisplay(); // Efface l'image précédente
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print(F("1.1.5 WiFI client"));
    display.setTextSize(1);
    display.setCursor(5,17);
    display.print(F("Adresse du client: "));
    display.setCursor(5,27);
    display.print(WiFi.localIP());
    display.setCursor(5,37);
    display.print(F("Port: "));
    display.setCursor(35,37);
    display.print(F("8001"));
    display.setCursor(5,47);
    display.print(F("Bouton: "));
    display.setCursor(46,47);
    display.print(etatBouton);

    display.display();      // Affiche à l'écran
    delay(50);
}