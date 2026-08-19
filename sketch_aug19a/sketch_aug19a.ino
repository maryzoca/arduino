#include <Servo.h>

// Criando os dois servomotores
Servo servo1;
Servo servo2;

// Pinos dos servos
const int pinoServo1 = 9;
const int pinoServo2 = 10;

// Pinos dos LEDs
const int led1 = 7;
const int led2 = 8;

// Variáveis para receber os comandos
String comando = "";

void setup() {

  // Inicia a comunicação com o computador
  Serial.begin(9600);

  // Conecta os servos aos pinos
  servo1.attach(pinoServo1);
  servo2.attach(pinoServo2);

  // Configura os LEDs como saída
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  // Posição inicial dos servos
  servo1.write(90);
  servo2.write(90);

  // LEDs inicialmente desligados
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);

  Serial.println("Arduino pronto!");
}


void loop() {

  // Verifica se chegou algum comando do computador
  if (Serial.available() > 0) {

    comando = Serial.readStringUntil('\n');

    comando.trim();

    // Comando do Servo 1
    if (comando.startsWith("S1:")) {

      int angulo = comando.substring(3).toInt();

      // Limita o ângulo entre 0 e 180
      angulo = constrain(angulo, 0, 180);

      // Move o Servo 1
      servo1.write(angulo);

      // Acende o LED 1
      digitalWrite(led1, HIGH);

      Serial.print("Servo 1: ");
      Serial.println(angulo);
    }


    // Comando do Servo 2
    else if (comando.startsWith("S2:")) {

      int angulo = comando.substring(3).toInt();

      // Limita o ângulo entre 0 e 180
      angulo = constrain(angulo, 0, 180);

      // Move o Servo 2
      servo2.write(angulo);

      // Acende o LED 2
      digitalWrite(led2, HIGH);

      Serial.print("Servo 2: ");
      Serial.println(angulo);
    }
  }
}
