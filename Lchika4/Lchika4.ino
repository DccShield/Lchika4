//
// D5 port に接続したLEDを1秒周期で点滅を繰り替えす
// D6 port に接続したLEDを0.25秒周期で点滅を繰り替えす
//


unsigned long PreviosTimeA = 0;  // PreviosTime 前時間
unsigned long PreviosTimeB = 0;  // PreviosTime 前時間

void setup() {
  pinMode(5, OUTPUT);           // D5 portは出力ポート
  digitalWrite(5, LOW);         // 初期はLOW(OFF)出力
  pinMode(6, OUTPUT);           // D6 portは出力ポート
  digitalWrite(6, LOW);         // 初期はLOW(OFF)出力

  PreviosTimeA = millis();       // setup()終了時の時刻をPreviosTimeに格納
  PreviosTimeB = millis();       // setup()終了時の時刻をPreviosTimeに格納
}

void loop() {
  if( (millis() - PreviosTimeA ) >= 1000 ){  // 1000:1000msec 前回から1000ms経過したかチェック
    PreviosTimeA = millis();                 // 現在の時刻に更新
    led_chikaA(5);                            // led点滅処理
  }

  if( (millis() - PreviosTimeB ) >= 250 ){  // 250:250msec 前回から500ms経過したかチェック
    PreviosTimeB = millis();                 // 現在の時刻に更新
    led_chikaB(6);                            // led点滅処理
  }


}

//
// led点滅処理
//
void led_chikaA(unsigned char ch){
  static char ledState = 0;                 // ledの点灯状態格納用（staticは,ずっと忘れない変数）

  switch(ledState){
      case 0:                               // ledState = 0 つまり消灯だったら、LED点灯して、lesState=1
              digitalWrite(ch, HIGH);
              ledState = 1;
              break;
      case 1:                               // ledState = 1 点灯だったら、LED消灯して、lesState=0
              digitalWrite(ch, LOW);
              ledState = 0;
              break;
      default:                              // 万が一それ以外の数値がはいっていたら何もしない
              break;      
    }
}
void led_chikaB(unsigned char ch){
  static char ledState = 0;                 // ledの点灯状態格納用（staticは,ずっと忘れない変数）

  switch(ledState){
      case 0:                               // ledState = 0 つまり消灯だったら、LED点灯して、lesState=1
              digitalWrite(ch, HIGH);
              ledState = 1;
              break;
      case 1:                               // ledState = 1 点灯だったら、LED消灯して、lesState=0
              digitalWrite(ch, LOW);
              ledState = 0;
              break;
      default:                              // 万が一それ以外の数値がはいっていたら何もしない
              break;      
    }
}
