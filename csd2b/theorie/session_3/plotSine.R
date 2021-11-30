# generate and display a sinewave with wavelength = 2pi
curve(expr=sin, from=0, to=2*pi, xname = "t")
abline(h = 0, lty = 1, col = "gray")


# generate and display a sinewave with wavelength = 1, frequency = 1
sinewave_freq1 <- function(t) sin(t * 2*pi)
curve(expr=sinewave_freq1, from=0, to=2*pi, xname = "t")
abline(h = 0, lty = 1, col = "gray")

# display the sinewave with frequency = 1 another time, from time interval [0,1]
curve(expr=sinewave_freq1, from=0, to=1, xname = "t")
abline(h = 0, lty = 1, col = "gray")



# ________________ discrete time _________________
# now every t index represents a sample
# samplerate = the number of samples per seconds
# thus a sinewave with frequency = 1 corresponds to a wavelength = samplerate 
samplerate = 44100
# instead of finishing the wave in 1 t interval - we need to 'slow it down' to 44100 
# thus 'divide' every step in 44100 smaller steps:
sinewave <- function(t) sin(t * 2*pi / samplerate)
curve(sinewave, 0, samplerate, xname = "x")
abline(h = 0, lty = 1, col = "gray")


# now let's add the frequency, 
# a sinewave with frequency = 2 has a two time shorter wavelength compared to a sinewave with frequency = 1
# thus at every sample step it 'goes two times faster', we can simply multiply t
frequency <- 2
sinewave <- function(t) sin(2* t * pi * frequency / samplerate)
curve(sinewave, add = TRUE, col = "violet")
frequency <- 10
sinewave <- function(t) sin(t * 2*pi * frequency / samplerate)
curve(sinewave, add = TRUE, col = "green")




# ________________ usage of phase _________________

# Let t indicate the index of a sample,
# then the equation is as follow.
# sample =  sin((t * 2 * pi) / samplerate)
#
# we can rewrite this function: 
# sample =  sin((t / samplerate) * 2 * pi)
#
# (t / samplerate) with interval t = [0, samplerate]results in the interval [0, 1]
# e.g. samplerate = 44100
# 0 / 44100 = 0
# 44100 / 44100 = 1

# Because the sin function is a periodic function 
# Therefore, with t > samplerate in (t/samplerate) * 2 * pi, the sine curve simply repeats
# thus (t / samplerate) can be viewed as the phase of the sinewave
# phase = t / samplerate

# Let's rewrite the equation.
# sample =  sin((t / samplerate) * 2 * pi)
# with phase = t / samplerate 
# results in: 
# sample = sin(phase * 2 * pi)
#
# To generate a sinewave with frequency = 1, it is sufficient to keep track of the phase
# and to increase this at each sample step.
# phase += frequenc / samplerate
#
# Now, let's also consider the frequency 
# To also take the frequency into account, we can simply add it as follow.
# phase += frequency / samplerate

samplerate = 44100
phase = 0
frequency = 2
sinewave <- function(t) {
  phase = phase + (frequency / samplerate)
  return (sin((t * frequency / samplerate) * 2*pi))
}
curve(sinewave, 0, samplerate, xname = "x")



