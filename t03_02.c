#include <stdio.h>  // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Untuk INT_MAX dan INT_MIN

int main() {
    int n;           // Variabel untuk menyimpan jumlah bilangan yang akan dimasukkan
    int num;         // Variabel untuk menyimpan setiap bilangan yang dimasukkan
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan nilai integer terbesar yang mungkin
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan nilai integer terkecil yang mungkin
    
    // Variabel untuk menyimpan dua bilangan data pertama untuk perhitungan rata-rata
    int first_data_for_avg = 0;
    int second_data_for_avg = 0;
    double average_of_first_two = 0.0; // Untuk menyimpan hasil rata-rata

    // 1. Membaca baris pertama: jumlah bilangan (n)
    if (scanf("%d", &n) != 1) {
        printf("Masukan tidak valid untuk jumlah bilangan.\n");
        return 1; // Keluar dengan kode error
    }

    // Validasi n harus bilangan bulat positif
    if (n <= 0) {
        printf("Jumlah bilangan (n) harus positif.\n");
        return 1; // Keluar dengan kode error
    }
    
    // Validasi n minimal 2 untuk dapat menghitung rata-rata dua bilangan data pertama
    if (n < 2) {
        printf("Jumlah bilangan (n) harus minimal 2 untuk menghitung rata-rata dua bilangan pertama.\n");
        return 1; // Keluar dengan kode error
    }

    // 2. Membaca n baris masukan berikutnya
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &num) != 1) {
            printf("Masukan tidak valid pada baris ke-%d.\n", i + 2); // Baris ke-2 dst
            return 1; // Keluar dengan kode error
        }

        // Validasi bilangan dalam rentang -100 sampai 100
        if (num < -100 || num > 100) {
            printf("Bilangan ke-%d (%d) di luar rentang -100 hingga 100.\n", i + 1, num);
            return 1; // Keluar dengan kode error
        }

        // Simpan dua bilangan data pertama untuk perhitungan rata-rata
        if (i == 0) {
            first_data_for_avg = num;
        } else if (i == 1) {
            second_data_for_avg = num;
        }

        // Membandingkan dan memperbarui nilai minimum
        if (num < min_val) {
            min_val = num;
        }

        // Membandingkan dan memperbarui nilai maksimum
        if (num > max_val) {
            max_val = num;
        }
    }

    // Hitung rata-rata dua bilangan data pertama
    average_of_first_two = (double)(first_data_for_avg + second_data_for_avg) / 2.0;

    // 3. Menampilkan hasil keluaran
    printf("%d\n", min_val);
    printf("%d\n", max_val);
    printf("%.2f\n", average_of_first_two); // Menampilkan rata-rata dengan 2 digit presisi

    return 0; // Program berakhir dengan sukses
}
