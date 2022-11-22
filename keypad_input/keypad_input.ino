#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <DHT.h>

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define DHTTYPE DHT11
#define DHTPIN 11
DHT dht(DHTPIN, DHTTYPE);

float temperature;

// int dhtPin = A1;
int temp;

void setup(){
  LcdSetup();
  //pinMode(dhtPin, INPUT);
  dht.begin();
  
  Serial.begin(9600);
}
  
void loop(){
  temperature = dht.readTemperature();
  
  char customKey = customKeypad.getKey();
  
  
  // temp = analogRead(dhtPin); 
  
  
  if (customKey){
    lcd.setCursor(1, 0);
    lcd.clear();
    lcd.print(customKey);
    delay(5000);
  }
  
  if(customKey == 'A')
  {
    lcd.clear();
    lcd.print("temperature");
    lcd.setCursor(0, 1);
    lcd.print(temperature);
    lcd.setCursor(5, 1);
    lcd.print(" *C");
    delay(5000);
  }
  if(!customKey)
    MainMenu();
} 

void MainMenu()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welcome to");
  lcd.setCursor(0, 1);
  lcd.print("Shroomies!");
  delay(3000);
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print("Use button A for");
  lcd.setCursor(0, 1);
  lcd.print("temperature");
  delay(3000);
}






// my version

/*
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
char Outputs[] = 
{'1', '2', '3', 'A', 
'4', '5', '6', 'B', 
'7', '8', '9', 'C',
'*', '0', '#', 'D'};

int pinInputs[] = {'1', '2', '4', '5', '7', '9', "10", "12"};
int states[8];


void setup() {
  // put your setup code here, to run once:
  LcdSetup();  
  for(int pin = 0; pin < pinInputs; pin++)
  {
    pinMode(pin, INPUT);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
    for(int pin = 0; pin < pinInputs; pin++)
    {
      states[pin] = digitalRead(pin);
    
      if(states[pin] = HIGH)
      {
        lcd.clear();
        lcd.print(pin);  
      }
    }

}


*/



void LcdSetup()
{
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("hello world");
 }
