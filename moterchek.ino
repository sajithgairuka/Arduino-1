void setup() {
// put your setup code here, to run once: Arduino
pinMode(7,OUTPUT);//issarahata dakunupaththe moter eka
pinMode(8,OUTPUT);//pitipassata dakunupaththa moter eka
pinMode(9,OUTPUT);//pitipassata wampaththe moter eka
pinMode(10,OUTPUT);//issarahata wampaththe moter eka
pinMode(6,OUTPUT);//dakunupaththa
pinMode(5,OUTPUT);//wampaththa
/*//nodemcu
pinMode(4,OUTPUT);// issarahata dakunupaththa moter eka
pinMode(2,OUTPUT);// pitipassata dakunupaththa moter eka
pinMode(5,OUTPUT);//wampaththe pitipassata
pinMode(0,OUTPUT);//wampaththa issarahata
*/
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(5,HIGH);
}
