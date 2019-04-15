#include <LiquidCrystal.h>

#define TEMP_0_PIN         13   // Analog Input
#define TEMP_1_PIN         15   // Analog Input
#define TEMP_BED_PIN       14   // Analog Input
#define GRZALKA            10

#define a -4.41695189485423e-07
#define b 0.000757625195689714
#define c -0.542507320314895
#define d 241.754529368582

int i = 0;
double x,y;
int temperatura;
LiquidCrystal lcd(16,17,23,25,27,29);



void setup() {
  // put your setup code here, to run once:
  lcd.begin(20,4);
  pinMode(GRZALKA,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  temperatura = analogRead(TEMP_0_PIN);
  x = (double)temperatura;
  y = a*x*x*x + b*x*x + c*x + d;
  
  lcd.print("siema = ");
  lcd.print(y);
  lcd.setCursor(0,0);

  
  
  if (y < 60.0)
  {
    digitalWrite(GRZALKA,HIGH);
    i++;
    
  }
  else
    digitalWrite(GRZALKA,LOW);
    
  delay(100);
}
