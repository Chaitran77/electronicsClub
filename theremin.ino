int freqInput = A0;
int volInput = A1;
int soundOutput = 5;

int currentFrequency = 0; // Hz
float currentPeriod = 0; // ms
int maxFrequency = 5000;

void setup() {
  // put your setup code here, to run once:
  pinMode(soundOutput, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  while (true) {
    currentFrequency = (analogRead(freqInput)/1024.0) * maxFrequency;
    currentPeriod = 500.0/currentFrequency;
    delay(currentPeriod);
    Serial.println(currentPeriod);
    digitalWrite(5, LOW);
    delay(currentPeriod);
    digitalWrite(5, HIGH);
  }

  
}
