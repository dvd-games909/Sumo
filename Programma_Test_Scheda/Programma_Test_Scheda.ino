/*Programma di test per la scheda CNY70
Questo programma fa un test del riconoscimento del bianco e del nero e della variazione di potenza dei CNY70
*/
#define CNY0 A0
#define CNY1 A1
#define CNY2 A2
#define potenza 11
String stringa;
char c = " ";
void setup() {
  Serial.begin(9600);
  pinMode(potenza, OUTPUT);
  Serial.println("PROGRAMMA DI TEST SCHEDA CNY70");
  delay(2000);
  analogWrite(potenza, 0);
  Serial.println("Controllare con la telecamera del cellulare che i CNY70 siano accesi");
  delay(5000);
  test();
}

void loop() {
  Serial.println("Vuoi testare un'altra scheda? (Y=si,N=no)");
  while (Serial.available() == false) {}
  if (Serial.available()) {
    stringa = "";
    do {
      if (Serial.available()) {
        c = Serial.read();
        if (c != '\n')
          stringa += c;
      }
    } while (c != '\n');
    if (stringa == "Y" || stringa == "y") {
      test();
    }
    if (stringa == "N" || stringa == "n") {
      Serial.println("Scollegare l'Arduino");
      while (Serial.available() == false) {}
    }
  }
}

void test() {
  Serial.println("Preparare i campioni di colori per il test e ricordarsi di mantenere i sensori ad una distanza di circa 1mm dal campione");
  delay(5000);
  Serial.println("PROVA BIANCO");
  Serial.println("Spostare i sensori sul campione di colore bianco");
  delay(3000);
  int CNY[3] = { analogRead(A0), analogRead(A1), analogRead(A2) };
  String valori = "", esito = "";
  for (int i = 0; i < 3; i++) {
    valori = valori + CNY[i];
    valori = valori + "     ";
    if (CNY[i] > 700) {
      esito = esito + "OK";
    } else {
      esito = esito + "ER";
    }
    esito = esito + "      ";
  }
  Serial.println(valori);
  Serial.println(esito);
  delay(2000);
  Serial.println("PROVA NERO");
  Serial.println("Spostare i sensori sul campione di colore nero");
  delay(3000);
  CNY[0] = analogRead(A0);
  CNY[1] = analogRead(A1);
  CNY[2] = analogRead(A2);
  valori = "";
  esito = "";
  for (int i = 0; i < 3; i++) {
    valori = valori + CNY[i];
    valori = valori + "     ";
    if (CNY[i] < 300) {
      esito = esito + "OK";
    } else {
      esito = esito + "ER";
    }
    esito = esito + "      ";
  }
  Serial.println(valori);
  Serial.println(esito);
  delay(3000);
  Serial.println("Test variazione di potenza utilizzare la fotocamera del cellulare per controllare che i CNY varino la potenza del diodo a infrarossi");
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j<255;j++){
      analogWrite(potenza,j);
      delay(2);
    }
    for (int y = 255; y>1;y--){
      analogWrite(potenza,y);
      delay(2);
    }
  }
  delay(1000);
  Serial.println("Fine del programma di test");
}