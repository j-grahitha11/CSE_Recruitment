#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// ====== Pins ======
#define RX_PIN 4
#define TX_PIN 3

SoftwareSerial GPS_SoftSerial(RX_PIN, TX_PIN); // RX, TX
TinyGPSPlus gps;

// ====== Setup ======
void setup() {
  Serial.begin(9600);          // Serial monitor
  GPS_SoftSerial.begin(9600);  // GPS module baud rate
  Serial.println("GPS Simulation Starting...");
}

// ====== Loop ======
void loop() {
  smartDelay(1000); // Delay 1 second while parsing GPS

  // ----- Latitude & Longitude -----
  if (gps.location.isValid()) {
    Serial.print("Lat: ");
    Serial.println(gps.location.lat(), 6);

    Serial.print("Lon: ");
    Serial.println(gps.location.lng(), 6);
  } else {
    Serial.println("Lat: *****");
    Serial.println("Lon: *****");
  }

  // ----- Altitude -----
  if (gps.altitude.isValid()) {
    Serial.print("Altitude: ");
    Serial.print(gps.altitude.meters(), 2);
    Serial.println(" m");
  } else {
    Serial.println("Altitude: *****");
  }

  // ----- Time -----
  if (gps.time.isValid()) {
    char time_string[16];
    sprintf(time_string, "Time: %02d:%02d:%02d",
            gps.time.hour(), gps.time.minute(), gps.time.second());
    Serial.println(time_string);
  } else {
    Serial.println("Time: *****");
  }

  Serial.println("------");
}

// ====== Helper: Delay while parsing GPS ======
static void smartDelay(unsigned long ms) {
  unsigned long start = millis();
  do {
    while (GPS_SoftSerial.available())
      gps.encode(GPS_SoftSerial.read());
  } while (millis() - start < ms);
}