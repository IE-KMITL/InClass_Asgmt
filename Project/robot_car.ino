#include <analogWrite.h>


//sensor ir
const int irSensor1=7;
const int irSensor2=12;
// ir color
const int ircolor1 = 6;
const int button = 0;   //ir collor 
//int ledPin = A2;      // select the pin for the LED
// infared detected color
int analogInPin = A0;
int ledValue = 0;

// Motor A
int enA = 5;
int in1 = 8;
int in2 = 2;

// Motor B

int enB = 3;
int in3 = 10;
int in4 = 11;

// ulra sensor  defines pins numbers
//front
const int trigPin1 = 9;
const int echoPin1= 13;
//back
const int trigPin2 =1 ;
const int echoPin2 = 4;
//led pin 
//vavul holder
  int duration1, distance1;
  int duration2, distance2;
  bool reading;//push button state
  int ctr=0;
  int sensorValue = 0;

void setup() {
//  pinMode(Sensor,INPUT);    
  Serial.begin(9600);

  // Set all the motor control pins to outputs
  //motor
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  //sensor
  pinMode(irSensor1, INPUT); //left side
  pinMode(irSensor2, INPUT); //right side
  pinMode(ircolor1, INPUT);  //digital 
   // pinMode(ircolor2Sensor,OUTPUT);//analog front under
  pinMode(trigPin1, OUTPUT); //front
  pinMode(trigPin2, OUTPUT); //back
  pinMode(echoPin1, INPUT);  //front
  pinMode(echoPin2, INPUT); //back

 // pinMode(led, OUTPUT);
  pinMode(button, INPUT);

  
}
//wheel 
void backwardwheel()

{

  // This function will run the motors in both directions at a fixed speed

  // Turn on motor A

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  // Set speed to 200 out of possible range 0~255

  analogWrite(enA, 255);

  // Turn on motor B

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // Set speed to 200 out of possible range 0~255

  analogWrite(enB, 255);

}
void slowlyforwardwheel()

{

  // This function will run the motors in both directions at a fixed speed

  // Turn on motor A

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set speed to 200 out of possible range 0~255

  analogWrite(enA, 180);

  // Turn on motor B

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set speed to 200 out of possible range 0~255

  analogWrite(enB, 180);

}
void forwardwheel()

{

  // This function will run the motors in both directions at a fixed speed

  // Turn on motor A

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set speed to 200 out of possible range 0~255

  analogWrite(enA, 255);

  // Turn on motor B

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set speed to 200 out of possible range 0~255

  analogWrite(enB, 255);

}
void stopwheel()

  {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW); 
  }

void defender(){
  
    if (distance1 <= 10&& distance1 >= 0 ) 
    {
     
      forwardwheel();
    }
    else if(distance2 <= 10&& distance2 >= 0 )
    {
      backwardwheel();
     }
     //ir sensor face enemy
    else if(digitalRead(irSensor1)==HIGH)
    {
      stopwheel();
     }
    else {
      for (int i = 0; i <= 5; i++)

      {
       forwardwheel();
       delay (1000);
       } 
      for (int j = 0; j <= 5; j++)
      {

      backwardwheel();
      delay (1000);
      }
    }
     }
void offender(){
  
    if (digitalRead(irSensor1)==HIGH||digitalRead(irSensor2)==HIGH) 
    {
     
      for (int j = 0; j <= 5; j++)
      {

      backwardwheel();
      delay (1000);
      }
    }
    //front ultrasonic not detect
    else if(distance1 >= 10 )
    {
      slowlyforwardwheel();
     }
     //ir sensor face enemy
  
     
   
     }


void loop() {
  // Duration will be the input pulse width and distance will be the distance to the obstacle in centimeters
 
  // Output pulse with 1ms width on trigPin
  digitalWrite(trigPin1, HIGH); 
  delay(1);
  digitalWrite(trigPin1, LOW);
  // Measure the pulse input in echo pin
  duration1 = pulseIn(echoPin1, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance1= (duration1/2) / 29.1;
//  sensorValue = analogRead(sensorPin);
  //ledValue = analogRead(ledPin);
    digitalWrite(trigPin2, HIGH); 
  delay(1);
  digitalWrite(trigPin2, LOW);
  // Measure the pulse input in echo pin
  duration2 = pulseIn(echoPin2, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance2 = (duration2/2) / 29.1;
//  sensorValue = analogRead(sensorPin);
  //ledValue = analogRead(ledPin);

  //win condition
   sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  
  // change the analog out value:
  //analogWrite(analogOutPin, outputValue);
   if (sensorValue>100&&sensorValue<200){
    
      backwardwheel();
      
   }


  //stategy select
  reading=digitalRead(button);//reads the push button

    if(reading==HIGH){
       delay(100);
      ctr++;//if button is pressed, counter goes up by one
  }
    if(ctr%2!=0){

    defender();
   

    }
    else
    //LEDs turn off when ctr is even
      // if (ctr%2==0){
    offender();

}
