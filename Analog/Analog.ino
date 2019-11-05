#define readPin A0  //khai bao chan doc bien tro

float Analog;       //khai bao bien analog
float votal;        //khai bao bien dien ap

void setup() {
Serial.begin(9600); //khai bao cong Serial toc do 9600
}

void loop() {
Analog= analogRead(readPin);   //doc gia tri analog 0-5v -> 0-1023
votal= Analog *  5.0 /1023.0;  //doi analog qua nhiet do 
Serial.print("Analog= \t");
Serial.print(Analog);
Serial.print(" votal= \t");
Serial.println(votal);

delay(100);
}
