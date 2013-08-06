// oc_sample_4.ino
// Ardumotoを使って左右２個のモーターを制御するプログラム
// 左右独立に前転・後転でき、スピードも変えられる

int pwm_a = 3;   //PWM control for motor outputs 1 and 2 is on digital pin 3
int pwm_b = 11;  //PWM control for motor outputs 3 and 4 is on digital pin 11
int dir_a = 12;  //direction control for motor outputs 1 and 2 is on digital pin 12
int dir_b = 13;  //direction control for motor outputs 3 and 4 is on digital pin 13

void setup()
{
  Serial.begin(9600);
  
  pinMode(pwm_a, OUTPUT);  //Set control pins to be outputs
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);
  
}

void loop()
{ 
  goForward(255); 
  Serial.println("Go forward.");
  delay(2000);
  
  stopped();
  Serial.println("Stopped.");
  delay(2000);
  
  goBackward(255);
  Serial.println("Go backward.");
  delay(2000);
  
  stopped();
  Serial.println("Stopped.");
  delay(2000);

  turnLeft(128);
  Serial.println("Turn left.");
  delay(2000);
  
  stopped();
  Serial.println("Stopped.");
  delay(2000);

  turnRight(128);
  Serial.println("Turn right.");
  delay(2000);

  stopped();
  Serial.println("Stopped.");
  delay(2000);
}

void goForward(int speed) // forward
{ 
  digitalWrite(dir_a, HIGH);  //Reverse motor direction, 1 high, 2 low
  digitalWrite(dir_b, HIGH);  //Reverse motor direction, 3 low, 4 high  
  analogWrite(pwm_a, speed);    //set both motors to run at (100/255 = 39)% duty cycle
  analogWrite(pwm_b, speed);
}

void goBackward(int speed) // backward
{
  digitalWrite(dir_a, LOW);  //Set motor direction, 1 low, 2 high
  digitalWrite(dir_b, LOW);  //Set motor direction, 3 high, 4 low
  analogWrite(pwm_a, speed);   //set both motors to run at 100% duty cycle (fast)
  analogWrite(pwm_b, speed);
}

void stopped() //stop
{ 
  digitalWrite(dir_a, LOW); //Set motor direction, 1 low, 2 high
  digitalWrite(dir_b, LOW); //Set motor direction, 3 high, 4 low
  analogWrite(pwm_a, 0);    //set both motors to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 0); 
}

void turnLeft(int speed)  // turn left
{
  digitalWrite(dir_a, HIGH);  //Reverse motor direction, 1 high, 2 low
  digitalWrite(dir_b, LOW);  //Reverse motor direction, 3 low, 4 high  
  analogWrite(pwm_a, speed);    //set both motors to run at (100/255 = 39)% duty cycle
  analogWrite(pwm_b, speed);  
}

void turnRight(int speed)  // turn right
{
  digitalWrite(dir_a, LOW);  //Reverse motor direction, 1 high, 2 low
  digitalWrite(dir_b, HIGH);  //Reverse motor direction, 3 low, 4 high  
  analogWrite(pwm_a, speed);    //set both motors to run at (100/255 = 39)% duty cycle
  analogWrite(pwm_b, speed);  
}

