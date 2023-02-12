# Generate coefficients for a Butterworth notch filter.

import numpy as np
from scipy import signal
import matplotlib.pyplot as plt

fc = np.array([59, 61]);   # cutoff freq in Hz
fs = 500;       # sampling freq in Hz
n = 2           # n is actually only 1/2 order for a bandstop filter
B, A = signal.butter(n, fc/(fs/2), btype='bandstop');

# visualize frequency response
w, h = signal.freqz(B, A, 100)
plt.semilogx(fs * w / (2*np.pi), 20 * np.log10(np.maximum(abs(h), 1e-5)))
plt.title(f"IIR Filter Frequency Response")
plt.xlabel('Frequency [Hz]')
plt.ylabel('Amplitude [dB]')
plt.grid(which='both', axis='both')
plt.show()

# print out coefficients in C array format
print(f"const float A[] = {[round(a, 8) for a in A]};");
print(f"const float B[] = {[round(b, 8) for b in B]};");
