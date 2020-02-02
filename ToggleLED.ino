
int yellow=19;// LED
int buttonpin=16;
bool reading;//push button state
int ctr=0;//counter for button presses


void setup(){
 pinMode(yellow, OUTPUT);
 pinMode(buttonpin, INPUT);
}

void loop(){
  reading=digitalRead(buttonpin);//reads the push button

    if(reading==HIGH){
       delay(100);
      ctr++;//if button is pressed, counter goes up by one
  }
    if(ctr%2!=0){

    digitalWrite(yellow,HIGH);
   

    }
    else
  //LEDs turn off when ctr is even
   // if (ctr%2==0){
  digitalWrite(yellow,LOW);

//}
}
