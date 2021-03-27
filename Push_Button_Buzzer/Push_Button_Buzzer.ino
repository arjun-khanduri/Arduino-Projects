#define buzzer 9
#define ButtonPin 7

void setup() {
  // put your setup code here, to run once:
  pinMode(ButtonPin, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(ButtonPin) == LOW){
    noTone(buzzer);
  }else{
    tone(buzzer, 3000);
  }
}
