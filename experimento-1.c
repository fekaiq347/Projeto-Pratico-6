
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pinos RS, E, D4, D5, D6, D7

void setup() {
  lcd.begin(16, 2); // Inicializa o LCD 2x16
  analogReference(DEFAULT); // Define a referência analógica como padrão
}

void loop() {
  float temperaturaCelsius = getTemperaturaCelsius();
  float temperaturaFahrenheit = celsiusToFahrenheit(temperaturaCelsius);

  lcd.clear(); // Limpa o LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp (C): ");
  lcd.print(temperaturaCelsius, 1);

  lcd.setCursor(0, 1);
  lcd.print("Temp (F): ");
  lcd.print(temperaturaFahrenheit, 1);

  delay(1000); // Atualiza a cada segundo
}

float getTemperaturaCelsius() {
  ADMUX = (_BV(REFS1) | _BV(REFS0) | _BV(MUX3));  // Configura o canal 8 (sensor de temperatura interno)
  ADCSRA |= _BV(ADEN); // Habilita o conversor ADC
  delay(20); // Espera a tensão se estabilizar
  ADCSRA |= _BV(ADSC); // Inicia a conversão ADC
  while (bit_is_set(ADCSRA, ADSC)); // Aguarda o final da conversão
  int sensorValue = ADCW; // Lê o valor do registrador "ADCW" (ADCL + ADCH)
  
  float tensao = sensorValue * 0.0048828125; // Converte o valor lido em tensão
  float temperaturaCelsius =  (sensorValue - 324.31)/1.22; // Converte a tensão para temperatura em graus Celsius
  return temperaturaCelsius;
}

float celsiusToFahrenheit(float celsius) {
  return (celsius * 9 / 5) + 32; // Converte de Celsius para Fahrenheit
}
