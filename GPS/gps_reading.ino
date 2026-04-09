#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// GPS RX, TX
SoftwareSerial GPS_SoftSerial(4, 3);

TinyGPSPlus gps;

void setup() {
  Serial.begin(9600);
  GPS_SoftSerial.begin(9600);
}

void loop() {
  smartDelay(1000);

  if (gps.location.isValid() && gps.altitude.isValid()) {
    
    Serial.print("Lat: ");
    Serial.println(gps.location.lat(), 6);

    Serial.print("Lon: ");
    Serial.println(gps.location.lng(), 6);

    Serial.print("Altitude: ");
    Serial.print(gps.altitude.meters(), 2);
    Serial.println(" m");

    Serial.println(); // spacing
  }
  else {
    Serial.println("Waiting for GPS signal...");
    Serial.println();
  }
}

static void smartDelay(unsigned long ms) {
  unsigned long start = millis();
  do {
    while (GPS_SoftSerial.available()) {
      gps.encode(GPS_SoftSerial.read());
    }
  } while (millis() - start < ms);
}
