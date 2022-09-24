// FICHIER POUR AFFICHAGE DES DONNEES.
#ifndef lcd
#define lcd

//pins pour la configuration des bornes du lcd de temperature
#define RS 9
#define EN 8
#define D4 2
#define D5 3
#define D6 4
#define D7 5

LiquidCrystal lcd_tempe(RS, EN, D4, D5, D6, D7);

char tableau[4];

void affiche_tempe(){
  
  sprintf(tableau,"%cC ", char(0b11011111));
  lcd_tempe.clear();
  lcd_tempe.setCursor(2, 0);
  lcd_tempe.print("Chauffage Rb");
  
  lcd_tempe.setCursor(5, 1);
  lcd_tempe.print(tempe, 1);
  lcd_tempe.print(tableau);
  

}

#endif //lcd
