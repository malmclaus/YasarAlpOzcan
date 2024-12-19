// C++ code
//
#include <Adafruit_LiquidCrystal.h>

int Temp = 0;

int Voltage = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  lcd_1.begin(16, 2);
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  Temp = (-40 + 0.488155 * (analogRead(A0) - 20));
  if (Temp <= 30) {
    digitalWrite(2, HIGH);
    digitalWrite(5, LOW);
  } else {
    digitalWrite(2, LOW);
    digitalWrite(5, HIGH);
  }
  if (Temp > 40) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }

  lcd_1.setCursor(0, 1);
  lcd_1.leftToRight();
  lcd_1.print("Temperature:");
  lcd_1.print(Temp);
  lcd_1.print("C");
  lcd_1.setCursor(0, 0);
  lcd_1.print("Fan Speed:");
  delay(10); // Delay a little bit to improve simulation performance
}