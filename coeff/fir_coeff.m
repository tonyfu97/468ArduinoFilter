% Generate coefficients for a FIR notch filter
% tonyfu97@uw.edu, Feb 2023
% Credit: https://www.mathworks.com/matlabcentral/answers/1591484-i-want-to-remove-50hz-noise-using-fir-notch-filter-in-ecg-signal

fs = 350;  % sampling freq in Hz
lowpass = false;

if lowpass
    fc = 30;
    n = 31;
    hh = fir1(n, fc./(fs/2), 'low');
else
    fcomb = [55 59 61 64];  % cutoff freq in [pass1 stop1 stop2 pass2] format
    mags = [1 0 1];
    dev = [[0.5 0.1 0.5]];
    [n,Wn,beta,ftype] = kaiserord(fcomb,mags,dev,fs);
    hh = fir1(n,Wn,ftype,kaiser(n+1,beta),'noscale');
end

% visualize frequency response
figure
freqz(hh, 1, 2^20, fs)
set(subplot(2,1,1), 'XLim', [0 100])
set(subplot(2,1,2), 'XLim', [0 100])

% print out coefficients in C array format
disp(['const float h[] = {', sprintf('%0.8f,', hh), '};']);