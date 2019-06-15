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

int i=0;
int kierunek=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);

  //inicjalizacja silnikow, ustawienie kierunku
  pinMode(X_STEP_PIN,OUTPUT);
  pinMode(X_DIR_PIN,OUTPUT);
  pinMode(X_ENABLE_PIN,OUTPUT);

  pinMode(Y_STEP_PIN,OUTPUT);
  pinMode(Y_DIR_PIN,OUTPUT);
  pinMode(Y_ENABLE_PIN,OUTPUT);

  pinMode(Z_STEP_PIN,OUTPUT);
  pinMode(Z_DIR_PIN,OUTPUT);
  pinMode(Z_ENABLE_PIN,OUTPUT);
  
  digitalWrite(X_ENABLE_PIN,LOW);
  digitalWrite(X_DIR_PIN,LOW);

  digitalWrite(Y_ENABLE_PIN,LOW);
  digitalWrite(Y_DIR_PIN,LOW);

  digitalWrite(Z_ENABLE_PIN,LOW);
  digitalWrite(Z_DIR_PIN,LOW);

  //ustawienie pinow, odpowiadajacych za krancowki jako wejscia z pullupem
  pinMode(X_MAX_PIN,INPUT_PULLUP);
  pinMode(Y_MAX_PIN,INPUT_PULLUP);
  pinMode(Z_MAX_PIN,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(i==500)
  {
    //część kodu odpowiadająca za zmianę kierunku
    i=0;
    kierunek=!kierunek;
    digitalWrite(X_DIR_PIN,kierunek);
    digitalWrite(Y_DIR_PIN,kierunek);
    digitalWrite(Z_DIR_PIN,kierunek);
  }
  
  //dzialanie silnikow
  digitalWrite(X_STEP_PIN,LOW);
  digitalWrite(Y_STEP_PIN,LOW);
  digitalWrite(Z_STEP_PIN,LOW);
  delay(1);
  
  //sprawdzenie czy zaden z silnikow nie dotyka krancowki
  if((digitalRead(X_MAX_PIN)==0 && kierunek==0) || kierunek==1)
    digitalWrite(X_STEP_PIN,HIGH);
  if((digitalRead(Y_MAX_PIN)==0 && kierunek==0) || kierunek==1)
    digitalWrite(Y_STEP_PIN,HIGH);
  if((digitalRead(Z_MAX_PIN)==0 && kierunek==0) || kierunek==1)
    digitalWrite(Z_STEP_PIN,HIGH);
  delay(1);
  i++;
  
  Serial.print(digitalRead(X_MAX_PIN));
  Serial.print(digitalRead(Y_MAX_PIN));
  Serial.println(digitalRead(Z_MAX_PIN));




}
