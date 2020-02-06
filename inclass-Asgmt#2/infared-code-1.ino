const int ProxSensor=27;
int inputVal = 0;

void setup() 
{                
 
  pinMode(ProxSensor,INPUT);    //Pin 2 is connected to the output of proximity sensor
  Serial.begin(9600);
}

void loop() 
{
 
  
   if(digitalRead(ProxSensor)==HIGH)
{

Serial.println("sensor not detected object"" ");
delay(200);    // wait for a second
}
else 
{
Serial.println("sensor detected object");

}
}
