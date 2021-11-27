import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import math

# a frequency of 50, with samplerate 44100 --> period of 882
freq = 50.0
samplerate = 44100
period =  samplerate / freq
data = []
pi_2 = math.pi * 2.0
phase = 0
for i in range(int(period * 2)):
    tempPhase = (phase - 0.5) * pi_2;
    # generate approximation of sinewave, using polynomial
    if (tempPhase < 0):
        sample =  1.27323954 * tempPhase + .405284735 * tempPhase * tempPhase;
    else:
        sample = 1.27323954 * tempPhase - 0.405284735 * tempPhase * tempPhase;
    data.append(sample)
    phase += freq / samplerate
    # wrap phase
    if (phase > 1):
        phase -= 1


# transform list to numpy array
np_data = np.array(data)

# create samples for x axis
t = np.arange(0, len(data), 1)

# create plot
fig, ax = plt.subplots()
ax.plot(t, np_data)
plt.yticks(np.arange(-1., 1., 1.0))
ax.set(xlabel='sample', ylabel='output',
       title='Output data')
ax.grid()

# To save the result, outcomment the line below:
# fig.savefig("data_plot.png")
plt.show()
