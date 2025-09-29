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
const char* maString;

/// WiFi ///
#include <WiFi.h>
#include <WiFiUdp.h>
#include <MicroOsc.h>
#include <MicroOscUdp.h>

WiFiUDP myUdp;
unsigned int myReceivePort = 8000;
IPAddress mySendIp(192, 168, 50, 56);
unsigned int mySendPort = 8001;

const char* ssid     = "link"; // nom du routeur
const char* password = "nidieunimaitre"; // mot de passe 

MicroOscUdp<1024> myOsc(&myUdp, mySendIp, mySendPort);

char packetBuffer[255];

// FUNCTION THAT WILL BE CALLED WHEN AN OSC MESSAGE IS RECEIVED:
void myOscMessageParser( MicroOscMessage& receivedOscMessage) {
   // DO MESSAGE ADDRESS CHECKING AND ARGUMENT GETTING HERE
   
   if ( receivedOscMessage.checkOscAddress("/pot") ) {
 // Serial.println("hello world!");
//float floatArgument = receivedOscMessage.nextAsFloat();
  //Serial.println(floatArgument);
  //int intArgument = receivedOscMessage.nextAsInt(); // pour afficher le contenue du message
  //Serial.print(intArgument);
  maString = receivedOscMessage.nextAsString();
  Serial.print(maString);
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

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.println(F("1.1.5 WiFI serveur"));
    display.display();      // Show initial text
    delay(1500);
}

void loop() {

  // TRIGGER myOnOscMessageReceived() IF AN OSC MESSAGE IS RECEIVED :
  myOsc.onOscMessageReceived( myOscMessageParser ); // ouvre le message ??

    display.clearDisplay(); // Efface l'image précédente
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print(F("1.1.5 WiFI serveur"));
    display.setTextSize(1);
    display.setCursor(5,17);
    display.print(F("Adresse du serveur: "));
    display.setCursor(5,27);
    display.print(WiFi.localIP());
    display.setCursor(5,37);
    display.print(F("Port: "));
    display.setCursor(35,37);
    display.print(myReceivePort);

    display.display();      // Affiche à l'écran
    delay(50);
}