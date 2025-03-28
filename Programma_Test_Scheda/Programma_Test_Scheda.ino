/*Programma di test per la scheda CNY70
Questo programma fa un test del riconoscimento del bianco e del nero e della variazione di potenza dei CNY70
*/
#define CNY0 A0
#define CNY1 A1
#define CNY2 A2
#define potenza 10
void setup() {
Serial.begin(9600);
pinMode(10,OUTPUT);
Serial.println("PROGRAMMA DI TEST SCHEDA CNY70");
delay(2000);
Serial.println("Preparare i campioni di colori per il test e ricordarsi di mantenere i sensori ad una distanza di circa 1mm dal campione");
delay(5000);
Serial.println("PROVA BIANCO");
Serial.println("Spostare i sensori sul campione di colore bianco");
}

void loop() {

}
