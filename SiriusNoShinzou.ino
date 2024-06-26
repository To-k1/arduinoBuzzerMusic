// 定义蜂鸣器连接的引脚
int buzzer1 = 5; // D15, GPIO5 (A1 as digital)
int buzzer2 = 4; // D14, GPIO4 (A0 as digital)
int buzzer3 = 13; // D7, GPIO13
int buzzer4 = 12; // D6, GPIO12
int buzzer5 = 14; // D5, GPIO14

int melody1[] = {0, 2000, 2100, 2200, 2300, 2400, 2500, 2600, 2700, 2800, 2900, 3000, 3100, 3200, 3300, 3400, 3500, 3600, 3700, 3800, 3900, 4000, 988, 2349, 2349, 1047, 1175, 988, 587, 784, 988, 2637, 2960, 659, 3520, 2349, 1175, 0, 880, 523, 1047, 988, 880, 784, 1175, 3951, 0, 3951, 2093, 1760, 1568, 1480, 1760, 2637, 2960, 1568, 2637, 2960, 784, 2960, 3136, 2960, 2349, 784, 880, 988, 880, 988, 784, 1319, 880, 1319, 3136, 3520, 784, 1319, 1175, 587, 1568, 1175, 1480, 523, 784, 784, 784, 2349, 3520, 3136, 1319, 1175, 1175, 2960, 2349, 880, 1175, 784, 1175, 1760, 3136, 587, 0, 1976, 1760, 1568, 1760, 784, 1175, 1175, 2349, 2637, 2349, 2093, 1976, 1760, 1047, 1047, 587, 784, 784, 2637, 3520, 988, 1319, 2960, 2349, 2960, 2637, 2349, 880, 784, 784, 784, 784, 0, 784, 0, 784};
int durations1[] = {0, 818, 273, 273, 273, 545, 545, 545, 545, 545, 545, 545, 273, 273, 545, 545, 545, 273, 273, 545, 545, 545, 545, 545, 273, 273, 273, 273, 545, 545, 545, 545, 273, 273, 545, 545, 545, 955, 136, 545, 545, 545, 273, 273, 545, 545, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 545, 273, 273, 545, 273, 273, 273, 273, 545, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 545, 545, 545, 545, 273, 273, 545, 545, 545, 545, 545, 545, 273, 273, 545, 545, 545, 545, 273, 545, 273, 545, 545, 273, 273, 273, 273, 273, 273, 273, 273, 545, 545, 545, 273, 273, 273, 273, 273, 273, 545, 545, 545, 545, 1091, 273, 273, 545, 545, 273, 818, 545, 273, 818, 545, 545, 545, 545, 409, 136, 273, 273, 273};
int melody2[] = {0, 3136, 1480, 1480, 2960, 0, 1175, 2637, 784, 880, 1175, 988, 988, 3136, 1175, 1319, 1976, 1480, 880, 2637, 1319, 880, 3136, 0, 740, 1319, 988, 1976, 0, 1175, 1047, 1319, 1175, 2093, 1568, 0, 1568, 880, 880, 3136, 0, 3136, 1480, 1568, 1047, 1480, 1319, 0, 2349, 988, 1976, 1568, 1568, 2349, 1976, 0, 2349, 1047, 1175, 1047, 1976, 0, 3951, 1480, 1976, 1480, 1568, 3951, 1976, 0, 1760, 1047, 2349, 2093, 0, 784, 3951, 3520, 3136, 3520, 1976, 1480, 1319, 3520, 0, 1175, 0, 1319, 1175, 2349, 0, 2637, 2960, 3136, 0, 1175, 1568, 0, 0, 0, 0, 3951, 1047, 1976, 0, 1568, 0, 880, 0, 880};
int durations2[] = {0, 1636, 545, 545, 545, 818, 273, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 682, 409, 545, 545, 1091, 955, 136, 545, 545, 545, 273, 273, 545, 545, 545, 1091, 545, 273, 273, 545, 545, 545, 545, 545, 1227, 1227, 273, 545, 545, 545, 545, 545, 273, 273, 545, 545, 545, 545, 545, 273, 273, 545, 545, 545, 545, 545, 409, 136, 545, 545, 545, 273, 273, 545, 273, 273, 273, 273, 545, 545, 545, 273, 818, 545, 545, 545, 545, 545, 545, 273, 273, 273, 273, 545, 545, 273, 818, 545, 273, 818, 545, 1364, 273, 409, 136, 273, 273, 273};
int melody3[] = {0, 1568, 1760, 0, 1175, 2349, 0, 1047, 1175, 2349, 1175, 1175, 659, 0, 659, 2960, 0, 1175, 784, 1175, 0, 1047, 1568, 988, 1976, 1175, 2349, 0, 1480, 1568, 2637, 2349, 0, 1976, 0, 1976, 1319, 1047, 3951, 0, 2093, 1568, 0, 1976, 0, 1319, 2349, 2093, 1976, 2960, 2637, 2960, 3136, 0, 2349, 3136, 0, 1760, 2637, 3520, 2637, 0, 2960, 2349, 1976, 0, 2960, 0, 1976, 1175, 784, 3136, 1760, 2637, 0, 0, 0, 3951, 2637, 3136, 0, 1175, 1319, 1480, 3136, 784, 523, 784, 1175, 3136, 0, 1175, 0, 1175};
int durations3[] = {0, 2182, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 682, 136, 818, 818, 273, 545, 1091, 545, 273, 273, 545, 545, 545, 1091, 955, 136, 545, 545, 545, 273, 273, 818, 273, 545, 1091, 545, 273, 1364, 545, 545, 545, 1227, 1500, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 273, 273, 545, 545, 545, 545, 545, 545, 273, 1364, 545, 545, 545, 545, 545, 545, 545, 545, 545, 1636, 545, 545, 545, 1364, 818, 273, 273, 273};
int melody4[] = {0, 3520, 3951, 0, 1480, 0, 1319, 2093, 0, 1976, 1480, 0, 1480, 1568, 0, 3136, 2960, 0, 1175, 2637, 1480, 2960, 0, 2349, 2093, 0, 587, 3951, 0, 3520, 3520, 0, 3520, 784, 0, 2637, 0, 2637, 0, 3136, 0, 2349, 3520, 0, 3520, 0, 0, 3136, 3951, 0, 2093, 3136, 0, 3136, 988, 0, 2349, 0, 587, 2349, 0, 3951, 2960, 3136, 587, 0, 659, 3136, 0, 0, 1480, 1976, 3951, 0, 1568, 1047, 1319, 2093, 0, 880, 880};
int durations4[] = {0, 2182, 545, 545, 545, 545, 1091, 545, 545, 818, 273, 545, 545, 545, 545, 2182, 545, 545, 1091, 545, 545, 1091, 955, 136, 545, 545, 545, 545, 955, 955, 273, 682, 136, 273, 545, 1091, 545, 1091, 1227, 2045, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 545, 818, 818, 545, 545, 545, 545, 1091, 545, 545, 545, 1091, 545, 1091, 545, 545, 545, 545, 545, 545, 545, 1636, 545, 545, 545, 545, 545, 545};
int melody5[] = {0, 3520, 3951, 0, 1480, 3136, 0, 3951, 0, 2637, 0, 3951, 0, 1568, 0, 3136, 0, 988, 0, 3951, 0, 3136, 0, 0, 0, 0, 0, 0, 0, 988, 0, 3951, 0, 1480, 0, 3136, 0, 1047, 3136, 0, 988, 587, 1175, 0, 784, 0, 0, 1760, 0, 3520, 0, 1175, 1175};
int durations5[] = {0, 8727, 545, 545, 4364, 545, 545, 545, 545, 1636, 545, 545, 545, 3273, 545, 1091, 545, 1364, 273, 2727, 545, 545, 545, 545, 545, 545, 545, 1091, 545, 1364, 409, 409, 545, 273, 273, 1091, 545, 545, 545, 545, 1364, 273, 1091, 1091, 818, 273, 545, 1636, 545, 4364, 545, 545, 545, 545};

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


