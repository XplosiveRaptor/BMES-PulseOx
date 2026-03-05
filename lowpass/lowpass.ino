// Simply put the pins to be read in the array
const int PINS[] = {32,34,35};
const int num_pins = sizeof(PINS) / sizeof(PINS[0]);

// yFiltered =
// 0.9690699219933061 * last_filtered +
// 0.015465039003346948 * yInput +
// 0.015465039003347059
const float a1 = 0.9690699219933061;
const float b = 0.015465039003347059;

void setup() {
  // Set all pins in PINS[] to be inputs
  for(int i = 0; i < num_pins; i++) {
    pinMode(PINS[i],INPUT);
  }
  // would changing baud rate affect anything?
  Serial.begin(9600);
}

int current_reading[num_pins] = {0};
float last_filtered[num_pins] = {0};
int last_reading[num_pins] = {0};

void printAll(bool println = 0) {
  // Print the direct ADC reading from each pin
  // fill current_reading array with readings
  // bool println can be used as an integer 1 or 0
  for(int i = 0; i < num_pins - println; i++) {
    current_reading[i] = analogRead(PINS[i]);
    Serial.print(current_reading[i]);
    Serial.print(",");
  }
  if (println) {
    current_reading[num_pins-1] = analogRead(PINS[num_pins-1]);
    Serial.println(current_reading[num_pins-1]);
  }
}

float filterPin(int pindex) {
  last_filtered[pindex] = a1 * last_filtered[pindex] + b * current_reading[pindex] + b * last_reading[pindex];
  last_reading[pindex] = current_reading[pindex];
  return last_filtered[pindex];
}

void filterAll(bool println = 0) {
  // Filter and print each ADC reading
  // bool println can be used as an integer 1 or 0
  for(int i = 0; i < num_pins - println; i++) {
    Serial.print(filterPin(i));
    Serial.print(",");
  }
  if (println) {
    Serial.println(filterPin(num_pins-1));
  }
}

void loop() {
  printAll(0);
  filterAll(1);
}