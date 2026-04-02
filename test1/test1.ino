const int PDIODE = 34;

void setup() {
  pinMode(PDIODE,INPUT);
  Serial.begin(115200);
}

//this doesnt seem to exhibit the 60 Hz-ish interference

void loop() {
  Serial.println(analogRead(PDIODE));
  delay(10);
}