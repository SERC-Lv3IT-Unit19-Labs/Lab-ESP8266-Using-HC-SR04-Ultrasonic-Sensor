/*
    Arduino sketch for measuring distance using a HC-SR04 ultrasonic distance sensor. 
*/

// define pin numbers
const int trigPin = 4;  //D2
const int echoPin = 5;  //D1
const int ledPin = 2;  //D4  // define the pin the LED is attached 


// define variables
long duration;
int distance;

void setup() {
    pinMode(trigPin, OUTPUT);   // Sets the trigPin as an Output
    pinMode(echoPin, INPUT);    // Sets the echoPin as an Input
    Serial.begin(115200);       // Starts the serial communication
    pinMode(ledPin, OUTPUT); // Initialise the LED pin as an OUTPUT

}

void loop() {
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);

    // Calculating the distance using speed of sound estimate
    distance = duration*0.034/2;
    if (distance<10);
    {
    digitalWrite (ledPin,HIGH);
    }
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    delay(2000);
   
}

