#include <Servo.h>

Servo myservo;


int y=0;
 
#include <Wire.h>
 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


const int place[]={13,12,11,10};

byte val[4];

const int in    =7;

const int out   =6;

int free_spc  =4;

int valin=0;

int valout=0;

int pos = 0;
 


void setup()
 {

  Serial.begin(9600);

  for(int i=0;i<4;i++)

     {pinMode(place[i], INPUT);
}
  
     
  pinMode(in, INPUT);

  pinMode(out, INPUT);

  
  myservo.attach(5); 
  
  
lcd.begin(16, 2);

  
  lcd.setCursor(0, 0);

  lcd.print("Welcome to");
  
  lcd.setCursor(0, 1);

  lcd.print("Hackathon");
  
  myservo.write(0);

  
  for (pos = 0; pos <= 40; pos += 1)
 {
 
    myservo.write(pos);
              
    delay(30);
                       
  }

  delay(3000);

  for (pos = 40; pos >= 0; pos -= 1)
 {
 
    myservo.write(pos);
             
    delay(30);                       
  
}

  lcd.clear();

  lcd.setCursor(0, 0);

}


void loop()
 {

 //******************************************************* 
  lcd.clear();
  lcd.setCursor(0, 0);

  lcd.print("P-LOT:");

  lcd.setCursor(0, 1);
  free_spc =4;

  for( y=0;y<4;y++)

     {      
      
val[y]=digitalRead(place[y]);

      if(val[y]==1)
{
  lcd.print(y+1);
  lcd.print("|");
  free_spc--; 

}            
   
}

  lcd.setCursor(10, 1);

  lcd.print("Free:");
  
  lcd.print(free_spc);
        
  valin=digitalRead(in);

  valout=digitalRead(out);

 
  if(free_spc<=0)
{
//free_spc = 0;
myservo.write(0);
delay(1000);
myservo.detach();

}

  
 //******************************************************** 
  
if(valout==LOW)
{
    
 
    
for (pos = 0; pos <= 40; pos += 1)
 {
 myservo.write(pos);
delay(30);
}
    
        
while(valout==LOW)
{
valout=digitalRead(out);
}
           
delay(1000);     
    
for (pos = 40; pos >= 0; pos -= 1)
 {
 myservo.write(pos);
delay(30);
}
       
}

//********************************************************       
  
if(valin ==LOW)
{
    
  
myservo.attach(5);   
  
for (pos = 0; pos <= 40; pos += 1)
 {
 myservo.write(pos);
delay(30);
}
  
        
while(valin ==LOW)
{
valin=digitalRead(in);
}
            
  
delay(4000);      
  
for (pos = 40; pos >= 0; pos -= 1) 
{ 
myservo.write(pos);
delay(30);
}        
        
}



}



