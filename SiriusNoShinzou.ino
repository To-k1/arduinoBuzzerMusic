// 定义蜂鸣器连接的引脚
int buzzer1 = 5; // D15, GPIO5 (A1 as digital)
int buzzer2 = 4; // D14, GPIO4 (A0 as digital)
int buzzer3 = 13; // D7, GPIO13
int buzzer4 = 12; // D6, GPIO12
int buzzer5 = 14; // D5, GPIO14

int melody1[] = {0, 494, 659, 740, 784, 880, 988, 740, 0, 587, 659, 0, 659, 587, 523, 587, 0, 494, 659, 740, 784, 880, 988, 740, 0, 587, 0, 587, 659, 784, 740, 784, 0, 659, 740, 784, 880, 988, 740, 0, 587, 659, 1047, 988, 0, 988, 0, 988, 1047, 988, 880, 0, 880, 0, 880, 988, 740, 784, 659, 740, 784, 740, 784, 740, 587, 659, 0, 247, 196, 329, 220, 587, 784, 880, 988, 523, 784, 1175, 659, 1175, 1319, 1175, 784, 1175, 0, 988, 880, 784, 0, 784, 880, 988, 1175, 740, 587, 784, 587, 740, 784, 0, 784, 988, 880, 784, 880, 988, 740, 784, 1175, 659, 587, 523, 494, 440, 1319, 1175, 784, 1175, 0, 659, 740, 784, 880, 988, 1175, 0, 1175, 587, 1175, 1047, 988, 880, 784, 0, 392, 0, 294, 0, 294};
int durations1[] = {0, 818, 272, 272, 272, 545, 545, 545, 818, 272, 545, 409, 136, 272, 272, 545, 545, 272, 272, 272, 272, 545, 545, 545, 818, 272, 136, 136, 272, 545, 545, 545, 681, 409, 272, 272, 545, 545, 545, 954, 136, 545, 545, 545, 409, 136, 954, 136, 272, 272, 272, 136, 136, 681, 136, 272, 272, 272, 545, 272, 272, 545, 272, 272, 272, 272, 1227, 136, 272, 272, 272, 272, 272, 272, 272, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 272, 272, 272, 136, 136, 545, 545, 545, 545, 545, 545, 545, 545, 272, 136, 136, 545, 272, 272, 272, 272, 545, 545, 545, 272, 272, 272, 272, 272, 272, 545, 545, 545, 545, 545, 272, 272, 272, 272, 545, 409, 136, 272, 818, 545, 272, 818, 545, 1363, 272, 409, 136, 272, 272, 272};
int melody2[] = {0, 329, 392, 440, 247, 370, 294, 261, 329, 294, 0, 294, 0, 294, 370, 329, 370, 392, 494, 370, 294, 261, 294, 329, 294, 0, 261, 392, 370, 659, 0, 587, 0, 587, 0, 370, 523, 659, 587, 523, 494, 0, 494, 0, 523, 440, 392, 370, 440, 784, 0, 392, 370, 659, 392, 370, 494, 0, 329, 0, 329, 784, 392, 587, 880, 494, 294, 880, 1047, 294, 587, 988, 587, 523, 659, 370, 784, 988, 587, 0, 440, 587, 294, 523, 0, 587, 494, 440, 392, 440, 784, 440, 659, 880, 0, 294, 1047, 988, 659, 784, 0, 440, 659, 0, 370, 784, 740, 0, 740, 659, 587, 523, 494, 196, 0, 220, 0, 220};
int durations2[] = {0, 1636, 545, 545, 545, 545, 545, 545, 545, 545, 409, 136, 409, 136, 545, 545, 545, 545, 545, 545, 545, 545, 272, 272, 545, 545, 272, 272, 545, 545, 545, 545, 409, 136, 954, 136, 545, 545, 545, 272, 272, 818, 272, 545, 272, 272, 272, 272, 272, 272, 272, 272, 545, 545, 545, 545, 545, 1227, 1227, 136, 136, 545, 545, 545, 545, 545, 272, 272, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 272, 272, 545, 545, 545, 272, 272, 545, 272, 272, 272, 272, 545, 545, 545, 272, 818, 545, 545, 545, 545, 545, 545, 545, 272, 272, 545, 545, 272, 818, 545, 272, 818, 545, 1363, 409, 136, 272, 272, 272}; 
int melody3[] = {0, 370, 0, 370, 0, 294, 220, 0, 261, 220, 0, 196, 247, 294, 0, 294, 329, 247, 0, 220, 0, 247, 247, 220, 0, 247, 294, 494, 370, 494, 0, 294, 392, 329, 294, 220, 392, 294, 392, 329, 261, 659, 0, 0, 0, 523, 261, 0, 329, 0, 0, 247, 587, 329, 494, 740, 392, 0, 740, 784, 196, 261, 784, 0, 440, 494, 294, 659, 740, 494, 0, 294, 494, 0, 440, 0, 494, 294, 196, 494, 370, 329, 587, 0, 0, 261, 329, 294, 587, 0, 370, 494, 294, 392, 0, 392, 0, 261, 329, 294, 196, 294, 0, 294, 0, 196, 0, 196};
int durations3[] = {0, 2181, 409, 136, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 1090, 954, 136, 545, 545, 545, 272, 272, 545, 545, 545, 1090, 545, 272, 272, 545, 545, 545, 545, 545, 1227, 1227, 272, 545, 545, 545, 545, 545, 272, 272, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 409, 409, 272, 545, 545, 272, 272, 545, 545, 545, 545, 545, 545, 272, 272, 1090, 545, 545, 545, 545, 545, 545, 545, 545, 409, 136, 1090, 545, 545, 545, 545, 545, 409, 136, 545, 545, 272, 272, 272};
int melody4[] = {0, 247, 0, 247, 0, 247, 0, 0, 196, 147, 0, 220, 247, 0, 247, 0, 247, 0, 0, 0, 196, 147, 0, 0, 247, 329, 247, 294, 0, 220, 261, 0, 261, 247, 0, 196, 0, 0, 220, 220, 392, 0, 0, 392, 0, 0, 0, 247, 220, 247, 220, 0, 0, 0, 0, 494, 0, 392, 587, 0, 587, 261, 0, 196, 494, 0, 370, 329, 0, 392, 0, 370, 0, 220, 0, 261, 0, 261, 196, 0, 196, 0, 0, 0, 247, 294, 0, 294, 0, 294, 0, 0, 196, 261, 147, 196, 0, 294, 329, 247, 329, 196, 0, 131, 196, 261, 0, 220, 0, 220};
int durations4[] = {0, 2181, 409, 136, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 409, 136, 545, 545, 545, 545, 1090, 545, 545, 545, 545, 545, 1090, 954, 136, 545, 409, 136, 545, 272, 272, 545, 545, 545, 1090, 545, 545, 545, 545, 545, 545, 545, 272, 272, 272, 272, 272, 272, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 272, 272, 272, 545, 272, 545, 545, 545, 136, 136, 272, 545, 545, 272, 272, 409, 136, 409, 136, 1090, 545, 272, 272, 545, 545, 545, 545, 545, 545, 545, 545, 1090, 545, 545, 545, 545, 545, 409, 136, 545};
int melody5[] = {0, 165, 0, 185, 165, 247, 0, 131, 0, 147, 0, 196, 0, 196, 0, 196, 0, 196, 0, 147, 0, 370, 131, 0, 196, 0, 294, 0, 196, 0, 147, 0, 147, 0, 196, 147, 0, 147, 0, 165, 0, 196, 0, 220, 0, 196, 0, 196};
int durations5[] = {0, 8999, 818, 4363, 545, 545, 1090, 1636, 545, 545, 545, 3272, 545, 1090, 545, 1090, 545, 2727, 545, 1090, 545, 545, 545, 545, 1090, 545, 2181, 545, 1636, 545, 545, 409, 136, 272, 1363, 545, 954, 136, 1090, 545, 1090, 1090, 1090, 4363, 545, 545, 409, 136, 545};

// 时间控制变量
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
unsigned long previousMillis4 = 0;
unsigned long previousMillis5 = 0;
int noteIndex1 = 0;
int noteIndex2 = 0;
int noteIndex3 = 0;
int noteIndex4 = 0;
int noteIndex5 = 0;
bool finished1 = false;
bool finished2 = false;
bool finished3 = false;
bool finished4 = false;
bool finished5 = false;

void setup() {
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(buzzer3, OUTPUT);
  pinMode(buzzer4, OUTPUT);
  pinMode(buzzer5, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  // 控制每个蜂鸣器的音乐播放
  controlTone(buzzer1, melody1, durations1, sizeof(melody1) / sizeof(melody1[0]), currentMillis, previousMillis1, noteIndex1, finished1);
  controlTone(buzzer2, melody2, durations2, sizeof(melody2) / sizeof(melody2[0]), currentMillis, previousMillis2, noteIndex2, finished2);
  controlTone(buzzer3, melody3, durations3, sizeof(melody3) / sizeof(melody3[0]), currentMillis, previousMillis3, noteIndex3, finished3);
  controlTone(buzzer4, melody4, durations4, sizeof(melody4) / sizeof(melody4[0]), currentMillis, previousMillis4, noteIndex4, finished4);
  controlTone(buzzer5, melody5, durations5, sizeof(melody5) / sizeof(melody5[0]), currentMillis, previousMillis5, noteIndex5, finished5);

  // 如果旋律都已经播放完毕，停止loop循环
  if (finished1 && finished2 && finished3 && finished4 && finished5) {
    noTone(buzzer1);  // 确保关闭buzzer1
    noTone(buzzer2);  // 确保关闭buzzer2
    noTone(buzzer3);
    noTone(buzzer4);
    noTone(buzzer5);
    ESP.deepSleep(0); // 永久休眠，直到设备复位
  }

}

void controlTone(int buzzer, int melody[], int durations[], int size, unsigned long currentMillis, unsigned long &previousMillis, int &noteIndex, bool &finished) {
  if (!finished && currentMillis - previousMillis >= durations[noteIndex]) {
    if (noteIndex < size) {
      previousMillis = currentMillis;
      tone(buzzer, melody[noteIndex], durations[noteIndex]);
      noteIndex++;
    } else {
      noTone(buzzer);
      finished = true;
    }
  }
}


