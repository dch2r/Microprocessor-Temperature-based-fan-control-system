#include<LiquidCrystal.h>


// Declare all the pins 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int temp = A0;
int greenLed = 10;
int redLed = 9;
int fan = 7;
int buzzer = 8;

int thresholdValue = 0;
int celsius = 0;
int old_celsius = 0;
int fahrenheit = 0;

// Functions for various work
void greenLightOn(){
  digitalWrite(greenLed, HIGH);
}
void greenLightOff(){
  digitalWrite(greenLed, LOW);
}
void redLightOn(){
  digitalWrite(redLed, HIGH);
}
void redLightOff(){
  digitalWrite(redLed, LOW);
}
void fanOn(){
  digitalWrite(fan, HIGH);
}
void fanOff(){
  digitalWrite(fan, LOW);
}
void buzzerOn(){
  digitalWrite(buzzer, HIGH);
}
void buzzerOff(){
  digitalWrite(buzzer, LOW);
}


void setup(){
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(temp, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2); 
}

void loop(){
    
  // Temperature calculation
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  fahrenheit = ((celsius * 9) / 5 + 32);
  
  if(old_celsius != celsius) {
  	lcd.clear();
    old_celsius = celsius;
  }
 
  if( celsius<= 30){
    greenLightOn();
    redLightOff();
    fanOff();
    buzzerOff();
  }
  else if(celsius >= 31 && celsius <= 40){
    greenLightOff();
    fanOff();
    buzzerOff();
    redLightOn();
  }
  else if(celsius > 40){
    redLightOn();
    fanOn();
    buzzerOn();
    greenLightOff();
  }
  lcd.setCursor(0,0);          
  lcd.print("Celsius:");
  lcd.setCursor(11, 0);
  lcd.print(celsius);
  lcd.setCursor(15,0);
  lcd.print("C");
  lcd.setCursor(0,1);          
  lcd.print("Farenheit:");
  lcd.setCursor(11, 1);
  lcd.print(fahrenheit);
  lcd.setCursor(15, 1);
  lcd.print("F");  
  delay(100);
}
