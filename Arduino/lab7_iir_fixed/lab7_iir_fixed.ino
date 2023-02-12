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
int32_t x[FILTER_LENGTH];
int32_t y[FILTER_LENGTH];
int writeIdx;

// Fixed point stuff
const int FRAC_BITS = 16;
const uint32_t SCALE = (1L << FRAC_BITS);
int32_t fixedA[FILTER_LENGTH];
int32_t fixedB[FILTER_LENGTH];

void setup() {
  Serial.begin(115200);
  init_filter();
}

void loop() {
  // TODO: include sampling code
}

void filter() {
  // TODO: implement filter
}

void init_filter() {
  for (int i = 0; i < FILTER_LENGTH; i++) {
    fixedA[i] = (int32_t)(A[i] * SCALE);
    fixedB[i] = (int32_t)(B[i] * SCALE);
  }
}
