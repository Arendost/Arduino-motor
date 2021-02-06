#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(0,1);
LiquidCrystal lcd(2,3,4,5,6,7);
char inChar;
int vel=0;
int pinIzq=10;
int pinDer=9;


void pausa(unsigned int milisegundos)
{
  volatile unsigned long compara=0;
  volatile int contador =0;
  do
  {
    if (compara!=millis())
    {
      contador++;
      compara=millis();
    }
  }
  while(contador<=milisegundos);
  return;
}


void setup()
{
  lcd.begin(16,2);

  lcd.setCursor(0,0);
  lcd.print("Motor");
  pausa(1000);
  lcd.setCursor(0,0); 
  lcd.print("        ");
  pausa(1);
  lcd.setCursor(0,0);
  lcd.print("Control Motor");
  mySerial.begin(9600);
  pinMode(pinIzq, OUTPUT);
  pinMode(pinDer, OUTPUT);
}

void loop(){
while (mySerial.available()>0){

    inChar= (mySerial.read());
    lcd.setCursor(0,1);
    lcd.print("Recibiendo=");
    lcd.setCursor(13,1);
    lcd.print(inChar);
    
    
switch (inChar)
{
 case '0': vel=0;
 break;

 case '1': vel=20;
 break;

 case '2': vel=54;
 break;

 case '3': vel=88;
 break;

 case '4': vel=114;
 break;

 case '5': vel=142;
 break;

 case '6': vel=171;
 break;

 case '7': vel=199;
 break;

 case '8': vel=228;
 break;

 case '9': vel=255;
 break;

 case 'U': vel=vel+20;
 break;

 case 'D': vel=vel-20;
 break;
      
 case 'R': 
 analogWrite(pinIzq, 0);
 analogWrite(pinDer, 0);
 pausa(1000);
 analogWrite(pinIzq, 0);
 analogWrite(pinDer, vel);
 
 break;

 case 'L':
 analogWrite(pinIzq, 0);
 analogWrite(pinDer, 0);
 pausa(1500);
 analogWrite(pinIzq, vel);
 analogWrite(pinDer, 0);
 break;

 case 'X':
 pausa(1500);
 analogWrite(pinIzq, 0);
 analogWrite(pinDer, 0);
 break;
    
}
}
} 
