/* © Robocell,CCA
 * This code is given during Autonomous robotics workshop organised  by Robocell,CCA on 21,22,23 Sept,2018. 
 * For details visit https://www.facebook.com/RobocellNITDgp/ 
 *  
 * FUNCTIONING:
 *This is the code for a simplest line follower which follows a black line on white surface using two IR sensors.
 *Adjust the threshold of the IR sensors for good working
 *
 */



#define rmp 10
#define rmn 9
#define lmp 7
#define lmn 8

#define rir 4
#define lir 5
//#define enl
//#define enr
int right_IR_reading;
int left_IR_reading;

void setup() {
  pinMode(rmp,OUTPUT);
  pinMode(rmn,OUTPUT);
  pinMode(lmp,OUTPUT);
  pinMode(lmn,OUTPUT);
  pinMode(lir,INPUT);
  pinMode(rir,INPUT);
  //analogWrite(enl,150);
  //analogWrite(enr,150);
  Serial.begin(9600);
  }

void loop() {
  
  check();
  if(left_IR_reading==0&&right_IR_reading==0)
  {
      forward();
  }
  else if(left_IR_reading==1&&right_IR_reading==0)
  {
      left();
  }
  else if(left_IR_reading==0&&right_IR_reading==1)
  {
      right();
  }
  else
  {
      stops();
  }

}

void check()
{ 
  right_IR_reading=digitalRead(rir);
  left_IR_reading=digitalRead(lir);
  Serial.print("left_IR_reading=");
  Serial.println(left_IR_reading);
  Serial.print("right_IR_reading=");
  Serial.println(right_IR_reading);
  }
void forward()
{
  digitalWrite(rmp,HIGH);
  digitalWrite(rmn,LOW);
  digitalWrite(lmp,LOW);
  digitalWrite(lmn,HIGH);
  }
  
void right()
{
  digitalWrite(rmp,LOW);
  digitalWrite(rmn,LOW);
  digitalWrite(lmp,LOW);
  digitalWrite(lmn,HIGH);
   }
   
void left()
{
  digitalWrite(rmp,HIGH);
  digitalWrite(rmn,LOW);
  digitalWrite(lmp,LOW);
  digitalWrite(lmn,LOW);
   }
void stops()
{
  digitalWrite(lmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,LOW);
  
}
