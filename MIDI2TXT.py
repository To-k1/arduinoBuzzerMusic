import os
import sys
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
    """将 MIDI 音符编号转换为音符名称，并提高一个八度。"""
    notes = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']
    octave = (note // 12) - 1 + 1  # 提高一个八度
    return f"{notes[note % 12]}{octave}"

def process_track(track, track_index, output_dir, ticks_per_beat):
    """处理单个MIDI轨道，并将输出写入确保没有音符重叠的多个文本文件中。"""
    events = []
    active_notes = {}
    time = 0
    last_event_end_time = 0  # 记录最后一个事件的结束时间

    for msg in track:
        time += msg.time
        if msg.type == 'note_on' and msg.velocity > 0:
            # 如果这是首个事件且时间已经推进，记录初始休止符
            if not events and time > 0:
                events.append((0, time / ticks_per_beat, 'Rest'))  # 添加开头的休止符
            active_notes[msg.note] = time
        elif (msg.type == 'note_off' or (msg.type == 'note_on' and msg.velocity == 0)) and msg.note in active_notes:
            start_time = active_notes.pop(msg.note)
            duration = (time - start_time) / ticks_per_beat
            events.append((start_time, duration, midi_note_to_name(msg.note)))
            last_event_end_time = time

    # 分配事件到不同的序列以避免重叠
    sequences = [[]]
    for start, duration, note in sorted(events, key=lambda x: x[0]):
        for seq in sequences:
            if not seq or seq[-1][0] + seq[-1][1] * ticks_per_beat <= start:
                seq.append((start, duration, note))
                break
        else:
            sequences.append([(start, duration, note)])

    # 写入文件
    track_folder = os.path.join(output_dir, f"Track_{track_index}")
    os.makedirs(track_folder, exist_ok=True)
    for i, seq in enumerate(sequences):
        with open(os.path.join(track_folder, f"melody{i+1}.txt"), 'w') as f:
            for idx, (start, duration, note) in enumerate(seq):
                if note == 'Rest':
                    f.write(f"{int(duration * 4)}")
                else:
                    f.write(f"{note}-{int(duration * 4)}")
                if idx < len(seq) - 1:
                    f.write(", ")

def midi_to_parts(midi_file_path, output_dir):
    """将 MIDI 文件转换为多个不重叠的音符序列并保存在文本文件中。"""
    mid = MidiFile(midi_file_path)
    for i, track in enumerate(mid.tracks):
        process_track(track, i, output_dir, mid.ticks_per_beat)

def main():
    midi_path = 'sirius.mid'
    output_directory = 'output'
    if len(sys.argv) > 1:
        midi_path = sys.argv[1]
    midi_to_parts(midi_path, output_directory)

if __name__ == "__main__":
    main()
