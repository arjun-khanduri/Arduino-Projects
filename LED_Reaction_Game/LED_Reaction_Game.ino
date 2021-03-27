#define greenLED 8
#define redLED 9
#define yellowLED 10
int timesOn[] = {100, 250, 400, 500};
int delayTimes[] = {250, 500, 1000, 1500};
volatile boolean redLEDLit = false;
volatile boolean isWinner = false;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  attachInterrupt(0, checkWinner, FALLING);
  turnOffLEDs();
}

void loop() {
  int LEDToLight = random(1, 4);
  int periodLEDIsLit = timesOn[random(4)];
  lightLED(LEDToLight, periodLEDIsLit);
  turnOffLEDs();
  int delayTime = delayTimes[random(4)];
  delay(delayTime);
  if(isWinner){
    isWinner = false;
    winner();
  }
}

void lightLED(int led, int duration){
  switch(led){
    case 1:
      digitalWrite(greenLED, HIGH);
      break;
    case 2:
      redLEDLit = true;
      digitalWrite(redLED, HIGH);
      break;
    case 3:
      digitalWrite(yellowLED, HIGH);
      break;
    default:
      break;
  }
  delay(duration);
  redLEDLit = false;
}
void turnOffLEDs(){
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
}

void winner(){
  for(int i = 0; i < 3; i++){
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    delay(250);
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    delay(250);
  }
  delay(3000);
}

void checkWinner(){
  if(redLEDLit)
    isWinner = true;
}
