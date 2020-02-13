
//infared pin
const int infa1=19;
const int infa2=23;
//ultrasonic pin

const int trigPin = 26;// pin trig is 12
const int echoPin = 25;//pin echo is 13

/*HCSR04 hc(12,13);//initialisation class HCSR04 (trig pin , echo pin)*/

// led

const int led1 = 18;
const int LED_BUILTIN=2;
//value holding
int lit1=1;
int lit2=1;
int velo=0;
int inputVal = 0;
bool sigright = 0;
bool sigleft = 0;
long duration;
int distance;
void setup() 
{
  pinMode(infa2,INPUT);                
  pinMode(infa1,INPUT); 
  
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);

  pinMode(led1,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
 
//value hoding
sigleft=digitalRead(infa1);
sigright=digitalRead(infa2);
lit1=digitalRead(led1);
lit2=digitalRead(LED_BUILTIN);

//infa1 left
 if(sigleft==HIGH)
 {digitalWrite(LED_BUILTIN,HIGH);
 }
 else if(sigleft==LOW);
 {
  digitalWrite(LED_BUILTIN,LOW);
 }
//infa2 right
 if(sigright==HIGH)
 {digitalWrite(led1,HIGH);
 }
 else if(sigright==LOW);
 {
  digitalWrite(led1,LOW);
 }
//ultrasonic front
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance and velocity
distance= duration*0.034/2;
velo=331.3+(0.606*33);//change teperature

//forward and backward
  if (distance<20)
  {digitalWrite(led1,LOW);
   digitalWrite(LED_BUILTIN,LOW);
  }
  else if (distance>20&&distance<40)
  {

    digitalWrite(led1,HIGH);
    digitalWrite(LED_BUILTIN,HIGH);
    delay(1000);                    
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(led1, LOW);
    delay(1000);
    /*digitalWrite(led1,HIGH);
    digitalWrite(LED_BUILTIN,HIGH);
    delayMicroseconds(10);*/
  
  }
  else if (distance>40)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(LED_BUILTIN,HIGH);
  }
  
   


{
Serial.print("Distance: ");
Serial.println(distance);

delay(200);
Serial.print("ledbuild-in: ");
Serial.println(lit2);

Serial.print("led:");
Serial.println(lit1);
delay(200);
}

}
