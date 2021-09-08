int sensorVal = 0;
int count = 0;
int buzzer = 11; 

void setup()
{
  pinMode(A0, INPUT);
  pinMode(10, OUTPUT);
  pinMode(buzzer, OUTPUT); 
  Serial.begin(9600);
}

void loop()
{
  sensorVal = analogRead(A0);
  
  Serial.print("Sensor Value: ");
  Serial.println(sensorVal);
  Serial.print("Counter: ");
  Serial.println(count);
 
  analogWrite(11, map(sensorVal, 0, 1023, 0, 255));
  delay(1000); 


  if(sensorVal > 0 )
  {
    count++;
  }
  delay(1000);

  if(count>5)
  {
   Serial.println("Alarm is on");
   Serial.println("The room is full");
   for( int i = 0; i<6;i++)
   {
    digitalWrite(10, HIGH);
    tone(buzzer, 2900); 
    delay(1000);
    digitalWrite(10, LOW);
    noTone(buzzer);     
    delay(1000);        
   }
    exit(1);
           
  }
  else
  {
    noTone(buzzer);     
    
  }
  if(count<=0)
  {
    Serial.print("The room is empty \n");
    count = 0;
  }  
}
