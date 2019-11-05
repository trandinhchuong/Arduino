#define readPin A0

float Analog;
float votal;

void setup() {
Serial.begin(9600);
}

void loop() {
Analog= analogRead(readPin);
votal= Analog *  5.0 /1023.0;
Serial.print("Analog= \t");
Serial.print(Analog);
Serial.print(" votal= \t");
Serial.println(votal);

delay(100);
}
