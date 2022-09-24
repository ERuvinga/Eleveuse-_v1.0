#ifndef proto
#define proto

//QUELQUES VARIABLES GLOBALES DU PROGRAMME 
//variable pour la temperature et l'humidity
float tempe;

 //FONCTIONS POUR LE CONTROL DE tempe,humid,leds, etc...
void control_temperature();
void control_leds();
void control_buzzer();

//pour l'affichage
void affiche_tempe();

#endif //prototype
