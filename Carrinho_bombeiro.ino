/*

  Arduino Bluetooth Controlled Car
  Install Adafruit Motor Shield Library before uploading this code.
  AFMotor Library https://learn.adafruit.com/adafruit-motor-shield/library-install

  -> If you need helping guide on how to install library for the motor shield or how to use motor shield then
     watch this: https://youtu.be/vooJEyco1J4

     Caution: Remove the jumper or switch off the battery switch before connecting the Arduino board to computer.

     For more support contact me on Telegram: @UtGoTech


*/


#include <AFMotor.h>
#include <SoftwareSerial.h>
#include <Servo.h>

Servo nozzle;

SoftwareSerial bluetoothSerial(14, 15);  // RX, TX

//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

char command;
int servo_angle = 0;

void setup() {
  bluetoothSerial.begin(9600);  //Set the baud rate to your Bluetooth module.

  pinMode(19, OUTPUT);
  digitalWrite(19, HIGH);
  nozzle.attach(10);
}

void loop() {
  if (bluetoothSerial.available() > 0) {
    command = bluetoothSerial.read();

    Stop();  //initialize with motors stoped

    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'x':
        digitalWrite(19, HIGH);
        break;
      case 'X':
        digitalWrite(19, LOW);
        break;
      case '1':
        servo_angle = 1;
        nozzle_adjust();
        break;
      case '2':
        servo_angle = 2;
        nozzle_adjust();
        break;
      case '3':
        servo_angle = 3;
        nozzle_adjust();
        break;
      case '4':
        servo_angle = 4;
        nozzle_adjust();
        break;
      case '5':
        servo_angle = 5;
        nozzle_adjust();
        break;
      case '6':
        servo_angle = 6;
        nozzle_adjust();
        break;
      case '7':
        servo_angle = 7;
        nozzle_adjust();
        break;
      case '8':
        servo_angle = 8;
        nozzle_adjust();
        break;
      case '9':
        servo_angle = 9;
        nozzle_adjust();
        break;
    }
  }
}

void forward() {
  motor1.setSpeed(150);  //Define maximum velocity
  motor1.run(FORWARD);   //rotate the motor clockwise
  motor2.setSpeed(150);  //Define maximum velocity
  motor2.run(FORWARD);   //rotate the motor clockwise
  motor3.setSpeed(150);  //Define maximum velocity
  motor3.run(FORWARD);   //rotate the motor clockwise
  motor4.setSpeed(150);  //Define maximum velocity
  motor4.run(FORWARD);   //rotate the motor clockwise
}

void back() {
  motor1.setSpeed(150);  //Define maximum velocity
  motor1.run(BACKWARD);  //rotate the motor anti-clockwise
  motor2.setSpeed(150);  //Define maximum velocity
  motor2.run(BACKWARD);  //rotate the motor anti-clockwise
  motor3.setSpeed(150);  //Define maximum velocity
  motor3.run(BACKWARD);  //rotate the motor anti-clockwise
  motor4.setSpeed(150);  //Define maximum velocity
  motor4.run(BACKWARD);  //rotate the motor anti-clockwise
}

void left() {
  motor1.setSpeed(150);  //Define maximum velocity
  motor1.run(BACKWARD);  //rotate the motor anti-clockwise
  motor2.setSpeed(150);  //Define maximum velocity
  motor2.run(BACKWARD);  //rotate the motor anti-clockwise
  motor3.setSpeed(150);  //Define maximum velocity
  motor3.run(FORWARD);   //rotate the motor clockwise
  motor4.setSpeed(150);  //Define maximum velocity
  motor4.run(FORWARD);   //rotate the motor clockwise
}

void right() {
  motor1.setSpeed(150);  //Define maximum velocity
  motor1.run(FORWARD);   //rotate the motor clockwise
  motor2.setSpeed(150);  //Define maximum velocity
  motor2.run(FORWARD);   //rotate the motor clockwise
  motor3.setSpeed(150);  //Define maximum velocity
  motor3.run(BACKWARD);  //rotate the motor anti-clockwise
  motor4.setSpeed(150);  //Define maximum velocity
  motor4.run(BACKWARD);  //rotate the motor anti-clockwise
}

void Stop() {
  motor1.setSpeed(0);   //Define minimum velocity
  motor1.run(RELEASE);  //stop the motor when release the button
  motor2.setSpeed(0);   //Define minimum velocity
  motor2.run(RELEASE);  //rotate the motor clockwise
  motor3.setSpeed(0);   //Define minimum velocity
  motor3.run(RELEASE);  //stop the motor when release the button
  motor4.setSpeed(0);   //Define minimum velocity
  motor4.run(RELEASE);  //stop the motor when release the button
}

void nozzle_adjust() {
  int adjust = map(servo_angle, 1, 9, 135, 65);
  nozzle.write(adjust);
}
