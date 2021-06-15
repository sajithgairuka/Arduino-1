#define IR D7
#define LED D6

bool ir;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(IR, INPUT);
pinMode (LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

ir = digitalRead(IR);

if (ir == 0){
  Serial.print(ir);
  digitalWrite(LED, HIGH);
  }
  else if (ir == 1){
   Serial.print(ir); 
   digitalWrite(LED, LOW);
    }
}
