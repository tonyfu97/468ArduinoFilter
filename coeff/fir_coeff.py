# Generate coefficients for a FIR lowpass or notch filter

from scipy.signal import kaiserord, firwin, freqz

fs = 500;  # sampling freq in Hz
fc = np.array([59, 61]);   # cutoff freq in Hz

ripple_db = 30.0
width = 10 / fs
N, beta = kaiserord(ripple_db, width);
N |= 1  # convert N to odd number
hh = firwin(N, fc/(fs/2), window=('kaiser', beta), pass_zero='bandstop')


# visualize frequency response
w, h = freqz(hh)
plt.semilogx(fs * w / (2*np.pi), 20 * np.log10(np.maximum(abs(h), 1e-5)))
plt.title(f"FIR Filter Frequency Response")
plt.xlabel('Frequency [Hz]')
plt.ylabel('Amplitude [dB]')
plt.grid(which='both', axis='both')
plt.show()

# print out coefficients in C array format
def print_c_array(coeff, name, dtype='float'):
    coeff_str = f"const {dtype} {name} = {{"
    for c in coeff:
        coeff_str += f"{c:.8f},"
    coeff_str += "};"
    print(coeff_str)
print_c_array(hh, 'h')
print(f"filter length = {len(hh)}")