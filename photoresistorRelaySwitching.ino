int LDRInputPin = A0;
int RelayOutputPin = 2;
float LDRThreshVoltage = 3;

// analogRead() gives a value from 0 - 1024, which can be used as-is, or be converted into a P.D.
// AU = Arbitary Unit
float AUtoVoltage(int AU, float maxPD) {
  float voltsPerUnit = maxPD/1024.0;
  float voltage = voltsPerUnit * AU;
  return voltage;
}

// this model is inefficient. How can it be restructured to conserve # computations

void setup() {
  // put your setup code here, to run once:
  pinMode(LDRInputPin, INPUT);
  pinMode(RelayOutputPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int RAWldrValue = analogRead(LDRInputPin);
  float LDRpdValue = AUtoVoltage(RAWldrValue, 5);
  Serial.print(LDRpdValue);
  Serial.print(" ");

  if (LDRpdValue <= LDRThreshVoltage) { // we can decide if we want the boundary to trip the switch or not - the accuracy/number of S.F.s used will affect this (more will mean threshold is smaller)
    Serial.println("on");
    digitalWrite(RelayOutputPin, HIGH); // could hold the state of the pin in memory and perform a check, but this is easier
  } else {
    Serial.println("off");
    digitalWrite(RelayOutputPin, LOW);
  }

  delay(10);
}

