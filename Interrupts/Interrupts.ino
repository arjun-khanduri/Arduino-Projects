#define ledPin 13
#define inputPin 2
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT_PULLUP);
  attachInterrupt(0, buttonPressed, FALLING);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void buttonPressed(){
  Serial.println("Interrupt fired");
  if(digitalRead(ledPin))
    digitalWrite(ledPin, LOW);
  else
    digitalWrite(ledPin, HIGH);
}
