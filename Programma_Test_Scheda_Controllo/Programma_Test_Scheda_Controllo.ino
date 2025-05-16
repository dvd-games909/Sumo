/*
Programma di test per il funzionamento scheda di controllo del robot SUMO
Questo programma programma verifica il funzionamento del circuito integrato L293D mobilitando i motori
e verifica il funzionamento dei componenti connessi sulla scheda qual led e pulsanti
*/
#define Pulsante1 9
#define Pulsante2 10
#define Led1 A0
#define Led2 8
#define IN1 2
#define IN2 4
#define EN1 3
#define IN3 6
#define IN4 7
#define EN2 5
String stringa="";
char c=' ';
void setup() {
Serial.begin(9600);
pinMode(Pulsante1,INPUT);
pinMode(Pulsante2,INPUT);
pinMode(Led1,OUTPUT);
pinMode(Led2,OUTPUT);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(EN1,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
pinMode(EN2,OUTPUT);
digitalWrite(Led1,LOW);
digitalWrite(Led2,LOW);
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(EN1,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
digitalWrite(EN2,LOW);
Serial.println("Programma di test per la scheda di controllo del robot SUMO");
delay(2000);
Serial.println("Test led");
Serial.println("Led1 acceso");
digitalWrite(Led1,HIGH);
delay(1000);
Serial.println("Led2 acceso");
digitalWrite(Led2,HIGH);
delay(1000);
Serial.println("Led1 spento");
digitalWrite(Led1,LOW);
delay(1000);
Serial.println("Led2 spento");
digitalWrite(Led2,LOW);
delay(1000);
Serial.println("Test Motori");
delay(3000);
Serial.println("Motore 1 acceso");
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(EN1,HIGH);
delay(1000);
Serial.println("Motore 2 acceso");
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
digitalWrite(EN2,HIGH);
delay(2000);
Serial.println("Motore 1 velocità ridotta");
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
analogWrite(EN1,150);
delay(1000);
Serial.println("Motore 2 velocità ridotta");
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
analogWrite(EN2,150);
delay(2000);
Serial.println("Inversione motore 1");
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(EN1,HIGH);
delay(1000);
Serial.println("Inversione motore 2");
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
digitalWrite(EN2,HIGH);
delay(2000);
Serial.println("Motore 1 velocità ridotta");
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
analogWrite(EN1,150);
delay(1000);
Serial.println("Motore 2 velocità ridotta");
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
analogWrite(EN2,150);
delay(2000);
Serial.println("Motore 1 spento");
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(EN1,LOW);
delay(1000);
Serial.println("Motore 2 spento");
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
digitalWrite(EN2,LOW);
delay(1000);
Serial.println("Test Pulsanti");
Serial.println("Premere il pulsante 1");
int i=0;
bool result=false;
while(digitalRead(Pulsante1)==HIGH && i<3000){
i++;
delay(1);
}
if(digitalRead(Pulsante1)==LOW){
  result=true;
}
if(result){
  Serial.println("Pulsante1 OK");
}
else{
  Serial.println("Pulsante1 ERR");
}
delay(1000);
Serial.println("Premere il pulsante 2");
i=0;
result=false;
while(digitalRead(Pulsante2)==HIGH && i<3000){
i++;
delay(1);
}
if(digitalRead(Pulsante2)==LOW){
  result=true;
}
if(result){
  Serial.println("Pulsante2 OK");
}
else{
  Serial.println("Pulsante2 ERR");
}
Serial.println("Fine programma");
}

void loop() {

}
