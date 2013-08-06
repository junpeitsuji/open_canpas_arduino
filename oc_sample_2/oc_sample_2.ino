// oc_sample_2.ino
// 一秒ごとにシリアルモニターに test と書き込み続けるサンプルプログラム

void setup() {
  // ボーレート 9600 でシリアル通信を開始する
  Serial.begin(9600); 
}

void loop() {
  // シリアルモニターに test と出力する
  Serial.println("test");
  // 1000 ミリ秒停止する
  delay(1000);  
}

