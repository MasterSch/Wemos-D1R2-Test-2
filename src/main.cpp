#include <Arduino.h>



// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
  //pinMode(D9, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(D0, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(D0, HIGH);    // turn the LED off by making the voltage HIGH
  digitalWrite(D1, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(D1, HIGH);  
  digitalWrite(D2, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(D2, HIGH);  
  digitalWrite(D3, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(D3, HIGH);  
  digitalWrite(D4, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(D4, HIGH);  
  digitalWrite(D5, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(D5, HIGH);    // turn the LED off by making the voltage HIGH
  digitalWrite(D6, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(D6, HIGH);  
  digitalWrite(D7, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(D7, HIGH);  
  digitalWrite(D8, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(D8, HIGH);  
//  digitalWrite(D9, LOW);   // turn the LED on (HIGH is the voltage level)
//  delay(200);                       // wait for a second
//  digitalWrite(D9, HIGH);  
}




/*
 *
 * Arduino Sketch für SmartHome yourself - Arduino Lehrgang
 * 
 * Tag 19: GPIO über SerialComInstruments steuern
 * In diesem Sketch überwachen wir die Serielle Kommunikation auf Eingaben. 
 * In der loop-Methode wird geprüft ob eine Eingabe nach dem SerialComInstruments-Protokoll codiert vom PC an den Arduino übertragen wird.
 * Falls eine Eingabe nach dem Schema "#__M__<" übertragen wird, wird diese geprüft. 
 * Sofern ein gültiger Kanal erkannt wird (zwischen "#" und "M"), wird der Wert (zwischen "M" und "<") ausgewertet 
 * und entsprechend verarbeitet.
 * 
 * Beim schalten der LEDs wird nach gleicher Codierung ein Farbcode vom Arduino an den PC übermittelt. 
 * Dies sorgt für eine Einfärbung des entsprechenden Blocks in der Oberfläche. 
 * 
 * https://www.arduino.cc/reference/en/language/functions/communication/serial/parseint/
 * https://www.arduino.cc/reference/en/language/functions/communication/serial/parsefloat/
 * 
 * http://www.serialcominstruments.com/SerialComInstruments%20Doku.pdf
 * 
 * By Daniel Scheidler - Dezember 2019
 *
 *
 *******************************************  zum Testen vom RGB LED 64x32 Panel. Programm in Examples ***********************************

 
const unsigned int Line_A = 1;                // globale Konstante für Pin mit roter LED
const unsigned int Line_B = 2;               // globale Konstante für Pin mit gelber LED
const unsigned int Line_C = D8;              // globale Konstante für Pin mit grüner LED
const unsigned int Line_D = D6;                // globale Konstante für Pin mit roter LED
const unsigned int RED_oben = D3;               // globale Konstante für Pin mit gelber LED
const unsigned int GREEN_oben = D7;              // globale Konstante für Pin mit grüner LED
const unsigned int BLUE_oben = 9;                // globale Konstante für Pin mit roter LED
const unsigned int RED_unten = 10;               // globale Konstante für Pin mit gelber LED
const unsigned int GREEN_unten = 11;              // globale Konstante für Pin mit grüner LED
const unsigned int BLUE_unten = 12;                // globale Konstante für Pin mit roter LED
const unsigned int CLOCK = D5;               // globale Konstante für Pin mit gelber LED
const unsigned int LATCH = D0;              // globale Konstante für Pin mit grüner LED
const unsigned int OE = D4;

void schalte(int kanal, float wert);

void setup() {
//Serial.begin(115200);                              // Serielle Kommunikation mit 38400 Baud starten


  pinMode(Line_A, OUTPUT);
  pinMode(Line_B, OUTPUT);
  pinMode(Line_C, OUTPUT);
  pinMode(Line_D, OUTPUT);
  pinMode(RED_oben, OUTPUT);                    // PIN von roter LED als OUTPUT festlegen.
  pinMode(GREEN_oben, OUTPUT);                   // PIN von gelber LED als OUTPUT festlegen.
  pinMode(BLUE_oben, OUTPUT);                  // PIN von grüner LED als OUTPUT festlegen.
  pinMode(RED_unten, OUTPUT);
  pinMode(GREEN_unten, OUTPUT);
  pinMode(BLUE_unten, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(OE, OUTPUT);

  digitalWrite(Line_A, 0);
  digitalWrite(Line_B, 0);
  digitalWrite(Line_C, 0);
  digitalWrite(Line_D, 0);
  digitalWrite(RED_oben, 0);
  digitalWrite(GREEN_oben, 0);
  digitalWrite(BLUE_oben, 0);
  digitalWrite(RED_unten, 0);
  digitalWrite(GREEN_unten, 0);
  digitalWrite(BLUE_unten, 0);
  digitalWrite(CLOCK, 0);
  digitalWrite(LATCH, 0);
  digitalWrite(OE, 0);

}


void loop() {

  digitalWrite(Line_A, 0);
  digitalWrite(Line_B, 0);
  digitalWrite(Line_C, 0);
  digitalWrite(Line_D, 0);
  digitalWrite(RED_oben, 0);
  digitalWrite(GREEN_oben, 0);
  digitalWrite(BLUE_oben, 0);
  digitalWrite(RED_unten, 0);
  digitalWrite(GREEN_unten, 0);
  digitalWrite(BLUE_unten, 0);
  digitalWrite(CLOCK, 0);
  digitalWrite(LATCH, 0);
  digitalWrite(OE, 0);

delay (500);

  digitalWrite(Line_A, 1);
  digitalWrite(Line_B, 1);
  digitalWrite(Line_C, 1);
  digitalWrite(Line_D, 1);
  digitalWrite(RED_oben, 1);
  digitalWrite(GREEN_oben, 1);
  digitalWrite(BLUE_oben, 1);
  digitalWrite(RED_unten, 1);
  digitalWrite(GREEN_unten, 1);
  digitalWrite(BLUE_unten, 1);
  digitalWrite(CLOCK, 1);
  digitalWrite(LATCH, 1);
  digitalWrite(OE, 1);

delay(500);

}
*/
