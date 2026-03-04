
#include <stdio.h> // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Untuk INT_MAX dan INT_MIN


int main() {
    int n; // Variabel untuk menyimpan jumlah bilangan yang akan dimasukkan
    int num; // Variabel untuk menyimpan setiap bilangan yang dimasukkan
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan nilai integer terbesar yang mungkin
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan nilai integer terkecil yang mungkin

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

        // Membandingkan dan memperbarui nilai minimum
        if (num < min_val) {
            min_val = num;
        }

        // Membandingkan dan memperbarui nilai maksimum
        if (num > max_val) {
            max_val = num;
        }
    }

    // 3. Menampilkan hasil keluaran
    printf("%d\n", min_val);
    printf("%d\n", max_val);

    return 0; // Program berakhir dengan sukses
}
