#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define X_MIN_PIN           3
#ifndef X_MAX_PIN
#define X_MAX_PIN         2
#endif
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

int i = 0;
int kierunek1 = 0, kierunek2 = 0, kierunek3 = 0;
int flaga = 0;
String a; //zmienna wiadomosci
int krok1 = 0, krok2 = 0, krok3 = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);

  //silniki
  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(X_DIR_PIN, OUTPUT);
  pinMode(X_ENABLE_PIN, OUTPUT);

  pinMode(Y_STEP_PIN, OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);
  pinMode(Y_ENABLE_PIN, OUTPUT);

  pinMode(Z_STEP_PIN, OUTPUT);
  pinMode(Z_DIR_PIN, OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);

  digitalWrite(X_ENABLE_PIN, LOW);
  digitalWrite(X_DIR_PIN, LOW);

  digitalWrite(Y_ENABLE_PIN, LOW);
  digitalWrite(Y_DIR_PIN, LOW);

  digitalWrite(Z_ENABLE_PIN, LOW);
  digitalWrite(Z_DIR_PIN, LOW);

  //krancowki
  pinMode(X_MAX_PIN, INPUT_PULLUP);
  pinMode(Y_MAX_PIN, INPUT_PULLUP);
  pinMode(Z_MAX_PIN, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  //poruszanie sie gora dol
  /*          
  if (i == 500)
  {
    i = 0;
    kierunek = !kierunek;
    digitalWrite(X_DIR_PIN, kierunek);
    digitalWrite(Y_DIR_PIN, kierunek);
    digitalWrite(Z_DIR_PIN, kierunek);
  }

  digitalWrite(X_STEP_PIN, LOW);
  digitalWrite(Y_STEP_PIN, LOW);
  digitalWrite(Z_STEP_PIN, LOW);
  delay(1);
  if ((digitalRead(X_MAX_PIN) == 0 && kierunek == 0) || kierunek == 1)
    digitalWrite(X_STEP_PIN, HIGH);
  if ((digitalRead(Y_MAX_PIN) == 0 && kierunek == 0) || kierunek == 1)
    digitalWrite(Y_STEP_PIN, HIGH);
  if ((digitalRead(Z_MAX_PIN) == 0 && kierunek == 0) || kierunek == 1)
    digitalWrite(Z_STEP_PIN, HIGH);
  delay(1);
  i++;
  
  
  //wydruk stanu krancowek
  //Serial.print(digitalRead(X_MAX_PIN));
  //Serial.print(digitalRead(Y_MAX_PIN));
  //Serial.println(digitalRead(Z_MAX_PIN));
  */
  
  

  while (Serial.available() > 0)
  {
    a = Serial.readStringUntil('\n');
    sscanf(a.c_str(), "a %d b %d c %d", &krok1, &krok2, &krok3);
    flaga = 1;
    if( krok1 < 0){
      krok1 = -krok1;
      kierunek1 = 1;
      digitalWrite(X_DIR_PIN, kierunek1);
    }
    else {
      kierunek1 = 0;
      digitalWrite(X_DIR_PIN, kierunek1);
    }
    if( krok2 < 0){
      krok2 = -krok2;
      kierunek2 = 1;
      digitalWrite(Y_DIR_PIN, kierunek2);
    }
    else{
      kierunek2 = 0;
      digitalWrite(Y_DIR_PIN, kierunek2);
    }
    if( krok3 < 0){
      krok3 = -krok3;
      kierunek3 = 1;
      digitalWrite(Z_DIR_PIN, kierunek3);
    }
    else{
      kierunek3 = 0;
      digitalWrite(Z_DIR_PIN, kierunek3);
     
    }
    
    
    //wyswietlenie/sprawdzenie krokow
    //Serial.println(krok1);
  }
  //fprintf sprintf printf*******
  //obsluga krokow sil1,2,3
  if (((digitalRead(X_MAX_PIN) == 0 && kierunek1 == 0) || kierunek1 == 1) && krok1 > 0){
    digitalWrite(X_STEP_PIN, HIGH);
    krok1--;
  }
  
  if (((digitalRead(Y_MAX_PIN) == 0 && kierunek2 == 0) || kierunek2 == 1) && krok2 > 0){
    digitalWrite(Y_STEP_PIN, HIGH);
    krok2--;
  }
  if (((digitalRead(Z_MAX_PIN) == 0 && kierunek3 == 0) || kierunek3 == 1) && krok3 > 0){
    digitalWrite(Z_STEP_PIN, HIGH);
    krok3--;
  }
  
  delay(1);
  digitalWrite(X_STEP_PIN, LOW);
  digitalWrite(Y_STEP_PIN, LOW);
  digitalWrite(Z_STEP_PIN, LOW);
  delay(1);


 
  if ( krok1 == 0 && krok2 == 0 && krok3 == 0 && flaga == 1)
  {
    Serial.println("Idle");
    flaga = 0;
  }
 
}


/*
 * To nasz program wara od niego >:c
 * M.Martyna
 * Z.Matkowska
 * M.Rateusz
 */


