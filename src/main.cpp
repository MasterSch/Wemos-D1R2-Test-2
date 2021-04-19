#include <Arduino.h>
#include <PxMatrix.h>
#include <Wire.h>



#ifdef ESP32

#define P_LAT 22
#define P_A 19
#define P_B 23
#define P_C 18
#define P_D 5
#define P_E 15
#define P_OE 16
hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

#endif

#ifdef ESP8266

#include <Ticker.h>
Ticker display_ticker;
#define P_LAT 16
#define P_A 5
#define P_B 4
#define P_C 15
#define P_D 12
#define P_E 0
#define P_OE 2

#endif
// Pins for LED MATRIX

//PxMATRIX display(32,16,P_LAT, P_OE,P_A,P_B,P_C);
PxMATRIX display(64,32,P_LAT, P_OE,P_A,P_B,P_C,P_D);
//PxMATRIX display(64,64,P_LAT, P_OE,P_A,P_B,P_C,P_D,P_E);

#ifdef ESP8266
// ISR for display refresh
void display_updater()
{
  display.displayTestPattern(70);
  // display.displayTestPixel(70);
  //display.display(70);
}
#endif

#ifdef ESP32
void IRAM_ATTR display_updater(){
  // Increment the counter and set the time of ISR
  portENTER_CRITICAL_ISR(&timerMux);
  //isplay.display(70);
  display.displayTestPattern(70);
  portEXIT_CRITICAL_ISR(&timerMux);
}
#endif


uint16_t myCYAN = display.color565(0, 255, 255);
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
  delay(2000);
  Serial.println("Start........");
  display.begin(4);
  display.flushDisplay();
  display.setTextColor(myCYAN);
  display.setCursor(2,0);
  display.print("Pixel");
  Serial.println("hello");

  #ifdef ESP8266
    display_ticker.attach(0.004, display_updater);
  #endif

  #ifdef ESP32
    timer = timerBegin(0, 80, true);
    timerAttachInterrupt(timer, &display_updater, true);
    timerAlarmWrite(timer, 4000, true);
    timerAlarmEnable(timer);
  #endif

  delay(1000);
}


void loop() {

 delay(100);
 Serial.println("hello");

}










/*
int LED1 = 14;
//int LED2 = 2;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.

pinMode(LED1, OUTPUT); 
//pinMode(LED2, OUTPUT); 

digitalWrite(LED1, HIGH);  
//digitalWrite(LED2, LOW);   



  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);


  
}

// the loop function runs over and over again forever
void loop() {
//  digitalWrite(LED1, LOW);  
//  digitalWrite(LED2, LOW);   
  delay(200);
//  digitalWrite(LED1, HIGH);  
//  digitalWrite(LED2, HIGH);
  delay(200);
  
  digitalWrite(0, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(0, LOW);    // turn the LED off by making the voltage HIGH
  
  
  digitalWrite(1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(1, LOW);  
  
  
  digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(2, LOW);  
  
  
  digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(3, LOW);  
  
  
  digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(4, LOW);  
  
  
  digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(5, LOW);    // turn the LED off by making the voltage HIGH
  
  
  digitalWrite(12, HIGH);   // turn the LED on (LOW is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(12, LOW);  
  

  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(13, LOW);  
  
  
  digitalWrite(14, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(14, LOW);  
  
  
  digitalWrite(15, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(15, LOW);  


  digitalWrite(16, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(16, LOW);  

}
*/




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
