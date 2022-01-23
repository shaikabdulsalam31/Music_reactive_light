int soundsensor = A0; 
int bled = 7;
int rled=6;
int yled=5;
int gled=4;
int threshold=540;
// defining pin numbersvoid setup() 
void setup(){ 
  Serial.begin(9600);
  pinMode (soundsensor, INPUT);
  pinMode (bled, OUTPUT);
  pinMode (rled, OUTPUT);
  pinMode (yled, OUTPUT);
  pinMode (gled, OUTPUT);
}

void loop()
{
  int sensorvalue = analogRead (soundsensor);   
  int abs=analogRead(sensorvalue-threshold);
  //if the sound intensity is higher than threshold which is set by us, 
                                                          //then sensor would return the value as 1
  if (abs >=400&& abs<1000)                                    
  {
    analogWrite(bled,255);
    analogWrite(gled,175);
    delay(100);
    analogWrite(bled,0);
    analogWrite(gled,5);
    delay(100);
  }
  else if(abs>300&&abs<=400){
    analogWrite(rled,255);
    analogWrite(gled,155);
    analogWrite(bled,255);
    delay(400);
    analogWrite(rled,20);
    analogWrite(gled,25);
    analogWrite(bled,25);
    delay(300);
  }else if(abs>200&&abs<=300){
    analogWrite(rled,150);
    analogWrite(gled,175);
    analogWrite(bled,205);
    delay(1000);
    analogWrite(rled,25);analogWrite(yled,25);analogWrite(bled,25);
    delay(1000);
  }
  else if(abs>150&&abs<=200){
    analogWrite(rled,205);
    analogWrite(yled,205);
    analogWrite(bled,205);
    delay(1000);
    analogWrite(rled,15);analogWrite(yled,15);analogWrite(bled,15);
    delay(350);
  }
  else if(abs>100 && abs<=150){
    analogWrite(rled,255);analogWrite(gled,155);analogWrite(bled,255);analogWrite(yled,255);delay(100);
    analogWrite(rled,10);analogWrite(gled,10);analogWrite(bled,15);analogWrite(yled,10);delay(500);
  }
  else{
    analogWrite(bled,0);
  }
  
  Serial.println(abs);
  delay(100);
  
  
}
