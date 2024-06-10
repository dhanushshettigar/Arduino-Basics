//---------------------- PWM PINS  ---------------------- D6 (ARDUINO) --> EN_A (MOTOR DRIVER)
//---------------------- PWM PINS  ---------------------- D9 (ARDUINO) --> EN_B (MOTOR DRIVER)

//--------------------------------------------- D2 (ARDUINO) --> IN-1 (MOTOR DRIVER) --> OUT1 OF MOTOR(+VE)
//--------------------------------------------- D3 (ARDUINO) --> IN-2 (MOTOR DRIVER) --> OUT2 OF MOTOR
//--------------------------------------------- D4 (ARDUINO) --> IN-3 (MOTOR DRIVER) --> OUT3 OF MOTOR(+VE)
//--------------------------------------------- D5 (ARDUINO) --> IN-4 (MOTOR DRIVER) --> OUT4 OF MOTOR


const int LEFT_ENABLE = 6; // ENABLE PINs DECLARATION
const int RIGHT_ENABLE = 9;

const int IN1 = 2; // CONTROL PINs DECLARATION
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;

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
  // here call each motor control functions
  moveForward();
}
