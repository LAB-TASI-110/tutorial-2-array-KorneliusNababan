#include <stdio.h>

int main() {
    int current, previous;
    int first_input = 1;
    int min, max;
    float max_avg = -999999.0; // Inisialisasi dengan nilai sangat kecil

    while (scanf("%d", &current) != EOF) {
        // Tentukan nilai sentinel untuk berhenti, misal -7 sesuai contoh
        if (current == -7) {
            if (!first_input) {
                // Cetak hasil akhir sebelum keluar
                printf("%d\n", min);
                printf("%d\n", max);
                printf("%.2f\n", max_avg);
            }
            break;
        }

        if (first_input) {
            min = current;
            max = current;
            first_input = 0;
        } else {
            // Update Minimum dan Maximum
            if (current < min) min = current;
            if (current > max) max = current;

            // Hitung rata-rata dari dua nilai berurutan
            float current_avg = (float)(previous + current) / 2.0;
            
            // Update rata-rata tertinggi
            if (current_avg > max_avg) {
                max_avg = current_avg;
            }
        }
        
        previous = current;
    }

    return 0;
}