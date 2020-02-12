/*
 * Arduino sketch for measuring distance using a HC-SR04 ultrasonic distance sensor. 
 * Sketch includes
 *    - temperature compensation
 *    - warning LED
 */

/** Tempeature Sensor settings **/
// Include libraries needed for DS18B20 temperature sensor
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 0 on the Wemos D1 mini
#define ONE_WIRE_BUS 0  //D3
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
float celcius=0;


// define pin numbers
const int trigPin = 4;  //D2
const int echoPin = 5;  //D1

// define variables
long duration;
int distance;

void setup() {
    pinMode(trigPin, OUTPUT);   // Sets the trigPin as an Output
    pinMode(echoPin, INPUT);    // Sets the echoPin as an Input
    Serial.begin(115200);       // Starts the serial communication
}

void loop() {
    // call sensors.requestTemperatures() to issue a global temperature 
    // request to all devices on the bus
    sensors.requestTemperatures(); // Send the command to get temperatures
    
    // We use the function ByIndex, and as an example get the temperature from the first sensor only.
    celcius=sensors.getTempCByIndex(0);

    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);


    // Speed of sound m/s = 331.4 + (0.606 * Temp)
    // Calculating the distance using speed of sound estimate
    distance = duration*(331.4+(0.606*celcius))/20000;

    // Prints the temperature and distance on the Serial Monitor
    Serial.print("Temperature: ");
    Serial.print(celcius);
    Serial.print(" C   ");
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(2000);
}

