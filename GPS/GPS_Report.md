# GPS Reading Report (Simulation-Based)

## Student Details

* Name: J Grahitha
* Roll No: BL.SC.U4AIE25218

## Objective

* Read GPS data from L86-M33 module
* Parse NMEA sentences
* Extract Latitude, Longitude, Altitude, Timestamp
* Display formatted GPS data

## Implementation Note

The implementation is carried out using **online simulation tools**.
Simulated NMEA sentences are used instead of real satellite signals.

## Components Used

* Arduino IDE
* Online GPS Simulation Tool
* TinyGPS++ Library
* SoftwareSerial Library

## Working Principle

GPS modules output data in NMEA sentence format.
In this project, simulated NMEA data is fed into the system and parsed using TinyGPS++ to extract useful parameters.

## Implementation

* Baud rate configured to 9600
* Data parsed using gps.encode()
* smartDelay ensures continuous parsing
* Data validated using isValid()

## Output

Lat: 13.195987
Lon: 80.224016
Altitude: 15.34 m
Time: 12:45:32

## Observations

* Simulation provides instant GPS data
* No delay for satellite acquisition
* Useful for testing parsing logic

## Challenges

* Ensuring realistic NMEA input
* Validating parsed data without real hardware

## Conclusion

Successfully implemented GPS data parsing using simulated NMEA data.
The system accurately extracts and displays required parameters.

## Future Improvements

* Test with real GPS hardware
* Improve accuracy validation
* Integrate real-time tracking
