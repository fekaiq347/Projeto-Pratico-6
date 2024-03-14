#include <IRremote.h>

int receptorIR = 11;  // Pino de dados do sensor IR
IRrecv irrecv(receptorIR);
decode_results resultadosIR;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();  // Inicializa o receptor IR
}

void loop() {
  if (irrecv.decode(&resultadosIR)) {
    Serial.print("Código recebido: 0x");
    Serial.println(resultadosIR.value, HEX);
    irrecv.resume();  // Receba o próximo valor
  }
}
