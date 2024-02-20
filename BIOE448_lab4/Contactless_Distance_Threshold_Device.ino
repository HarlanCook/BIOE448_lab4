const int trigPin = 11;
const int echoPin = 12;
const int C = 10;
const int GREEN = 9;
const int RED = 8;
long duration;
int distanceCm, distanceInch;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(C);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 1/58;
  distanceInch = duration * 1/148;
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.print(" cm/");
  Serial.print(distanceInch);
  Serial.println(" in");
  delay(1000);

  if (distanceInch < 6){
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
  }
  else if (distanceInch >= 6){
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
  }
}
