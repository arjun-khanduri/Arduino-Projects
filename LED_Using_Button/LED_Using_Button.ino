#define LEDPin 8
#define ButtonPin 7

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPin, OUTPUT);
  pinMode(ButtonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(ButtonPin) == LOW)
    digitalWrite(LEDPin, HIGH);
  else
    digitalWrite(LEDPin, LOW);
}
