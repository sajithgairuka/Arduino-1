// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int Spin=8;//sensor pin out
int LED=6;
int cfl=7;//relay
int pinSpeaker = 10;//Set up a speaker on a PWM pin (digital 9, 10, or 11)

void setup() {
 lcd.begin(16, 2);
pinMode(Spin,INPUT);
pinMode(LED,OUTPUT);
pinMode(pinSpeaker, OUTPUT);
pinMode(cfl, OUTPUT);
}
void loop() {
int x=digitalRead(Spin);
 lcd.setCursor(0,0);
if(x==0){
  digitalWrite(LED,LOW);
  digitalWrite(cfl,HIGH);
 playTone(0, 0);
lcd.print("Secure !");
  }
  if(x==1){
    digitalWrite(LED,HIGH);
   digitalWrite(cfl,LOW);
   playTone(200, 450);
   lcd.print(" Detected Some! ");
    }
}
void playTone(long duration, int freq) {
    duration *= 1000;
    int period = (1.0 / freq) * 1000000;
    long elapsed_time = 0;
    while (elapsed_time < duration) {
        digitalWrite(pinSpeaker,HIGH);
        delayMicroseconds(period / 2);
        digitalWrite(pinSpeaker, LOW);
        delayMicroseconds(period / 2);
        elapsed_time += (period);
    }
}
