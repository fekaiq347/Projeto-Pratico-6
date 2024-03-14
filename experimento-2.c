	int contador = 0;
int pinBotaoIncrementar = 10;  // Pino do botão para incrementar
int pinBotaoDecrementar = 11;  // Pino do botão para decrementar
int pinA = 2; 
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;

void setup() {
  Serial.begin(9600);
  pinMode(pinBotaoIncrementar, INPUT_PULLUP);
  pinMode(pinBotaoDecrementar, INPUT_PULLUP);
  pinMode (pinA, OUTPUT);
  pinMode (pinB, OUTPUT);
  pinMode (pinC, OUTPUT);
  pinMode (pinD, OUTPUT);
  pinMode (pinE, OUTPUT);
  pinMode (pinF, OUTPUT);
  pinMode (pinG, OUTPUT);
}

void loop() {
  if (digitalRead(pinBotaoIncrementar) == LOW) {
    contador++;
    delay(100);  // Debounce
  }

  if (digitalRead(pinBotaoDecrementar) == LOW) {
    contador--;
    delay(100);  // Debounce
  }
  

  
  // Atualizar o display de 7 segmentos com o valor do contador
  atualizarDisplay(contador);
}

void atualizarDisplay(int valor) {
  if (contador == 0) {
    digitalWrite (pinA, LOW);
    digitalWrite (pinB, LOW);
    digitalWrite (pinC, LOW);
    digitalWrite (pinD, LOW);
    digitalWrite (pinE, LOW);
    digitalWrite (pinF, LOW);
    digitalWrite (pinG, HIGH);
    delay(100);
  }
  if (contador == 1) {
    digitalWrite (pinA, HIGH);
    digitalWrite (pinB, LOW);
    digitalWrite (pinC, LOW);
    digitalWrite (pinD, HIGH);
    digitalWrite (pinE, HIGH);
    digitalWrite (pinF, HIGH);
    digitalWrite (pinG, HIGH);
    delay(100);
  }
  if (contador == 2) {
    digitalWrite (pinA, LOW);
    digitalWrite (pinB, LOW);
    digitalWrite (pinC, HIGH);
    digitalWrite (pinD, LOW);
    digitalWrite (pinE, LOW);
    digitalWrite (pinF, HIGH);
    digitalWrite (pinG, LOW);
    delay(100);
  }
  if (contador == 3) {
    digitalWrite (pinA, LOW);
    digitalWrite (pinB, LOW);
    digitalWrite (pinC, LOW);
    digitalWrite (pinD, LOW);
    digitalWrite (pinE, HIGH);
    digitalWrite (pinE, HIGH);
    digitalWrite (pinG, LOW);
    delay(100);
  }
  if (contador == 4) {
    digitalWrite (pinA, HIGH);
    digitalWrite (pinB, LOW);
    digitalWrite (pinC, LOW);
    digitalWrite (pinD, HIGH);
    digitalWrite (pinE, HIGH);
    digitalWrite (pinF, LOW);
    digitalWrite (pinG, LOW);
    delay(100);
  }
  if (contador == 5) {
    digitalWrite (pinA, LOW);
    digitalWrite (pinB, HIGH);
    digitalWrite (pinC, LOW);
    digitalWrite (pinD, LOW);
    digitalWrite (pinE, HIGH);
    digitalWrite (pinF, LOW);
    digitalWrite (pinG, LOW);
    delay(100);
  }
  if (contador == 6) {
    digitalWrite (pinA, LOW);
    digitalWrite (pinB, HIGH);
    digitalWrite (pinC, LOW);
    digitalWrite (pinD, LOW);
    digitalWrite (pinE, LOW);
    digitalWrite (pinF, LOW);
    digitalWrite (pinG, LOW);
    delay(100);
  }
  if (contador == 7) {
    digitalWrite (pinA, LOW);
    digitalWrite (pinB, LOW);
    digitalWrite (pinC, LOW);
    digitalWrite (pinD, HIGH);
    digitalWrite (pinE, HIGH);
    digitalWrite (pinF, HIGH);
    digitalWrite (pinG, HIGH);
    delay(100);
  }
  if (contador == 8) {
    digitalWrite (pinA, LOW);
    digitalWrite (pinB, LOW);
    digitalWrite (pinC, LOW);
    digitalWrite (pinD, LOW);
    digitalWrite (pinE, LOW);
    digitalWrite (pinF, LOW);
    digitalWrite (pinG, LOW);
    delay(100);
  }
  if (contador == 9) {
    digitalWrite (pinA, LOW);
    digitalWrite (pinB, LOW);
    digitalWrite (pinC, LOW);
    digitalWrite (pinD, LOW);
    digitalWrite (pinE, HIGH);
    digitalWrite (pinF, LOW);
    digitalWrite (pinG, LOW);
    delay(100);
  }
  if (contador > 9) {
    contador = 0;
  }
}
