int sensorPin = A0;   // select the analog input pin for the photoresistor
int second  = A1;
int threshold = 150;  // analog inpsut trigger level from photoresistor
int sensorValue = 0;  // photoresistor value read from analog input pin
int closePin = 12;
int stopPin = 11;
int openPin = 10;
bool closed = false;
bool opened = false;
int upper = 250;
int check;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // built-in LED, usually on pin 13
  pinMode(closePin, OUTPUT);
  pinMode(stopPin, OUTPUT);
  pinMode(openPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(sensorPin));
  check = analogRead(second);
  if (analogRead(sensorPin) < threshold && !closed ) { //&& check > threshold
    // low light, so switch the light (LED) on
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Closing");
    digitalWrite(closePin, HIGH);
    delay(500);
    digitalWrite(closePin, LOW);
    delay(7000);
    digitalWrite(stopPin, HIGH);
    delay(500);
    digitalWrite(stopPin, LOW);
    Serial.println("Closed");
    opened = false;
    closed = true;
  }
  else if(analogRead(sensorPin)>upper && !opened){ // && check < threshold
    // light level high enough, so switch the light (LED) off
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("Opening");
    digitalWrite(openPin, HIGH);
    delay(500);
    digitalWrite(openPin, LOW);
    delay(7000);
    digitalWrite(stopPin, HIGH);
    delay(500);
    digitalWrite(stopPin, LOW);
    Serial.println("Opened");
    closed  = false;
    opened  = true;
  }
  // wait for ADC to settle before next reading
  Serial.println("checked");
  delay(10000);
}
