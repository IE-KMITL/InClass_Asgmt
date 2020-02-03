int ledpin = 19;
int buttonpin = 16;

boolean buttonstate;
boolean laststate;
boolean state = HIGH;

void setup(){
  pinMode (buttonpin,INPUT);
  pinMode (ledpin,OUTPUT);
}
void loop(){
  buttonstate = digitalRead(buttonpin);
  if ((buttonstate == LOW)&&(laststate==HIGH))state=!state;
  digitalWrite(ledpin,state);
  laststate= buttonstate;
}
