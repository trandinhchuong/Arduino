int val =10;
void setup() {
 Serial.begin(9600);
}

void loop() {
Serial.print("hello word\n");
Serial.print(val);
delay(1000);
}
