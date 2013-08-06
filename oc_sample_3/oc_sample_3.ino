// oc_sample_3.ino
// 赤外線測距センサーの値（電圧値）を読み取り、それを距離に変換しシリアルモニターに出力する

void setup() {
  // ボーレート 9600 でシリアル通信を開始する
  Serial.begin(9600); 
}

void loop() {
  // アナログ0番ピンに接続された測距センサーの距離を取得する
  int range = getRange(0);

  // 取得した距離情報をシリアルモニターに表示
  Serial.println(range); 

  // 100 ミリ秒停止する
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

