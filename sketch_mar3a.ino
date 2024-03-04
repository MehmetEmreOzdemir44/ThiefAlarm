#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int led1=5;
int led2=4;
int sensorPin=7;
int hareket=0;
int buz=9;


void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(buz,OUTPUT);

  pinMode(sensorPin,INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

}

void loop() {
  hareket= digitalRead(sensorPin);

  Serial.println(hareket);
  if(hareket==1){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(buz,HIGH);
    Serial.println("Hırsız Var");
    
    lcd.setCursor(0,0);
    lcd.print("HIRSIZ VAR");
    delay(50);


    lcd.clear();
  }
  else
  {
    digitalWrite(led2,HIGH);
    digitalWrite(led1,LOW);
    digitalWrite(buz,LOW);
    Serial.println("Sorun Yok");
    
    lcd.setCursor(0,0);
    lcd.print("SORUN YOK");
    delay(50);
    lcd.clear();
  }

}
