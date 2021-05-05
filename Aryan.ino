#define trig 2
#define echo 4

void setup() {
  pinMode(5,OUTPUT); 
  pinMode(8,OUTPUT); //mortor control pins
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  long t = pulseIn(echo,HIGH);

  long inches = t / 74 / 2;
  long cm = t / 29 /2;

  Serial.print(inches);
  Serial.print("in \t");
  Serial.print(cm);
  Serial.println("cm");
  delay(100);

  if(cm>20){
    digitalWrite(5,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);}
  else {
  digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(5,HIGH);
  
  }
  
}
