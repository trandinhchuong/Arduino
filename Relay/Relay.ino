char input;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); 
}


void loop() {
if(Serial.available()==1){
        input = Serial.read();
        Serial.print("You typed: " );
        Serial.println(input);
    }
if((String)input == "a")
  digitalWrite(LED_BUILTIN, HIGH);   
else if((String)input == "b")                   
  digitalWrite(LED_BUILTIN, LOW);   
                     
}


 
