#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);

  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();
  unsigned long days = currentMillis / 86400000;
  unsigned long hours = (currentMillis / 3600000) % 24;
  unsigned long minutes = (currentMillis / 60000) % 60;
  unsigned long seconds = (currentMillis / 1000) % 60;
  unsigned long milliseconds = currentMillis % 1000;

  lcd.setCursor(0, 0);
  lcd.print(days);
  lcd.print(" d :");
  lcd.print(hours);
  lcd.print(" h :"); // Extra spaces to clear old text
  lcd.print(minutes);
  lcd.print(" m       "); // Extra spaces to clear old text

  lcd.setCursor(0, 1);
  lcd.print(seconds);
  lcd.print(" s : ");
  lcd.print(milliseconds);
  lcd.print(" ms      ");

// this part is just so i can see it on the serial monitor
  Serial.print(seconds);
  Serial.print(" seconds");
  Serial.println(milliseconds);
  Serial.print(" milliseconds");

  delay(100); // Small delay to make it readable
}
