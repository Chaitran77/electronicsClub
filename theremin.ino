int freqInput = A0;
int volInput = A1;
int soundOutput = 5;

int currentFrequency = 0; // Hz
int maxFrequency = 5000;

void setup() {
  // put your setup code here, to run once:
  pinMode(soundOutput, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  currentFrequency = (analogRead(freqInput)/1024.0) * maxFrequency;
  analogWrite(soundOutput, currentFrequency);
  delay(500);

  Serial.println(currentFrequency);
}
