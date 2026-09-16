#include <DabbleESP32.h>

void setup() {
  // Start Serial Monitor
  Serial.begin(115200);

  // Start Dabble Bluetooth
  Dabble.begin("ESP32_Dabble");

  Serial.println("=================================");
  Serial.println("ESP32 + Dabble Started");
  Serial.println("Bluetooth: ESP32_Dabble");
  Serial.println("Open the Dabble app and connect.");
  Serial.println("=================================");
}

void loop() {
  // Process incoming data from Dabble
  Dabble.processInput();

  // Check if a message was received
  if (Terminal.available()) {
    String message = Terminal.readString();

    // Display message on Serial Monitor
    Serial.print("Received from phone: ");
    Serial.println(message);

    // Send response to Dabble Terminal
    Terminal.println("ESP32 received: " + message);
  }

  delay(100);
}
