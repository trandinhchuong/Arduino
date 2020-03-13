
#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD


LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x3F, 16, 2); // Change to (0x27,16,2) for 16x2 LCD. 0x3f or 0x20
void setup() {

  lcd.init(); //khoi tao man hinh 
  lcd.backlight();  //tat man hinh
  lcd.clear();  //xoa man hinh
}
void loop() {
  // Print 'Hello World!' on the first line of the LCD:
  lcd.setCursor(2, 0); // Set the cursor on the first column and first row.
  lcd.print("ab"); // Print the string "Hello World!"


  delay(5000);
}
