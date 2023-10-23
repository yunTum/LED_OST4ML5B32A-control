#define DIN_H_PIN 5
#define DIN_L_PIN 6
#define PIN_DELAY 50
#define LATCH_TIME 3

void setup() {
  pinMode(DIN_H_PIN, OUTPUT);
  pinMode(DIN_L_PIN, OUTPUT);
}

void loop() {
  color_test();
}

void create_color(unsigned int r, unsigned int g, unsigned int b) {
  delay(LATCH_TIME);
  create_byte(r);
  create_byte(g);
  create_byte(b);
  digitalWrite(DIN_H_PIN, HIGH);
  digitalWrite(DIN_L_PIN, LOW);
  delay(100);
}

void color_test() {
  create_color(255, 255, 255);
  create_color(255, 0, 0);
  create_color(0, 255, 0);
  create_color(0, 0, 255);
  create_color(255, 255, 0);
  create_color(255, 0, 255);
  create_color(0, 0, 255);
  create_color(0, 255, 255);
}

void color_test2() {
  int i = 255;
  int j = 0;
  int k = 255;
  for(int d=0; d<100; d++){
    create_color(i, j, k);
    i -= 2;
    j += 2;
    k -= 2;
  }
  for(int d=0; d<100; d++){
    create_color(i, j, k);
    i += 2;
    j -= 2;
    k += 2;
  }
}

void create_bit(bool state) {
  digitalWrite(DIN_H_PIN, HIGH);
  digitalWrite(DIN_L_PIN, LOW);
  delayMicroseconds(PIN_DELAY);
  digitalWrite(DIN_H_PIN, state);
  digitalWrite(DIN_L_PIN, state);
  delayMicroseconds(PIN_DELAY);
}

void create_byte(unsigned int number) {
  int state = 0;
  for(int i=128; i>0; i = i >> 1){
    state = ((number & i) != 0);
    create_bit(state);
  }
}