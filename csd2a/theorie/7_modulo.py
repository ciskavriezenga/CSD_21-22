# exmample of the usage of a modulo to get beat index relative to a bar
from icecream import ic

num_beats = 100
num_beats_per_bar = 7

for beat_index in range(num_beats):
    ic(beat_index)
    ic(beat_index % num_beats_per_bar)
