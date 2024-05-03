
#include <SoftwareSerial.h> //Libarary bawaan

const int trigPin1 = A1;


const int echoPin1 = A0;

long duration1;

int distance1;




void loop() {
  delay(1000); // Delay to control the rate of readings

  long duration1, distance1; // Variables to store duration and distance values

  // Clear the trigger pin
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond pulse to the trigger pin
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  // Read the duration of the pulse on the echo pin
  duration1 = pulseIn(echoPin1, HIGH);

  // Calculate the distance in centimeters based on the duration
  distance1 = duration1 * 0.034 / 2;

  Serial.print("Distance1: ");
  Serial.print(distance1);
  Serial.println(" cm");

  // Debugging output to check buzzer conditions
  Serial.print("Buzzer Conditions: ");
  Serial.print("distance1 < 30 && distance1 > 20: ");
  Serial.print(distance1 < 30 && distance1 > 20);
  Serial.print(", distance1 < 20 && distance1 > 10: ");
  Serial.print(distance1 < 20 && distance1 > 10);
  Serial.print(", distance1 < 10 && distance1 > 0: ");
  Serial.println(distance1 < 10 && distance1 > 0);

  // Buzzer control based on distance conditions
  if (distance1 < 30 && distance1 > 20) {
    digitalWrite(8, HIGH); // Turn on buzzer
    delay(1000);
    digitalWrite(8, LOW); // Turn off buzzer
    delay(1000);
  } else if (distance1 < 20 && distance1 > 10) {
    digitalWrite(8, HIGH);
    delay(500);
    digitalWrite(8, LOW);
    delay(500);
  } else if (distance1 < 10 && distance1 > 0) {
    digitalWrite(8, HIGH);
    delay(100);
    digitalWrite(8, LOW);
    delay(100);
  } else {
    digitalWrite(8, LOW); // Turn off buzzer
  }
}
