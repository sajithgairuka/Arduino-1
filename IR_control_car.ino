#include <IRremote.h>
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
   Serial.begin(9600);
   irrecv.enableIRIn(); // Start the receiver
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
 
}
int spd=110;
void loop() {
  if (irrecv.decode(&results)) {
   Serial.println(results.value, DEC); 
     irrecv.resume(); // Receive the next value
  } 
delay(100);
 
      long val=results.value;  
              
     if(val==49214)
     {
                 //issarahata-2 button
                  digitalWrite(5,HIGH);
                  digitalWrite(10,HIGH);          
     }
          if(val==49246)
          {      
                      //stop-5 button
                   digitalWrite(6,LOW);
                   digitalWrite(10,LOW); 
                    digitalWrite(5,LOW);
                   digitalWrite(9,LOW); 
          }
            
                  if(val==49242){
                    //dakunata-6 button
                 analogWrite(9,spd);
                   analogWrite(5,spd); 
                   }
                   
                   if(val== 49370 )
                   {            
                        //wampaththa-4 button
                  analogWrite(6,spd);
                   analogWrite(10,spd); 
                   }
                   
                    if(val==49374){
                      //pitipassa-8 button
                   digitalWrite(6,HIGH);
                   digitalWrite(9,HIGH);             
     }             
  
}
