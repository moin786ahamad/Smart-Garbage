
long duration, distance;
int period = 5000;
unsigned long time_now = 0;

const int trigPin = 10;
const int echoPin = 11;

void setup() 
{
    Serial.begin(115200);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() 
{
  
  
      distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree  
      Serial.print(distance);
      Serial.println ("cm");   
}


int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
