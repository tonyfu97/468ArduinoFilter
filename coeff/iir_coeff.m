% Generate coefficients for a Butterworth notch filter
% tonyfu97@uw.edu, Feb 2023

fc = [59 61];   % cutoff freq in Hz
fs = 500;       % sampling freq in Hz
n = 4;          % n is actually only 1/2 order for a bandstop filter
[B,A] = butter(n, fc./(fs/2), 'stop');

% visualize frequency response
fvtool(B,A);

% print out coefficients in C array format
disp(['const float A[] = {', sprintf('%0.8f,', A), '};']);
disp(['const float B[] = {', sprintf('%0.8f,', B), '};']);

