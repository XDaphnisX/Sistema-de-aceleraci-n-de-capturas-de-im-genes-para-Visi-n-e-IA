#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

// Definimos el pin analógico donde conectamos el potenciómetro
const int pinPotenciometro = A0; 

int pasoDelay = 5; // Variable para almacenar la velocidad calculada

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  // No es estrictamente necesario declarar los pines analógicos como entrada,
  // pero es una buena práctica de programación.
  pinMode(pinPotenciometro, INPUT);
}

void loop() {
  // 1. Leer el valor del potenciómetro (retorna un valor entre 0 y 1023)
  int lecturaPot = analogRead(pinPotenciometro);

  // 2. Mapear la lectura a un rango de delay adecuado para el motor paso a paso.
  // - Un delay muy bajo (ej. menos de 2ms o 3ms) puede hacer que el motor pierda pasos o vibre sin moverse.
  // - Un delay alto (ej. 30ms) lo hará girar bastante lento.
  // Ajustamos: Lectura de 0 a 1023 se convierte en un delay de 30ms (lento) a 3ms (rápido).
  pasoDelay = map(lecturaPot, 0, 1023, 30, 3);

  // 3. Secuencia de pasos (modo full step) utilizando la nueva velocidad modulada
  paso1();
  delay(pasoDelay);

  paso2();
  delay(pasoDelay);

  paso3();
  delay(pasoDelay);

  paso4();
  delay(pasoDelay);
}

// Definición de cada paso (Se mantiene idéntico a tu lógica original)
void paso1() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void paso2() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void paso3() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void paso4() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}