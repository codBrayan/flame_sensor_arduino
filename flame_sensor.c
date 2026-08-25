#include <Servo.h>

const int PINO_SENSOR_A0 = A0;
const int PINO_BOTAO     = 3;
const int PINO_LED        = 5;
const int PINO_SERVO      = 9;
const int PINO_BUZZER     = 8;

const int LIMITE_CHAMA = 400;

Servo servoMangueira;
bool alarmeAtivo = false;
bool estadoBotaoAnterior = HIGH;

unsigned long ultimoTempoPisca = 0;
bool estadoAlarmeVisual = LOW;

void setup() {
  Serial.begin(9600);
  Serial.println("--- SISTEMA INICIALIZADO ---");

  pinMode(PINO_BOTAO, INPUT_PULLUP);
  pinMode(PINO_LED, OUTPUT);
  pinMode(PINO_BUZZER, OUTPUT);

  servoMangueira.attach(PINO_SERVO);
  servoMangueira.write(0);

  digitalWrite(PINO_LED, LOW);
  digitalWrite(PINO_BUZZER, LOW);
  
}

void loop() {
  int valorA0 = analogRead(PINO_SENSOR_A0);
  int leituraBotao = digitalRead(PINO_BOTAO);

  Serial.print("Sensor A0: ");
  Serial.print(valorA0);
  Serial.print(" | Botao Pino 3: ");
  Serial.print(leituraBotao);
  
  if (alarmeAtivo) {
    Serial.println(" | STATUS: ALARME LIGADO");
  } else {
    Serial.println(" | STATUS: ALARME DESLIGADO");
  }

  if (valorA0 < LIMITE_CHAMA && !alarmeAtivo) {
    Serial.println(">>> ALERTA: CHAMA DETECTADA PELO SENSOR! <<<");
    ativarAlarme();
  }

  if (leituraBotao == LOW && estadoBotaoAnterior == HIGH) {
    Serial.println(">>> BOTAO PRESSIONADO! <<<");
    if (alarmeAtivo) {
      Serial.println(">>> DESATIVANDO ALARME VIA BOTAO <<<");
      desativarAlarme();
    } else {
      Serial.println(">>> ATIVANDO ALARME VIA BOTAO <<<");
      ativarAlarme();
    }
    delay(250);
  }
  estadoBotaoAnterior = leituraBotao;

  if (alarmeAtivo) {
    if (millis() - ultimoTempoPisca >= 200) {
      ultimoTempoPisca = millis();
      servoMangueira.write(90);
      estadoAlarmeVisual = !estadoAlarmeVisual;
      digitalWrite(PINO_LED, estadoAlarmeVisual);
      digitalWrite(PINO_BUZZER, estadoAlarmeVisual);
      servoMangueira.write(0);
    }
  }

  delay(200);
}

void ativarAlarme() {
  alarmeAtivo = true;
  Serial.println("[ATUADORES] Servo girou para 90 graus");
}

void desativarAlarme() {
  alarmeAtivo = false;
  servoMangueira.write(0);
  digitalWrite(PINO_LED, LOW);
  digitalWrite(PINO_BUZZER, LOW);
  Serial.println("[ATUADORES] Servo voltou para 0 graus");
}