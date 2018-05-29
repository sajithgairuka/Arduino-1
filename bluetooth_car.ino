void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}
int spd=110;
int spdd=255;
void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
  char c=Serial.read();
  if(c=='1'){
              analogWrite(5,spdd);
                   analogWrite(10,spdd);
    }
    if(c=='2'){
                   analogWrite(6,LOW);
                   analogWrite(10,LOW); 
                    analogWrite(5,LOW);
                   analogWrite(9,LOW); 
      }
      if(c=='3'){
         analogWrite(9,spd);
                   analogWrite(5,spd); 
        }
        if(c=='4'){
           analogWrite(6,spd);
                   analogWrite(10,spd); 
          }
          if(c=='5'){
             analogWrite(6,spdd);
                    analogWrite(9,spdd); 
            }
  }
}
