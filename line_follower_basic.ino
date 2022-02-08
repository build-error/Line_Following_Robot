/*
 * Author - Aryan Singh (build_error)
 * link to the project video - https://www.youtube.com/watch?v=_W4bohFWdrs
 */
int mid_tracker=4,left_tracker=10,right_tracker=2;
int ENA=5,ENB=6,IN1=7,IN2=8,IN3=9,IN4=11;

void setup() {
  // put your setup code here, to run once:
  pinMode(mid_tracker,INPUT);
  pinMode(left_tracker,INPUT);
  pinMode(right_tracker,INPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  Serial.begin(9600);
}

enum dir {f=1,b,l,r,s,ll,lr};

void motor_drive(int dir,int speed_bot)
{
  int motor_status[5][4]={{1,0,0,1},{0,1,1,0},{0,1,0,1},{1,0,1,0},{0,0,0,0}};
  int final_speed=(int)((1.65*speed_bot)+95);
  switch (dir)
  {
    case 1:
    digitalWrite(IN1,motor_status[0][0]);
    digitalWrite(IN2,motor_status[0][1]);
    digitalWrite(IN3,motor_status[0][2]);
    digitalWrite(IN4,motor_status[0][3]);
    analogWrite(ENA,final_speed);
    analogWrite(ENB,final_speed);
    break;

    case 2:
    digitalWrite(IN1,motor_status[1][0]);
    digitalWrite(IN2,motor_status[1][1]);
    digitalWrite(IN3,motor_status[1][2]);
    digitalWrite(IN4,motor_status[1][3]);
    analogWrite(ENA,final_speed);
    analogWrite(ENB,final_speed);
    break;

    case 3:
    digitalWrite(IN1,motor_status[2][0]);
    digitalWrite(IN2,motor_status[2][1]);
    digitalWrite(IN3,motor_status[2][2]);
    digitalWrite(IN4,motor_status[2][3]);
    analogWrite(ENA,final_speed);
    analogWrite(ENB,final_speed);
    break;

    case 4:
    digitalWrite(IN1,motor_status[3][0]);
    digitalWrite(IN2,motor_status[3][1]);
    digitalWrite(IN3,motor_status[3][2]);
    digitalWrite(IN4,motor_status[3][3]);
    analogWrite(ENA,final_speed);
    analogWrite(ENB,final_speed);
    break;

    case 5:
    digitalWrite(IN1,motor_status[4][0]);
    digitalWrite(IN2,motor_status[4][1]);
    digitalWrite(IN3,motor_status[4][2]);
    digitalWrite(IN4,motor_status[4][3]);
    analogWrite(ENA,final_speed);
    analogWrite(ENB,final_speed);
    break;

    case 6:
    digitalWrite(IN1,motor_status[3][0]);
    digitalWrite(IN2,motor_status[3][1]);
    digitalWrite(IN3,motor_status[3][2]);
    digitalWrite(IN4,motor_status[3][3]);
    analogWrite(ENA,final_speed);
    analogWrite(ENB,0);
    break;

    case 7:
    digitalWrite(IN1,motor_status[2][0]);
    digitalWrite(IN2,motor_status[2][1]);
    digitalWrite(IN3,motor_status[2][2]);
    digitalWrite(IN4,motor_status[2][3]);
    analogWrite(ENA,0);
    analogWrite(ENB,final_speed);
    break;
  }
}

void loop() {
  int dir_prev=l;
  // put your main code here, to run repeatedly:
//  if(digitalRead(mid_tracker)==0 && digitalRead(left_tracker)==1 && digitalRead(right_tracker)==1)
//  {
//    motor_drive(f,20);
//  }
//  else if(digitalRead(mid_tracker)==1 && digitalRead(left_tracker)==1 && digitalRead(right_tracker)==0)
//  {
//    motor_drive(r,60);
//  }
//  else if(digitalRead(mid_tracker)==1 && digitalRead(left_tracker)==0 && digitalRead(right_tracker)==1)
//  {
//    motor_drive(l,60);
//  }
  while (digitalRead(mid_tracker)==0 && digitalRead(left_tracker)==1 && digitalRead(right_tracker)==1)
  {
    motor_drive(f,20);
  }

  while (digitalRead(mid_tracker)==1 && digitalRead(left_tracker)==0 && digitalRead(right_tracker)==1)
  {
    motor_drive(r,60);
    dir_prev=r;
  }

  while (digitalRead(mid_tracker)==1 && digitalRead(left_tracker)==1 && digitalRead(right_tracker)==0)
  {
    motor_drive(l,60);
    dir_prev=l;
  }

  //Special Code
  while (digitalRead(mid_tracker)==1 && digitalRead(left_tracker)==1 && digitalRead(right_tracker)==1)
  {
    if (dir_prev==r) motor_drive(l,60);
    if (dir_prev==l) motor_drive(r,60);
  }
}
