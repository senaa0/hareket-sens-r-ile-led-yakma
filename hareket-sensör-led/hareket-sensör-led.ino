
int led = 13;     // the pin that the LED is atteched to
int sensor = 4;   // the pin that the sensor is atteched to
int button = 2;
int state = LOW;  // by default, no motion detected
int val = 0;
bool isMotion = false;
bool isOpen = false;  // variable to store the sensor status (value)
int timeout = 5000;
int motiontime = 0;


void setup() {
  pinMode(led, OUTPUT);    // initalize LED as an output
  pinMode(sensor, INPUT);  // initialize sensor as an input
  Serial.begin(9600);      // initialize serial
  motiontime = millis();
}

void loop() {

  isMotion = digitalRead(sensor) == HIGH ||  digitalRead(button) == HIGH;

  if (isMotion) {
    isOpen = true;
    motiontime = millis();
    Serial.println("hareket algılandı");
  }

  if (motiontime + timeout < millis()) {
    isOpen = false;
    Serial.println("zaman doldu");
  }


  digitalWrite(led, isOpen ? HIGH : LOW);
}