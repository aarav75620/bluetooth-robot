// Pin assignments for L293D motor driver
const int motor1Pin1 = 7;
const int motor1Pin2 = 6;
const int motor2Pin1 = 5;
const int motor2Pin2 = 4;
const int enable1 = 9;
const int enable2 = 10;

// Bluetooth data storage
char data = 0;

void setup() {
  // Set motor pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);

  // Set motor speed (0-255)
  analogWrite(enable1, 150);
  analogWrite(enable2, 150);

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Read Bluetooth data
  if (Serial.available()) {
    data = Serial.read();
    
    // Car control based on received data
    if (data == 'F') { // Forward
      moveForward();
    } 
    else if (data == 'B') { // Backward
      moveBackward();
    } 
    else if (data == 'L') { // Left
      turnLeft();
    } 
    else if (data == 'R') { // Right
      turnRight();
    } 
    else if (data == 'S') { // Stop
      stopCar();
    }
  }
}

// Movement functions
void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void moveBackward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void stopCar() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
