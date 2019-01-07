#include <LiquidCrystal.h>
LiquidCrystal lcd(9,7,8,10,11,12,13);

#define rmp 2
#define rmn 4
#define lmp A2
#define lmn 6
#define lir A0
#define rir A1
#define enl 3
#define enr 5

void setup() {
  pinMode(rmp,OUTPUT);
  pinMode(rmn,OUTPUT);
  pinMode(lmp,OUTPUT);
  pinMode(lmn,OUTPUT);
  pinMode(lir,INPUT);
  pinMode(rir,INPUT);
  pinMode(enl,OUTPUT);
  pinMode(enr,OUTPUT);
  lcd.begin(16,2);
}

void loop() {
  int lirr=digitalRead(lir);
  int rirr=digitalRead(rir);
  lcd.setCursor(0,0);
  lcd.print("lir= ");
  lcd.print(lirr);
  lcd.setCursor(0,1);
  lcd.print("rir= ");
  lcd.print(rirr);
  if(lirr==1&&rirr==1)
  {
    while(lirr==1&&rirr==1)
    {
      fm();
      int lirr=digitalRead(lir);
      int rirr=digitalRead(rir);
      lcd.setCursor(0,0);
     lcd.print("lir= ");
     lcd.print(lirr);
     lcd.setCursor(0,1);
     lcd.print("rir= ");
      lcd.print(rirr);
    }
  }
  else if(lirr==0&&rirr==1)
  { st();
    delay(100);
    while(lirr==0)
    {
      lm();
      int lirr=digitalRead(lir);
      int rirr=digitalRead(rir);
      lcd.setCursor(0,0);
      lcd.print("lir= ");
      lcd.print(lirr);
      lcd.setCursor(0,1);
      lcd.print("rir= ");
      lcd.print(rirr);
    }
  }
  else if(lirr==1&&rirr==0)
  {
    st();
    delay(100);
    while(rirr==0)
    {
      rm();
      int lirr=digitalRead(lir);
      int rirr=digitalRead(rir);
      lcd.setCursor(0,0);
      lcd.print("lir= ");
      lcd.print(lirr);
      lcd.setCursor(0,1);
      lcd.print("rir= ");
      lcd.print(rirr);
    }
  }
  else if(lirr==0&&rirr==0)
  {
    while(lirr==0&&rirr==0)
    {
      st();
      int lirr=digitalRead(lir);
      int rirr=digitalRead(rir);
      lcd.setCursor(0,0);
      lcd.print("lir= ");
      lcd.print(lirr);
      lcd.setCursor(0,1);
      lcd.print("rir= ");
      lcd.print(rirr);
    }
  }

}
void fm()
{
  digitalWrite(lmp,HIGH);
  digitalWrite(lmn,LOW);
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,HIGH);
  analogWrite(enl,100);
  analogWrite(enr,100);
}
void bm()
{
   digitalWrite(lmp,LOW);
  digitalWrite(lmn,HIGH);
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
  analogWrite(enl,100);
  analogWrite(enr,100);
}
void lm()
{
   digitalWrite(rmn,LOW);
   digitalWrite(rmp,HIGH);
   digitalWrite(lmp,LOW);
   digitalWrite(lmn,LOW);
   analogWrite(enl,0);
   analogWrite(enr,60);
}
void rm()
{
   digitalWrite(lmp,HIGH);
   digitalWrite(lmn,LOW);
   digitalWrite(rmn,LOW);
   digitalWrite(rmp,LOW);
   analogWrite(enl,60);
   analogWrite(enr,0);
 }
void st()
{
   digitalWrite(lmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,LOW);
  analogWrite(enl,0);
  analogWrite(enr,0);
}



