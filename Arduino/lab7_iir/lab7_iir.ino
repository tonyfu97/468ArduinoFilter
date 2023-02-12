/*
 * Implement a IIR notch filter to remove 60 Hz noise from ECG signal.
 * tonyfu97@uw.edu, Feb 2023
 */

// Sampling constants
const int FS = 500;  // in Hz
const uint32_t SAMPLE_INTERVAL = float(1e6) / FS;  // in us

// Filter constants
const float A[] = {1.00000000,-2.89019559,4.05293022,-2.83928211,0.96508117,};
const float B[] = {0.98238544,-2.86473885,4.05324052,-2.86473885,0.98238544,};

const size_t FILTER_LENGTH = sizeof(A) / sizeof(float);

// Signal stuff
int16_t x[FILTER_LENGTH];
float y[FILTER_LENGTH];
int writeIdx;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // TODO: implement sampling
}

void filter() {
  // TODO: implement IIR filter
}
