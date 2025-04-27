void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    int data = Serial.read();  // Read one byte
    // Do something with the received data
    Serial.print("Received: ");
    Serial.println(data);
  }
}