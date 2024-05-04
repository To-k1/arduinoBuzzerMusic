# 以以下格式表示“[音符]-[持续时间单位数]，比如我想将音符C#4持续3个时间单位，输入'C#4-3'，每个音符之间拿逗号隔开，特别注意的是如果这里是休止符，比如休止4个时间单位，输入'4'
# int melody1[] = {262, 262, 392, 392, 440, 440, 392, 349, 349, 330, 330, 294, 294, 262};
# int durations1[] = {500, 500, 500, 500, 500, 500, 1000, 500, 500, 500, 500, 500, 500, 1000};
# Python脚本用于将输入转换成这两个数组一样的输出
import sys
import argparse

def note_to_frequency(note):
    """将音符转换为相应的频率。"""
    frequencies = {
        'C3': 131, 'C#3': 139, 'D3': 147, 'D#3': 156, 'E3': 165, 'F3': 175, 'F#3': 185,
        'G3': 196, 'G#3': 208, 'A3': 220, 'A#3': 233, 'B3': 247,
        'C4': 261, 'C#4': 277, 'D4': 294, 'D#4': 311, 'E4': 329, 'F4': 349, 'F#4': 370,
        'G4': 392, 'G#4': 415, 'A4': 440, 'A#4': 466, 'B4': 494,
        'C5': 523, 'C#5': 554, 'D5': 587, 'D#5': 622, 'E5': 659, 'F5': 698, 'F#5': 740,
        'G5': 784, 'G#5': 831, 'A5': 880, 'A#5': 932, 'B5': 988,
        'C6': 1047, 'C#6': 1109, 'D6': 1175, 'D#6': 1245, 'E6': 1319, 'F6': 1397, 'F#6': 1480,
        'G6': 1568, 'G#6': 1661, 'A6': 1760, 'A#6': 1865, 'B6': 1976,
        'C7': 2093, 'C#7': 2217, 'D7': 2349, 'D#7': 2489, 'E7': 2637, 'F7': 2794, 'F#7': 2960,
        'G7': 3136, 'G#7': 3322, 'A7': 3520, 'A#7': 3729, 'B7': 3951
    }
    return frequencies.get(note, 0)  # 如果音符不在字典中，默认返回0（休止符）

def parse_melody(input_string, bpm):
    """解析旋律字符串并返回频率和持续时间数组。"""
    notes = input_string.split(',')
    frequencies = []
    # 未知理由durations读取会错开一位，所以手动错开一位
    durations = [0]

    # 最小的时间单位(四分之一拍的时间)
    clock_cycle = 60 / bpm * 1000 / 4
    print(clock_cycle)
    
    for note_duration in notes:
        if '-' in note_duration:
            note, duration = note_duration.split('-')
            freq = note_to_frequency(note.strip())
            frequencies.append(freq)
            durations.append(int(int(duration.strip()) * clock_cycle))
        else:
            # 处理休止符
            duration = note_duration.strip()
            frequencies.append(0)  # 休止符的频率设置为0
            durations.append(int(int(duration) * clock_cycle))
    
    return frequencies, durations

def read_melody_from_file(file_path):
    """从文件中读取旋律字符串。"""
    with open(file_path, 'r') as file:
        return file.readline().strip()

# 创建 ArgumentParser 对象
parser = argparse.ArgumentParser(description="Process some integers.")
# 添加 bpm 参数，类型为整数，设置默认值为 110
parser.add_argument('-bpm', type=int, default=110, help='Beats per minute')
# 添加 tracks 参数，类型为整数，设置默认值为 5
parser.add_argument('-tracks', type=int, default=5, help='Number of tracks')
# 解析命令行参数
args = parser.parse_args()

input_melodies = [read_melody_from_file(f'melody{i + 1}.txt') for i in range(args.tracks)]

# 解析旋律
frequencies_list = [parse_melody(input_melody, args.bpm)[0] for input_melody in input_melodies]
durations_list = [parse_melody(input_melody, args.bpm)[1] for input_melody in input_melodies]

# 写入txt并打印输出，以便可以直接在Arduino代码中使用
with open("melodyArrays.txt", 'w') as f:
    for i in range(len(frequencies_list)):
        frequencies_array_str = f"int melody{i + 1}[] = " + str(frequencies_list[i]).replace('[', '{').replace(']', '}') + ';'
        durations_array_str = f"int durations{i + 1}[] = " + str(durations_list[i]).replace('[', '{').replace(']', '}') + ';'
        print(frequencies_array_str)
        print(durations_array_str)
        f.write(frequencies_array_str + '\n')
        f.write(durations_array_str + '\n')
