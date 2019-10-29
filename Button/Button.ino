#define LED1 13
#define BUTTON1 9

int button;
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(BUTTON1, INPUT);
}
void loop() {

  button = digitalRead(BUTTON1);
  if (button == 0)
    digitalWrite(LED1, 1);
  else
    digitalWrite(LED1, 0);

}
