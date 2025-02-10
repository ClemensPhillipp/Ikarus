const int GSM1 = 3;
#define In1 5
#define In2 6
const int GSM2 = 9;
#define In3 10
#define In4 11

const int stop_inbetween_after = 7000;
const int watch_sensor_after = 3000;
const int spinning_time_at_the_top = 10000;

const int sensor_lower = 13;
const int sensor_upper = 12;

const int max_up_down_speed = 50;
const int max_spinning_speed = 120;

void setup() {
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(GSM1, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(GSM2, OUTPUT);
  pinMode(sensor_lower, INPUT);
  pinMode(sensor_upper, INPUT);

  Serial.begin(9600);
}

void loop() {
  delay(3000);
  spin();
  delay(3000);
  up();
  delay(stop_inbetween_after);
  stop();
  delay(2500);
  up();
  delay(watch_sensor_after);
  while (true) {
    if (digitalRead(sensor_upper) == HIGH) {
      stop();
      break;
    }
  }
  delay(spinning_time_at_the_top);
  down();
  delay(stop_inbetween_after);
  stop();
  delay(2500);
  down();
  delay(watch_sensor_after);
  while (true) {
    if (digitalRead(sensor_lower) == HIGH) {
      stop();
      break;
    }
  }
  delay(3000);
  stopSpin();
}

void stopSpin() {
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
  analogWrite(GSM2, 0);
}

void spin() {
  digitalWrite(In4, HIGH);
  digitalWrite(In3, LOW);
  analogWrite(GSM2, max_spinning_speed);
}

void stop() {
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  analogWrite(GSM1, 0);
}

void down() {
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  analogWrite(GSM1, max_up_down_speed);
}

void up() {
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  analogWrite(GSM1, max_up_down_speed);
}