//---------------------- PWM PINS  ---------------------- A0 (ARDUINO) --> EN_A (MOTOR DRIVER)
//---------------------- PWM PINS  ---------------------- A1 (ARDUINO) --> EN_B (MOTOR DRIVER)

//-------------------------------------------- D10 (ARDUINO) --> TX (HC05 BLUETOOTH MODULE)
//-------------------------------------------- D11 (ARDUINO) --> RX (HC05 BLUETOOTH MODULE)

//--------------------------------------------- D2 (ARDUINO) --> IN-1 (MOTOR DRIVER) --> OUT1 OF MOTOR(+VE)
//--------------------------------------------- D3 (ARDUINO) --> IN-2 (MOTOR DRIVER) --> OUT2 OF MOTOR
//--------------------------------------------- D4 (ARDUINO) --> IN-3 (MOTOR DRIVER) --> OUT3 OF MOTOR(+VE)
//--------------------------------------------- D5 (ARDUINO) --> IN-4 (MOTOR DRIVER) --> OUT4 OF MOTOR

//--------------------------------------------- D6 (ARDUINO) --> SERVO SIGNAL PIN 


#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial btSerial(10, 11);
Servo myArm;

char receivedData;  // Variable to store received data

const int LEFT_ENABLE = A0; // ENABLE PINs DECLARATION
const int RIGHT_ENABLE = A1;

const int IN1 = 2; // CONTROL PINs DECLARATION
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;

const int ServoPin = 6;

const int MOTOR_SPEED = 150; // ROTATION SPEED

void Set_Speed(int SPEED)
{
  analogWrite(LEFT_ENABLE , SPEED);
  analogWrite(RIGHT_ENABLE , SPEED);
}

void moveForward()
{
  Set_Speed(MOTOR_SPEED);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward()
{
  Set_Speed(MOTOR_SPEED);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void arcRight()
{
  Set_Speed(MOTOR_SPEED);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void arcLeft()
{
  Set_Speed(MOTOR_SPEED);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void spotRight()
{
  Set_Speed(MOTOR_SPEED);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void spotLeft()
{
  Set_Speed(MOTOR_SPEED);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Stop()
{
  Set_Speed(0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setup() {
  Serial.begin(9600);
  btSerial.begin(9600);

  myArm.attach(ServoPin);
  // pin declarations
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(LEFT_ENABLE, OUTPUT);
  pinMode(RIGHT_ENABLE, OUTPUT);
}

void loop()
{
  if (btSerial.available() > 0)
  {
    receivedData = btSerial.read();
    Serial.println(receivedData);
    if (receivedData == 'F')
    {
      moveForward();
    }
    else if (receivedData == 'B')
    {
      moveBackward();
    }
    else if (receivedData == 'R')
    {
      spotRight();
    }
    else if (receivedData == 'L')
    {
      spotLeft();
    }
    else if (receivedData == 'I')
    {
      arcRight();
    }
    else if (receivedData == 'G')
    {
      arcLeft();
    }
    else if (receivedData == 'W')
    {
      myArm.write(0);
    }
    else if (receivedData == 'w')
    {
      myArm.write(60);
    }
    else if (receivedData == 'S')
    {
      Stop();
    }
    else
    {
      Stop();
    }
  }
}
