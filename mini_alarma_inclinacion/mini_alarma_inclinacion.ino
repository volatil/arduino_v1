/*
  Mini alarma de inclinacion para Arduino UNO R4 WiFi.

  Conexiones sugeridas:
  - SW-520D: una pata a D2 y la otra a GND.
  - LED verde: anodo a D8 con resistencia, catodo a GND.
  - LED rojo: anodo a D9 con resistencia, catodo a GND.
  - Buzzer activo: positivo a D10, negativo a GND.
*/

const byte PIN_SENSOR_INCLINACION = 2;
const byte PIN_LED_REPOSO = 8;
const byte PIN_LED_ALARMA = 9;
const byte PIN_BUZZER = 10;

const unsigned long TIEMPO_ESTABLE_MS = 80;
const unsigned long PARPADEO_ALARMA_MS = 150;

bool lecturaAnterior = HIGH;
bool sensorEstable = HIGH;
bool alarmaActiva = false;
bool salidaAlarmaEncendida = false;

unsigned long ultimoCambioLecturaMs = 0;
unsigned long ultimoParpadeoMs = 0;

void setup() {
  pinMode(PIN_SENSOR_INCLINACION, INPUT_PULLUP);
  pinMode(PIN_LED_REPOSO, OUTPUT);
  pinMode(PIN_LED_ALARMA, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);

  digitalWrite(PIN_LED_REPOSO, HIGH);
  digitalWrite(PIN_LED_ALARMA, LOW);
  digitalWrite(PIN_BUZZER, LOW);

  Serial.begin(9600);
  Serial.println("Mini alarma de inclinacion lista.");
}

void loop() {
  actualizarSensorEstable();
  actualizarEstadoAlarma();
  actualizarSalidas();
}

void actualizarSensorEstable() {
  bool lecturaActual = digitalRead(PIN_SENSOR_INCLINACION);
  unsigned long ahoraMs = millis();

  if (lecturaActual != lecturaAnterior) {
    lecturaAnterior = lecturaActual;
    ultimoCambioLecturaMs = ahoraMs;
  }

  if ((ahoraMs - ultimoCambioLecturaMs) >= TIEMPO_ESTABLE_MS &&
      sensorEstable != lecturaActual) {
    sensorEstable = lecturaActual;
  }
}

void actualizarEstadoAlarma() {
  bool nuevaAlarmaActiva = (sensorEstable == LOW);

  if (nuevaAlarmaActiva != alarmaActiva) {
    alarmaActiva = nuevaAlarmaActiva;
    salidaAlarmaEncendida = false;
    ultimoParpadeoMs = 0;

    if (alarmaActiva) {
      Serial.println("Alarma activada: inclinacion detectada.");
    } else {
      Serial.println("Alarma desactivada: sensor en reposo.");
    }
  }
}

void actualizarSalidas() {
  if (!alarmaActiva) {
    digitalWrite(PIN_LED_REPOSO, HIGH);
    digitalWrite(PIN_LED_ALARMA, LOW);
    digitalWrite(PIN_BUZZER, LOW);
    return;
  }

  digitalWrite(PIN_LED_REPOSO, LOW);

  unsigned long ahoraMs = millis();
  if ((ahoraMs - ultimoParpadeoMs) >= PARPADEO_ALARMA_MS) {
    ultimoParpadeoMs = ahoraMs;
    salidaAlarmaEncendida = !salidaAlarmaEncendida;
    digitalWrite(PIN_LED_ALARMA, salidaAlarmaEncendida ? HIGH : LOW);
    digitalWrite(PIN_BUZZER, salidaAlarmaEncendida ? HIGH : LOW);
  }
}
