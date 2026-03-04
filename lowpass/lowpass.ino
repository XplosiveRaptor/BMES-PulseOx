// Simply put the pins to be read in the array
const int PINS[] = {32,34,35};
const int num_pins = sizeof(PINS) / sizeof(PINS[0]);

void setup() {
  // Set all pins in PINS[] to be inputs
  for(int i = 0; i < num_pins; i++) {
    pinMode(PINS[i],INPUT);
  }
  Serial.begin(9600);
}

void loop() {
  printAll();
}

void printAll(bool println = 0) {
  // Print the direct ADC reading from each pin
  // bool println can be used as an integer 1 or 0
  for(int i = 0; i < num_pins - println; i++) {
    Serial.print(analogRead(PINS[i]));
    Serial.print(",");
  }
  if (println) {
    Serial.println(analogRead(PINS[num_pins-1]));
  }
}