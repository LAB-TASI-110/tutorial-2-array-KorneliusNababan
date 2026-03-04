#include <stdio.h>  // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Untuk INT_MAX dan INT_MIN
#include <float.h>  // Untuk DBL_MIN (digunakan untuk inisialisasi rata-rata tertinggi)

int main() {
    int n;           // Variabel untuk menyimpan jumlah bilangan yang akan dimasukkan
    int num;         // Variabel untuk menyimpan setiap bilangan yang dimasukkan
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan nilai integer terbesar yang mungkin
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan nilai integer terkecil yang mungkin
    
    // Variabel untuk menyimpan dua bilangan data pertama untuk perhitungan rata-rata spesifik
    int first_data_for_avg = 0;
    int second_data_for_avg = 0;
    double average_of_first_two = 0.0; // Untuk menyimpan hasil rata-rata dua bilangan pertama

    int prev_num = 0; // Variabel untuk menyimpan bilangan sebelumnya guna menghitung rata-rata berurutan
    // Inisialisasi rata-rata tertinggi dengan nilai floating point terkecil yang mungkin,
    // agar rata-rata pertama yang valid pasti lebih besar dan menjadi nilai awal.
    double highest_consecutive_avg = -DBL_MAX; 

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
    
    // Validasi n minimal 2 untuk dapat menghitung kedua jenis rata-rata
    if (n < 2) {
        printf("Jumlah bilangan (n) harus minimal 2 untuk menghitung rata-rata dua bilangan pertama dan rata-rata tertinggi dari pasangan berturut.\n");
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

        // Simpan dua bilangan data pertama untuk perhitungan rata-rata spesifik
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

        // Hitung rata-rata pasangan berurutan (jika sudah ada bilangan sebelumnya)
        if (i > 0) {
            double current_consecutive_avg = (double)(prev_num + num) / 2.0;
            if (current_consecutive_avg > highest_consecutive_avg) {
                highest_consecutive_avg = current_consecutive_avg;
            }
        }
        
        // Simpan bilangan saat ini sebagai bilangan sebelumnya untuk iterasi berikutnya
        prev_num = num;
    }

    // Hitung rata-rata dua bilangan data pertama setelah loop selesai
    average_of_first_two = ((double)first_data_for_avg + second_data_for_avg) / 2.0;

    // 3. Menampilkan hasil keluaran
    printf("%d\n", min_val);
    printf("%d\n", max_val);
    printf("%.2f\n", average_of_first_two); // Menampilkan rata-rata dua bilangan pertama dengan 2 digit presisi
    printf("%.2f\n", highest_consecutive_avg); // Menampilkan rata-rata tertinggi dari pasangan berturut dengan 2 digit presisi

    return 0; // Program berakhir dengan sukses
}
