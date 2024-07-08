//---------------------- PWM PINS  ---------------------- A0 (ARDUINO) --> EN_A (MOTOR DRIVER)
//---------------------- PWM PINS  ---------------------- A1 (ARDUINO) --> EN_B (MOTOR DRIVER)

//---------------------- RX PIN  ---------------------- D10 (ARDUINO) --> RX (HC05 BLUETOOTH MODULE)
//---------------------- TX PIN  ---------------------- D11 (ARDUINO) --> TX (HC05 BLUETOOTH MODULE)

//--------------------------------------------- D2 (ARDUINO) --> IN-1 (MOTOR DRIVER) --> OUT1 OF MOTOR(+VE)
//--------------------------------------------- D3 (ARDUINO) --> IN-2 (MOTOR DRIVER) --> OUT2 OF MOTOR
//--------------------------------------------- D4 (ARDUINO) --> IN-3 (MOTOR DRIVER) --> OUT3 OF MOTOR(+VE)
//--------------------------------------------- D7 (ARDUINO) --> IN-4 (MOTOR DRIVER) --> OUT4 OF MOTOR

#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial btSerial(10, 11); // RX, TX
Servo myArm;

char recivedData;  // Variable to store recived data

const int LEFT_ENABLE = A0; // ENABLE PINs DECLARATION
const int RIGHT_ENABLE = A1;

const int IN1 = 2; // CONTROL PINs DECLARATION
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 7;

const int ServoPin = 5;

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
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void spotLeft()
{
  Set_Speed(MOTOR_SPEED);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
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
    recivedData = btSerial.read();
    Serial.println(recivedData);
    if (recivedData == 'F')
    {
      moveForward();
    }
    else if (recivedData == 'B')
    {
      moveBackward();
    }
    else if (recivedData == 'R')
    {
      spotRight();
    }
    else if (recivedData == 'L')
    {
      spotLeft();
    }
    else if (recivedData == 'G')
    {
      arcRight();
    }
    else if (recivedData == 'I')
    {
      arcLeft();
    }
    else if (recivedData == 'W')
    {
      myArm.write(0);
    }
    else if (recivedData == 'w')
    {
      myArm.write(60);
    }
    else if (recivedData == 'S')
    {
      Stop();
    }
    else
    {
      Stop();
    }
  }
}
