# GPS Reading using L86-M33 (Simulation)

## Objective

* Read GPS data from L86-M33 module
* Parse NMEA sentences
* Extract Latitude, Longitude, Altitude, Time
* Display formatted GPS data

## Implementation Note

This project is implemented using **online simulation tools** instead of physical hardware.
Simulated NMEA data is used to test parsing and extraction logic.

## Tools Used

* Arduino IDE
* Online GPS Simulation Tool
* TinyGPS++ Library
* SoftwareSerial Library

## Output

Lat: 13.195987
Lon: 80.224016
Altitude: 15.34 m

## How it Works

* Simulated GPS data generates NMEA sentences
* TinyGPS++ parses incoming data
* Valid data is extracted and printed
* Invalid data is handled safely


## Author

* J Grahitha
* BL.SC.U4AIE25218
