#include <NewPing.h>
#include<Wire.h>
#include<LCD_I2C.h>
int LED1=13;
int LED2=12;
int buzzer=11;
int trig=10;
int echo=9;
int centimeters=180;
LCD_I2C lcd(0x27,16,2);
NewPing sonar(trig,echo,centimeters);
void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(115200);
}
void loop() {
  // put your main code here, to run repeatedly:
  int i=0;
  if(sonar.ping_cm(centimeters)!=0){
    Serial.print(sonar.ping_cm(centimeters));
        lcd.setCursor(1, 0);
        lcd.print("Distance");
        lcd.setCursor(2,1);
        lcd.print(sonar.ping_cm(centimeters));
        digitalWrite(LED1,HIGH);
        digitalWrite(LED2,LOW);
        digitalWrite(buzzer,HIGH);
        for(i=0;i<200;i++){
            digitalWrite(buzzer,HIGH);
            delay(3);
            digitalWrite(buzzer,LOW);
            delay(1);
        }
         lcd.clear();
         digitalWrite(LED2,HIGH);
        digitalWrite(LED1,LOW);
        digitalWrite(buzzer,LOW);
        delay(1000);
  }
}
