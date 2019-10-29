#define LED1 13

void setup() {
  pinMode(13, OUTPUT);
}
void loop() {
  digitalWrite(LED1, 1);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED1, 0);    // turn the LED off by making the voltage LOW
  delay(300);                       // wait for a second
}
