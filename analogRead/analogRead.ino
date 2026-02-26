// Simply put the pins to be read in the array
const int PINS[] = {34,35,32};
const int num_pins = sizeof(PINS) / sizeof(PINS[0]);

void setup() {
  // Set all pins in PINS[] to be inputs
  for(int i = 0; i < num_pins; i++) {
    pinMode(PINS[i],INPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // Print the direct ADC reading from each pin
  for(int i = 0; i < num_pins-1; i++) {
    Serial.print(analogRead(PINS[i]));
    Serial.print(",");
  }
  Serial.println(analogRead(PINS[num_pins-1]));
}