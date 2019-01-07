#include <LiquidCrystal.h>
LiquidCrystal lcd(2,7,8,10,11,12,13);

#define rmp 3
#define rmn 5
#define lmp 9
#define lmn 6
#define lir A0
#define rir 4
void setup() {
  pinMode(rmp,OUTPUT);
  pinMode(rmn,OUTPUT);
  pinMode(lmp,OUTPUT);
  pinMode(lmn,OUTPUT);
  pinMode(lir,INPUT);
  pinMode(rir,INPUT);
  lcd.begin(16,2);
}

void loop() {
  int lirr=digitalRead(lir);
  int rirr=digitalRead(rir);
  lcd.setCursor(0,0);
  lcd.print("lir= ");
  lcd.print(digitalRead(lir));
  lcd.setCursor(0,1);
  lcd.print("rir= ");
  lcd.print(digitalRead(rir));
  if(lirr==1&&rirr==1)
  {
    fm();
    lcd.setCursor(0,0);
    lcd.print("lir= ");
    lcd.print(digitalRead(lir));
    lcd.setCursor(0,1);
    lcd.print("rir= ");
    lcd.print(digitalRead(rir));
  }
  if(lirr==0&&rirr==1)
  { st();
    delay(10);
    while(lirr==0)
    {
      lm();
      lirr=digitalRead(lir);
      rirr=digitalRead(rir);
      lcd.setCursor(0,0);
      lcd.print("lir= ");
      lcd.print(digitalRead(lir));
      lcd.setCursor(0,1);
      lcd.print("rir= ");
      lcd.print(digitalRead(rir));
    }
  }
  if(lirr==1&&rirr==0)
  {
    st();
    delay(10);
    while(rirr==0)
    {
      rm();
      lirr=digitalRead(lir);
      rirr=digitalRead(rir);
      lcd.setCursor(0,0);
      lcd.print("lir= ");
      lcd.print(digitalRead(lir));
      lcd.setCursor(0,1);
      lcd.print("rir= ");
      lcd.print(digitalRead(rir));
    }
  }
  if(lirr==0&&rirr==0)
  {
    st();
    lcd.setCursor(0,0);
    lcd.print("lir= ");
    lcd.print(digitalRead(lir));
    lcd.setCursor(0,1);
    lcd.print("rir= ");
    lcd.print(digitalRead(rir));
  }

}
void fm()
{
  digitalWrite(lmp,HIGH);
  digitalWrite(lmn,LOW);
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,HIGH);
}
void bm()
{
   digitalWrite(lmp,LOW);
  digitalWrite(lmn,HIGH);
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
}
void lm()
{
   digitalWrite(rmn,LOW);
   digitalWrite(rmp,HIGH);
   digitalWrite(lmp,LOW);
   digitalWrite(lmn,LOW);
}
void rm()
{
   digitalWrite(lmp,HIGH);
   digitalWrite(lmn,LOW);
   digitalWrite(rmn,LOW);
   digitalWrite(rmp,LOW);
   
 }
void st()
{
   digitalWrite(lmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,LOW);
}

