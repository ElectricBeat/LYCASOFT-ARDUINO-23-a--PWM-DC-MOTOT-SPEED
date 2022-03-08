#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);

const int analogInPin = A0;
const int analogOutPin = 9;

int sensorValue = 0;
int outputValue = 0;

void setup()
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);     
  lcd.print("SRIELECTRONIC & EMBEDDED SOIUTIONS");
  delay(1000);    
  Serial.println("SRIELECTRONIC & EMBEDDED SOIUTIONS");
  Serial.begin(9600); 
}

void loop() 
{
  sensorValue = analogRead(analogInPin);    
  outputValue = map(sensorValue, 0, 1023, 0, 255); 
  analogWrite(analogOutPin, outputValue); 
  lcd.setCursor(0,1);
  lcd.print("SPEED:    "); 
  lcd.setCursor(6,1);
  lcd.print(outputValue); 
  delay(1000);   
   
  Serial.print("sensor = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t output = ");      
  Serial.println(outputValue);   

  delay(1000);                     
}
