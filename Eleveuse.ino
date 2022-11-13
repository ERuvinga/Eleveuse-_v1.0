#include <dht.h>
#include "prototypes.h"

  // Composants connectes sur l'arduino
#define DHT_PIN 12

// leds pour le control de la temperature
#define RED_LED_T 13
#define GREEN_LED_T 11


//AUTRES
#define BUZZER 7
#define RELAIS_RES_A 5
#define RELAIS_RES_B 6


unsigned long temp_led_red;
unsigned long temp_getTemp;
unsigned long temp_led_green;

bool etat_red_led= 0;
bool etat_led_green= 0;

dht capteur;

void beginer(){
  Serial.begin(9600);  
  pinMode(RED_LED_T , OUTPUT);
  pinMode(GREEN_LED_T, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(RELAIS_RES_A , OUTPUT);
  pinMode(RELAIS_RES_B , OUTPUT);

}

void setup() {
  
    beginer();
    temp_getTemp = millis();
    temp_led_red = millis();
    temp_led_green = millis();
 }

void loop() {
 
  if(( millis() - temp_getTemp) >= 800){
    temp_getTemp = millis(); 
          Serial.println(tempe);
          capteur.read11(DHT_PIN); //lecture sur le capteur dht11
          }

  control_temperature();
  tempe = capteur.temperature;
}



void control_temperature(){
    
  if(tempe >= 40){
   digitalWrite(RELAIS_RES_A, LOW);
   digitalWrite(RELAIS_RES_B, LOW);
  }

 else if(tempe <= 36){
   digitalWrite(RELAIS_RES_A, HIGH);
   digitalWrite(RELAIS_RES_B, HIGH);
  }
   
   control_leds();
}



void control_leds(){ 
/*
  if(tempe < 36){
      if(( millis() - temp_led_yel) >= 500){
        temp_led_yel = millis();     
        digitalWrite(RED_LED_T, etat_led_green);
        etat_yellow_led= !etat_led_green;
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
    }*/
}
