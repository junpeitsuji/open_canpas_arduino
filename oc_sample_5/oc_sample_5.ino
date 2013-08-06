// oc_sample_5.ino
// 両側に取り付けた赤外線測距センサーに反応して行動する二輪ロボットのプログラム

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
  int rangeR = getRange(0); // 右側の赤外線測距センサーの値を取得
  int rangeL = getRange(1); // 左側の赤外線測距センサーの値を取得

  if( rangeR > 0 && rangeR < 30 ){
    // 右側センサーに反応があったとき
    // TODO ここで前進／後進／旋回／停止のいずれかの関数を呼び出す

  }
  else if( rangeL > 0 && rangeL < 30 ){
    // 左側センサーに反応があったとき
    // TODO ここで前進／後進／旋回／停止のいずれかの関数を呼び出す
    
  }
  else {
    // 両側センサーに反応がないとき
    goForward(255);
  }
  // 100ミリ秒停止
  delay(100);
}

// 引数で指定したpinに接続された赤外線測距センサーの距離値を取得する関数
// cm単位の距離を整数値で返す。範囲外（10cm未満、又は80cmより大きい）の場合は0を返す。
int getRange(int pin) {

// 引数で指定されたpinの電圧値を0から1023の値で取得する
  int voltage = analogRead(pin);

  // 取得した電圧値を距離（cm）に変換
  int range = ((6787 / (voltage - 3)) - 4);
  
  if( range >= 10 && range <= 80 ){
    return range;
  }
  else {
    return 0;
  }
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

