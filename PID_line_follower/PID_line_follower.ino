#define L1 2  //First IR sensor  from left (Green)
#define L2 3  //Purple
#define L3 4  //Yellow
#define L4 5  //Black
#define L5 6  //Brown
#define L6 7  //Blue
#define L7 8  //Grey
#define L8 9  //Orange
#define lmp 10  //left motor positive
#define lmn 11  //left motor negative
#define rmp 12  //right motor positive ;assuming that when lmp & rmp is high and lmn & rmn is low then bot moves forward; although it is conceptually wrong but eassy to think
#define rmn 13  //right motor negative
#define rmen A0   //right motor enable
#define lmen A1   //left motor enable

float PID_value,kp,ki,kd,j,k;
int L1r,L2r,L3r,L4r,L5r,L6r,L7r,L8r,error,prev_error,i,d;

void setup() {
  Serial.begin(9600);// put your setup code here, to run once:
  pinMode(L1,INPUT);
  pinMode(L2,INPUT);
  pinMode(L3,INPUT);
  pinMode(L4,INPUT);
  pinMode(L5,INPUT);
  pinMode(L6,INPUT);
  pinMode(L7,INPUT);
  pinMode(L8,INPUT);
  pinMode(lmp,OUTPUT);
  pinMode(lmn,OUTPUT);
  pinMode(rmp,OUTPUT);
  pinMode(rmn,OUTPUT);
  ki=0;
  kp=10;
  kd=0;
  i=0;
  d=0;
  error=0;
  prev_error=0;
  PID_value=0;
  j=135;
  k=135;
}

void loop() {
 check(); // put your main code here, to run repeatedly:
//printIR();
if((L1r==1)&&(L2r==1)&&(L3r==1)&&(L4r==1)&&(L5r==1)&&(L6r==1)&&(L7r==1)&&(L8r==1))
{error=0;
//about_turn();
}
//else if((L1r==0)&&(L2r==0)&&(L3r==0)&&(L4r==0)&&(L5r==0)&&(L6r==0)&&(L7r==0)&&(L8r==0)){st();}
else if((L1r==0)&&(L2r==1)&&(L3r==1)&&(L4r==1)&&(L5r==1)&&(L6r==1)&&(L7r==1)&&(L8r==1)){error=-6;}
else if((L1r==0)&&(L2r==0)&&(L3r==1)&&(L4r==1)&&(L5r==1)&&(L6r==1)&&(L7r==1)&&(L8r==1)){error=-5;}
else if((L1r==1)&&(L2r==0)&&(L3r==1)&&(L4r==1)&&(L5r==1)&&(L6r==1)&&(L7r==1)&&(L8r==1)){error=-4;}
else if((L1r==1)&&(L2r==0)&&(L3r==0)&&(L4r==1)&&(L5r==1)&&(L6r==1)&&(L7r==1)&&(L8r==1)){error=-3;}
else if((L1r==1)&&(L2r==1)&&(L3r==0)&&(L4r==1)&&(L5r==1)&&(L6r==1)&&(L7r==1)&&(L8r==1)){error=-2;}
else if((L1r==1)&&(L2r==1)&&(L3r==0)&&(L4r==0)&&(L5r==1)&&(L6r==1)&&(L7r==1)&&(L8r==1)){error=-1;}
else if((L1r==1)&&(L2r==1)&&(L3r==1)&&(L4r==0)&&(L5r==0)&&(L6r==1)&&(L7r==1)&&(L8r==1)){error=0;}
else if((L1r==1)&&(L2r==1)&&(L3r==1)&&(L4r==1)&&(L5r==0)&&(L6r==0)&&(L7r==1)&&(L8r==1)){error=1;}
else if((L1r==1)&&(L2r==1)&&(L3r==1)&&(L4r==1)&&(L5r==1)&&(L6r==0)&&(L7r==1)&&(L8r==1)){error=2;}
else if((L1r==1)&&(L2r==1)&&(L3r==1)&&(L4r==1)&&(L5r==1)&&(L6r==0)&&(L7r==0)&&(L8r==1)){error=3;}
else if((L1r==1)&&(L2r==1)&&(L3r==1)&&(L4r==1)&&(L5r==1)&&(L6r==1)&&(L7r==0)&&(L8r==1)){error=4;}
else if((L1r==1)&&(L2r==1)&&(L3r==1)&&(L4r==1)&&(L5r==1)&&(L6r==1)&&(L7r==0)&&(L8r==0)){error=5;}
else if((L1r==1)&&(L2r==1)&&(L3r==1)&&(L4r==1)&&(L5r==1)&&(L6r==1)&&(L7r==1)&&(L8r==0)){error=6;}


i=i+error;
if(error==0){i=0;}
if(abs(error)>100){i=0;}
d=error-prev_error;
prev_error=error;

PID_value=(kp*error)+(ki*i)+(kd*d);

j=135-PID_value;
k=135+PID_value; // 150 is speed at zero error

digitalWrite(rmp,HIGH);
digitalWrite(rmn,LOW);
digitalWrite(lmp,HIGH);
digitalWrite(lmn,LOW);

analogWrite(rmen,j);
analogWrite(lmen,k);

printData();
}

void check(){

  L1r=digitalRead(L1);
  L2r=digitalRead(L2);
  L3r=digitalRead(L3);
  L4r=digitalRead(L4);
  L5r=digitalRead(L5);
  L6r=digitalRead(L6);
  L7r=digitalRead(L7);
  L8r=digitalRead(L8);
  
}

void printIR(){

Serial.println(" ");
Serial.print("IR Left to Right     ");
Serial.print(L1r);
Serial.print("     ");
Serial.print(L2r);
Serial.print("     ");
Serial.print(L3r);
Serial.print("     ");
Serial.print(L4r);
Serial.print("     ");
Serial.print(L5r);
Serial.print("     ");
Serial.print(L6r);
Serial.print("     ");
Serial.print(L7r);
Serial.print("     ");
Serial.print(L8r);
Serial.println("     ");

}

void printData(){

Serial.println(" ");
Serial.print("  error= ");
Serial.print(error);
Serial.print("   i= ");
Serial.print(i);
Serial.print("   d= ");
Serial.print(d);
Serial.print("   PID= ");
Serial.println(PID_value);

}

void about_turn(){

digitalWrite(rmp,HIGH);
digitalWrite(rmn,LOW);
digitalWrite(lmp,LOW);
digitalWrite(lmn,HIGH);
delay(500);
st();

}

void st(){

digitalWrite(rmp,LOW);
digitalWrite(rmn,LOW);
digitalWrite(lmp,LOW);
digitalWrite(lmn,LOW);  

}
