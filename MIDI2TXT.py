import os
import sys
import argparse
import mido
from mido import MidiFile

def remove_last_two_chars(file_path):
    # 打开文件并读取内容
    with open(file_path, 'r', encoding='utf-8') as file:
        content = file.read()

    # 移除最后两个字符
    modified_content = content[:-2]

    # 重新写入修改后的内容
    with open(file_path, 'w', encoding='utf-8') as file:
        file.write(modified_content)

def midi_note_to_name(note):
    """将 MIDI 音符编号转换为音符名称，并提高参数中数量的八度。"""
    notes = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']
    octave = (note // 12) - 1 + args.octave  # 提高八度
    return f"{notes[note % 12]}{octave}"

def process_track(track, track_index, output_dir, ticks_per_beat):
    # 存储所有音符的开始和结束时间
    note_events = []

    # 第一步：遍历所有音符，收集开始和结束时间
    time = 0
    active_notes = {}
    for msg in track:
        time += msg.time
        if msg.type == 'note_on' and msg.velocity > 0:
            if msg.note not in active_notes:
                active_notes[msg.note] = time
        elif (msg.type == 'note_off' or (msg.type == 'note_on' and msg.velocity == 0)) and msg.note in active_notes:
            start_time = active_notes.pop(msg.note)
            duration = time - start_time
            note_events.append((start_time, duration, msg.note))

    # 第二步：按开始时间排序音符事件
    note_events.sort()

    # 第三步：分配音符到不同的组以避免重叠
    sequences = []
    last_end_times = []

    for start, duration, note in note_events:
        placed = False
        note_name = midi_note_to_name(note)
        for i, seq in enumerate(sequences):
            if last_end_times[i] <= start:
                seq.append((start, duration, note_name))
                last_end_times[i] = start + duration
                placed = True
                break
        if not placed:
            sequences.append([(start, duration, note_name)])
            last_end_times.append(start + duration)

    # 第四步：为每个序列生成txt文件并插入休止符
    track_folder = os.path.join(output_dir, f"Track_{track_index}")
    os.makedirs(track_folder, exist_ok=True)
    for i, seq in enumerate(sequences):
        with open(os.path.join(track_folder, f"melody{i+1}.txt"), 'w') as f:
            last_end = 0
            for start, duration, note_name in seq:
                # 插入休止符
                if start > last_end:
                    f.write(f"{tick2ms(start - last_end, ticks_per_beat)}, ")
                f.write(f"{note_name}-{tick2ms(duration, ticks_per_beat)}, ")
                last_end = start + duration
            # 移除最后一个逗号
            f.seek(0, os.SEEK_END)
            f.seek(f.tell() - 2, os.SEEK_SET)
            f.truncate()

def midi_to_parts(midi_file_path, output_dir):
    """将 MIDI 文件转换为多个不重叠的音符序列并保存在文本文件中。"""
    mid = MidiFile(midi_file_path)
    for i, track in enumerate(mid.tracks):
        process_track(track, i, output_dir, mid.ticks_per_beat)

def tick2ms(ticks, ticks_per_beat):
    """将 tick 数转换成 ms 。"""
    milliseconds = (ticks / ticks_per_beat) * (60000 / args.bpm)
    return round(milliseconds)

# 创建 ArgumentParser 对象
parser = argparse.ArgumentParser(description="Process some integers.")
# 添加 bpm 参数，类型为整数，设置默认值为 110
parser.add_argument('-bpm', type=int, default=110, help='Beats per minute')
# 添加 path 参数，类型为字符串，设置默认值为 'sirius.mid'
parser.add_argument('-path', type=str, default='sirius.mid', help='Input path')
# 添加 octave 参数，类型为整数，设置默认值为 1 表示上升一个八度(适用于 zave 0905 2300 ± 500 频率小蜂鸣器, 大型 2300 ± 300, 另一个小型是 2800 ± 300)
parser.add_argument('-octave', type=int, default=1, help='How many octaves are you gonna raise')
# 解析命令行参数
args = parser.parse_args()
output_directory = 'output'
midi_to_parts(args.path, output_directory)

