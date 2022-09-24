#include<LiquidCrystal.h>
#include <dht.h>
#include "prototypes.h"
#include "lcd.h"

  // Composants connectes sur l'arduino
#define DHT_PIN 12
// leds pour le control de la temperature
#define RED_LED_T 13
#define GREEN_LED_T 11
#define YELLOW 10


//AUTRES
#define BUZZER 7
#define RELAIS_RES 6

unsigned long temp_lcd;
unsigned long temp_buzzer;
unsigned long temp_led_red;
unsigned long temp_led_yel;

bool etat_buz= 0;
bool etat_red_led= 0;
bool etat_yellow_led= 0;

dht capteur;

void beginer(){
  Serial.begin(9600);  
  pinMode(RED_LED_T , OUTPUT);
  pinMode(GREEN_LED_T, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(RELAIS_RES , OUTPUT);

  lcd_tempe.begin(16, 2); 
}

void setup() {
  
    beginer();
    temp_lcd = millis();
    temp_buzzer = millis();
    temp_led_red = millis();
    temp_led_yel = millis();
 }

void loop() {
 
  if(( millis() - temp_lcd) >= 500){
    temp_lcd = millis(); 
          affiche_tempe();
          }

  capteur.read11(DHT_PIN); //lecture sur le capteur dht11
  control_temperature();
  control_buzzer();
  tempe = capteur.temperature;
}



void control_temperature(){
    
  if(tempe >= 40){
   digitalWrite(RELAIS_RES, LOW);
  }

 else if(tempe < 36){
   digitalWrite(RELAIS_RES, HIGH);
  }
   
   control_leds();

}



void control_leds(){ 

  if(tempe < 36.5){
      if(( millis() - temp_led_yel) >= 500){
        temp_led_yel = millis();     
        digitalWrite(YELLOW, etat_yellow_led);
        etat_yellow_led= !etat_yellow_led;
      }
    digitalWrite(GREEN_LED_T, LOW);
    digitalWrite(RED_LED_T, LOW);
  }

  else if((tempe > 36) && (tempe < 38.5)){
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED_LED_T, LOW);
    digitalWrite(GREEN_LED_T, HIGH);
  }

  else{
      if(( millis() - temp_led_red) >= 500){
        temp_led_red = millis();     
        digitalWrite(RED_LED_T, etat_red_led);
        etat_red_led= !etat_red_led;
      } 

       digitalWrite(GREEN_LED_T, LOW);
       digitalWrite(YELLOW, LOW);
    }
}


void control_buzzer(){
 
  if((tempe > 40) || (tempe < 30)){
      if(( millis() - temp_buzzer) >= 500){
        temp_buzzer = millis();     
        digitalWrite(BUZZER, etat_buz);
        etat_buz= !etat_buz;
      }
  }

  else 
    digitalWrite(BUZZER, LOW);
}
