int Left_motor_go=8;
  int Left_motor_back=7;

  int Right_motor_go=2;
  int Right_motor_back=4;

  int Left_motor_pwm=6;
  int Right_motor_pwm=5;

  int key=A0;

  const int TrackSensorLeftPin1=A1;
  const int TrackSensorLeftPin2=A2;
  const int TrackSensorRightPin1=A3;
  const int TrackSensorRightPin2=A4;

  int TrackSensorLeftValue1;
  int TrackSensorLeftValue2;
  int TrackSensorRightValue1;
  int TrackSensorRightValue2;


void setup() {
  pinMode(Left_motor_go,OUTPUT);
  pinMode(Left_motor_back,OUTPUT);
  pinMode(Right_motor_go,OUTPUT);
  pinMode(Right_motor_back,OUTPUT);

  pinMode(key,INPUT);

  pinMode(TrackSensorLeftPin1,INPUT);
  pinMode(TrackSensorLeftPin2,INPUT);
  pinMode(TrackSensorRightPin1,INPUT);
  pinMode(TrackSensorRightPin2,INPUT);

  digitalWrite(key,HIGH);

  digitalWrite(TrackSensorLeftPin1,HIGH);
  digitalWrite(TrackSensorLeftPin2,HIGH);
  digitalWrite(TrackSensorRightPin1,HIGH);
  digitalWrite(TrackSensorRightPin2,HIGH);

  key_scan();
  
}

void run(int left_speed,int right_speed)
{
  digitalWrite(Left_motor_go,HIGH);
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_pwm,left_speed);

  digitalWrite(Right_motor_go,HIGH);
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_pwm,right_speed);
}

void brake(int time)
{
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Left_motor_back,LOW);
  digitalWrite(Right_motor_go,LOW);
  digitalWrite(Right_motor_back,LOW);

  delay(time * 100);
}

void left(int left_speed,int right_speed)
{
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_pwm,left_speed);

  digitalWrite(Right_motor_go,HIGH);
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_pwm,right_speed);

}

void right(int left_speed,int right_speed)
{
  digitalWrite(Left_motor_go,HIGH);
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_pwm,left_speed);

  digitalWrite(Right_motor_go,LOW);
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_pwm,right_speed);

}

void spin_left(int left_speed,int right_speed)
{
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_pwm,left_speed);

  digitalWrite(Right_motor_go,HIGH);
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_pwm,right_speed);
}

void spin_right(int left_speed,int right_speed)
{
  digitalWrite(Left_motor_go,HIGH);
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_pwm,left_speed);

  digitalWrite(Right_motor_go,LOW);
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_pwm,right_speed);
}

void back(int time)
{
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_pwm,40);

  digitalWrite(Right_motor_go,LOW);
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_pwm,40);

  delay(time);
}

void key_scan()
{
  while(digitalRead(key));
  while(!digitalRead(key))
  {
    delay(10);
    if(digitalRead(key)==LOW)
    {
      delay(100);
      while(!digitalRead(key));
    }
  }
}

void loop() 
{
  TrackSensorLeftValue1=digitalRead(TrackSensorLeftPin1);
  TrackSensorLeftValue2=digitalRead(TrackSensorLeftPin2);
  TrackSensorRightValue1=digitalRead(TrackSensorRightPin1);
  TrackSensorRightValue1=digitalRead(TrackSensorRightPin2);

  if((TrackSensorLeftValue1==LOW||TrackSensorLeftValue2==LOW)&&TrackSensorRightValue2==LOW)
  {
    spin_right(250,250);
    delay(80);
  }

  else if(TrackSensorLeftValue1==LOW&&(TrackSensorRightValue1==LOW||TrackSensorRightValue2==LOW))
  {
    spin_left(250,250);
    delay(80);
  }

  else if(TrackSensorLeftValue1==LOW)
  {
    spin_left(230,230);
    delay(10);
  }

  else if(TrackSensorLeftValue2==LOW)
  {
    spin_left(230,230);
    delay(10);
  }

   else if(TrackSensorRightValue2==LOW)
  {
    spin_right(230,230);
    delay(10);
  }

  else if(TrackSensorLeftValue2==LOW&&TrackSensorRightValue1==HIGH)
  {
    left(0,220);
  }

  else if(TrackSensorLeftValue2==HIGH&&TrackSensorRightValue1==LOW)
  {
    right(0,220);
  }

  else if(TrackSensorLeftValue2==LOW&&TrackSensorRightValue1==LOW)
  {
    run(250,250);
  }

}
