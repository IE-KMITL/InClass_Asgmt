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
//ถ้าใช้กระดาษสีขาววางกั้นห่าง 15 ซม. ใช้ไขควงหมุนจนไฟติด ถ้ามากกว่า 15 ซม.ไฟจะดับ
//สำหรับวัตถุอื่นๆ 5 อย่างได้แก่ โทรศัพท์ แผ่นรองเม้าส์ มือ กระเป๋าตังค์ และไอแพด พบว่าจะติดเมื่อมีตำแหน่งน้อยกว่า 15 ซม. เนื่องจากกระดาษสีขาวสะท้อนแสงเซนเซอร์ได้ดีกว่า
