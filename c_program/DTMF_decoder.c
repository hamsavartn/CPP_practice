#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define SAMPLING_RATE 8000.0f
#define N 205

const float ROW_FREQS[4] = {697.0f, 770.0f, 852.0f, 941.0f};
const float COL_FREQS[4] = {1209.0f, 1336.0f, 1477.0f, 1633.0f};

const char KEYPAD[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

float calc_coefficient(float target_freq) {
    int k = (int)(0.5f + ((float)N * target_freq / SAMPLING_RATE));
    float omega = (2.0f * M_PI * (float)k) / (float)N;
    return 2.0f * cosf(omega);
}

float goertzel_magnitude(const float *samples, float coeff) {
    float q0 = 0.0f;
    float q1 = 0.0f;
    float q2 = 0.0f;

    for (int i = 0; i < N; i++) {
        q0 = samples[i] + (coeff * q1) - q2;
        q2 = q1;
        q1 = q0;
    }

    return (q1 * q1) + (q2 * q2) - (coeff * q1 * q2);
}

char decode_dtmf(const float *samples) {
    float row_mags[4], col_mags[4];
    float row_harmonic_mags[4], col_harmonic_mags[4];
    
    int max_row_idx = 0, max_col_idx = 0;
    float max_row_mag = 0.0f, max_col_mag = 0.0f;

    for (int i = 0; i < 4; i++) {
        float row_coeff = calc_coefficient(ROW_FREQS[i]);
        row_mags[i] = goertzel_magnitude(samples, row_coeff);
        if (row_mags[i] > max_row_mag) {
            max_row_mag = row_mags[i];
            max_row_idx = i;
        }

        float col_coeff = calc_coefficient(COL_FREQS[i]);
        col_mags[i] = goertzel_magnitude(samples, col_coeff);
        if (col_mags[i] > max_col_mag) {
            max_col_mag = col_mags[i];
            max_col_idx = i;
        }
    }

    for (int i = 0; i < 4; i++) {
        float row_h_coeff = calc_coefficient(ROW_FREQS[i] * 2.0f);
        row_harmonic_mags[i] = goertzel_magnitude(samples, row_h_coeff);

        float col_h_coeff = calc_coefficient(COL_FREQS[i] * 2.0f);
        col_harmonic_mags[i] = goertzel_magnitude(samples, col_h_coeff);
    }

    const float MIN_THRESHOLD = 2000.0f; 
    if (max_row_mag < MIN_THRESHOLD || max_col_mag < MIN_THRESHOLD) {
        return '\0';
    }

    float twist = 10.0f * log10f(max_col_mag / max_row_mag);
    if (twist < -8.0f || twist > 4.0f) {
        return '\0';
    }

    const float HARMONIC_RATIO_LIMIT = 0.15f;
    if ((row_harmonic_mags[max_row_idx] / max_row_mag > HARMONIC_RATIO_LIMIT) ||
        (col_harmonic_mags[max_col_idx] / max_col_mag > HARMONIC_RATIO_LIMIT)) {
        return '\0';
    }

    return KEYPAD[max_row_idx][max_col_idx];
}

int main() {
    float sample_buffer[N]; 
    
    for (int i = 0; i < N; i++) {
        sample_buffer[i] = 0.0f;
    }

    char result = decode_dtmf(sample_buffer);
    if (result != '\0') {
        printf("Detected: %c\n", result);
    } else {
        printf("No valid tone detected.\n");
    }

    return 0;
}
