# 单片机多轨道蜂鸣器音乐
## Python脚本
### MIDI2TXT.py 将 midi 文件转化为如下格式的txt
- 一个midi可能有多个轨道，每个轨道内可能会有同时（某个音的持续时间内有别的音）的数个音，每个轨道生成一个文件夹，每个文件夹内若干个txt，使得每个txt中都没有同时的音符，并且同一个文件夹的所有txt表示的音符加起来就是完整的该midi轨道
- 旋律以以下格式表示“[音符]-[持续时间单位数]，比如将音符C#4持续3个时间单位表示为'C#4-3'，每个音符之间用逗号隔开，特别注意的是如果这里是休止符，比如休止4个时间单位，就表示为'4'
- 目前为四分之一拍为一个时间单位
- 命令行参数为 midi 文件目录
- 结果保存在 ./output
### convMelody.py 将 txt 文件转换为项目中所用到的数组文件
- 命令行参数为轨道数，默认为5
- 结果保存在 melodyArrays.txt
### 使用方法
```bash
pip install mido
python MIDI2TXT.py sirius.mid
python convMelody.py 5
```
## Arduino
- SiriusNoShinzou.ino 为 Arduino 项目代码文件
- 将 melodyArrays.txt 中的数组替换掉 SiriusNoShinzou.ino 中对应的数组即可
## STM32
- 待完善