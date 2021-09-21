import simpleaudio as sa
import time

# expected input:
# first number: number of note durations
# from index 1 to index x: note durations
# last: bpm
# example: 4 1 0.5 1.5 0.5 120


# ___ retrieve all necessary values and lists necessary for playing rhythm ___

# retrieve note durations and bpm from input
num_notes = input()
note_durations = list()

for i in range(int(num_notes)):
    note_durations.append(float(input()))

print("note_durations:", note_durations)
bpm = float(input())
quarternote_dur = 60.0 / bpm
print("bpm:", bpm, "quarternote_dur", quarternote_dur)

# transform note durations to sequence of time durations
time_durations = []
for note_dur in note_durations:
    time_durations.append(quarternote_dur * note_dur)

print("time_durations", time_durations)


# ___ play rhythm ___

# load a sample
sample_pop = sa.WaveObject.from_wave_file("./assets/Pop.wav")

time_zero = time.time()
time_accumulated = 0
# play rhythm
for time_dur in time_durations:
    time_cur = time.time() - time_zero
    time_deviation = time_cur - time_accumulated
    print("time_deviation:", time_deviation)
    sample_pop.play()
    time.sleep(time_dur)
    time_accumulated = time_accumulated + time_dur
