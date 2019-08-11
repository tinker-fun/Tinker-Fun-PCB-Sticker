//PCB Sticker with 8 LEDs and a Attiny85
//Website: http://Tinker-Fun.com
//Instagram: https://www.instagram.com/tinker.fun/
//YouTube: https://www.youtube.com/tinkerfun
//Github: https://github.com/tinker-fun

//ATiny 85 internal 8mhz
#include "PinChangeInterrupt.h"

int a;

//LED Output Pins
#define ledCouple1 1
#define ledCouple2 0

//Mode Button Pin
#define modeButton 2

int counter = 1;

int analogFade = 0;

volatile boolean changeCounter = false;


//The setup function runs once when you press reset or power the board
void setup() {
  pinMode(ledCouple1, OUTPUT);
  digitalWrite(ledCouple1, LOW);
  pinMode(ledCouple2, OUTPUT);
  digitalWrite(ledCouple2, LOW);

  //Initialize digital pin for the Mode Button as an input (Hardware pullup resistor)
  pinMode(modeButton, INPUT);
  digitalWrite(modeButton, HIGH);
  attachPCINT(modeButton, ButtonInterrupt, FALLING);
 }


//The loop function runs over and over again forever
void loop() {

  if (changeCounter)
  {
    detachPCINT(modeButton);
    counter++;
    changeCounter = false;
    delay(200);
   
    attachPCINT(modeButton, ButtonInterrupt, FALLING);
  }
  switch (counter)
  {
    case 1:    
      analogWrite(ledCouple1, 150);
      analogWrite(ledCouple2, 150);
      break;

    case 2:
      a = 0;
      while (a <= 254)
      {
        analogWrite(ledCouple1, a);
        analogWrite(ledCouple2, a);
        a++;
        delay(2);
      }
      while (a >= 0)
      {
        analogWrite(ledCouple1, a);
        analogWrite(ledCouple2, a);
        a--;
        delay(2);
      }
      break;
    case 3:
      a = 0;
      while (a <= 254)
      {
        analogWrite(ledCouple1, a);
        analogWrite(ledCouple2, 0);
        a++;
        delay(2);
      }
      while (a >= 0)
      {
        analogWrite(ledCouple1, a);
        analogWrite(ledCouple2, 0);
        a--;
        delay(2);
      }
       while (a <= 254)
      {
        analogWrite(ledCouple1, 0);
        analogWrite(ledCouple2, a);
        a++;
        delay(2);
      }
      while (a >= 0)
      {
        analogWrite(ledCouple1, 0);
        analogWrite(ledCouple2, a);
        a--;
        delay(2);
      }
      break;
    case 4:   
      digitalWrite(ledCouple1, HIGH);
      digitalWrite(ledCouple2, HIGH);
      delay(500);
      digitalWrite(ledCouple1, LOW);
      digitalWrite(ledCouple2, LOW);
      delay(300);
      break;
    case 5:  
      digitalWrite(ledCouple1, HIGH);
      digitalWrite(ledCouple2, LOW);
      delay(300);
      digitalWrite(ledCouple1, LOW);
      digitalWrite(ledCouple2, HIGH);
      delay(300);
      break;
    case 6:     
      digitalWrite(ledCouple1, HIGH);
      digitalWrite(ledCouple2, LOW);
      delay(150);
      digitalWrite(ledCouple1, LOW);
      digitalWrite(ledCouple2, HIGH);
      delay(150);
      break;
    case 7:     
      digitalWrite(ledCouple1, HIGH);
      digitalWrite(ledCouple2, LOW);
      delay(60);
      digitalWrite(ledCouple1, LOW);
      digitalWrite(ledCouple2, LOW);
      delay(60);
      break;
    case 8:      
      digitalWrite(ledCouple1, HIGH);
      digitalWrite(ledCouple2, LOW);
      delay(5);
      digitalWrite(ledCouple1, LOW);
      digitalWrite(ledCouple2, LOW);
      delay(10);
      break;
    case 9:
      counter = 1;
      break;
  }


}

void ButtonInterrupt()
{
  changeCounter = true;
}
