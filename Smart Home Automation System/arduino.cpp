#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Wi-Fi credentials
char ssid[] = "your_SSID";
char pass[] = "your_PASSWORD";

// Blynk credentials
char auth[] = "your_BLYNK_AUTH_TOKEN";

// Pin configurations
#define RELAY_PIN 2        // Example pin for controlling a relay
#define MOTION_SENSOR_PIN 4 // Example pin for motion sensor
#define DHT_PIN 5           // Example pin for DHT sensor

// Constants
#define DHT_TYPE DHT22 // DHT sensor type, you can change it based on your sensor

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(MOTION_SENSOR_PIN, INPUT);
}

void loop() {
  Blynk.run();
  
  // Read motion sensor
  int motionState = digitalRead(MOTION_SENSOR_PIN);

  // If motion detected, turn on the light
  if (motionState == HIGH) {
    digitalWrite(RELAY_PIN, HIGH);
    Blynk.virtualWrite(V1, HIGH); // Update Blynk app
  } else {
    digitalWrite(RELAY_PIN, LOW);
    Blynk.virtualWrite(V1, LOW); // Update Blynk app
  }

  // Read temperature and humidity from DHT sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Send sensor data to Blynk app
  Blynk.virtualWrite(V2, temperature);
  Blynk.virtualWrite(V3, humidity);

  delay(1000); // Adjust the delay based on your requirements
}
