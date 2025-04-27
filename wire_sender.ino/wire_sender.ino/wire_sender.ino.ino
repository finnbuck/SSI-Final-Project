void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = 254; // Replace with your sensor logic
  Serial.write(sensorValue);     // Send as a byte (0–255)
  delay(1000);                    // Wait a bit
}