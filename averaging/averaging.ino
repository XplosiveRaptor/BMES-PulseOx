const int PDIODE = 34;
const int avgLength = 128;

void start() {
  pinMode(PDIODE,INPUT);
  Serial.begin(9600);
}


int sum = 0;
void loop() {
  sum = 0;
  for(int i = 0; i < avgLength; i++){
    sum += analogRead(PDIODE);
  }
  Serial.println(sum/avgLength);
}