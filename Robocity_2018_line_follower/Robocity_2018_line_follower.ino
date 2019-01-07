#define rmp 7
#define rmn 8
#define lmp 10
#define lmn 9
#define s1 2
#define s2 3
#define s3 4
#define s4 5
#define led 11

int s1r,s2r,s3r,s4r;
void setup() {
 pinMode(rmp,OUTPUT); // put your setup code here, to run once:
pinMode(rmn,OUTPUT);
pinMode(lmp,OUTPUT);
pinMode(lmn,OUTPUT);
pinMode(led,OUTPUT);
pinMode(s1,INPUT);
pinMode(s2,INPUT);
pinMode(s3,INPUT);
pinMode(s4,INPUT);
Serial.begin(9600);
}

void loop() {
 check();
 if((s1r==1)&&(s2r==1)&&(s3r==1)&&(s4r==1))
 {fm();check();}
 else if((s1r==0)&&(s2r==0)&&(s3r==1)&&(s4r==1))
      {
        while(s2r==0)
        {lm();check();}
        
      } 
 else if((s1r==1)&&(s2r==1)&&(s3r==0)&&(s4r==0))
        {while(s3r==0)
          {rm();check();}
        
        }
 else if((s1r==1)&&(s2r==1)&&(s3r==0)&&(s4r==1))
        {while(s3r==0)
          {rm();check();}
        
        }
 else if((s1r==0)&&(s2r==0)&&(s3r==0)&&(s4r==0))
        {st();
         for(int i=0;i<2;i++)
         {digitalWrite(led,LOW);
          delay(200);
         digitalWrite(led,HIGH);
         delay(200);
         digitalWrite(led,LOW);
         delay(200);
         }
         fm();
         delay(1000);
      
         check();
        }
 else if((s1r==1)&&(s2r==0)&&(s3r==1)&&(s4r==1))
        {
         while(s2r==0)
         {lm();check;} 
          
        }
 else if((s1r==0)&&(s2r==1)&&(s3r==1)&&(s4r==1))
       {
        while(s1r==0)
        {lm();check();}
        }
 else if((s1r==1)&&(s2r==1)&&(s3r==1)&&(s4r==0))
      {
        while(s4r==0)
        {rm();check();}
      }
 else if((s1r==0)&&(s2r==0)&&(s3r==0)&&(s4r==1))
       {
         while(s2r*s3r==0)
         {rm();check();}
       }
 else if((s1r==1)&&(s2r==0)&&(s3r==0)&&(s4r==0))
      {
        while(s2r*s3r==0)
        {lm();check();} 
      }
 else {
        while(s2r*s3r==0)
        {rm();check();}
      } 
       

}
void check()
{
  s1r=digitalRead(s1);
  s2r=digitalRead(s2);
  s3r=digitalRead(s3);
  s4r=digitalRead(s4);
  Serial.print(s1r);
  Serial.print("----");
  Serial.print(s2r);
  Serial.print("----");
  Serial.print(s3r);
  Serial.print("----");
  Serial.print(s4r);
  Serial.println(" ");
}
void fm()
{
  digitalWrite(rmp,HIGH);
  digitalWrite(rmn,LOW);
  digitalWrite(lmp,LOW);
  digitalWrite(lmn,HIGH);
  }

void bm()
{
  digitalWrite(rmp,LOW);
  digitalWrite(rmn,HIGH);
  digitalWrite(lmp,HIGH);
  digitalWrite(lmn,LOW);
  }
  
void rm()
{
  digitalWrite(rmp,LOW);
  digitalWrite(rmn,LOW);
  digitalWrite(lmp,LOW);
  digitalWrite(lmn,HIGH);
   }
   
void lm()
{
  digitalWrite(rmp,HIGH);
  digitalWrite(rmn,LOW);
  digitalWrite(lmp,LOW);
  digitalWrite(lmn,LOW);
   }
void st()
{
  digitalWrite(lmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,LOW);
  
}
