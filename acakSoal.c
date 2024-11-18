#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Fungsi ini mengisi nilai satu sampai dengan jumlahElemen ke dalam 
   sebuah pointer array dengan urutan acak. Berguna untuk membuat pemilihan
   soal secara acak */
int *ptrElemenAcak(int jumlahElemen) {
    int *idx = malloc(jumlahElemen * sizeof(int));
    int penanda[jumlahElemen]; // Array penanda

    for (int i = 0; i < jumlahElemen; i++) {
        penanda[i] = 0; // Inisialisasi ke 0
    }

    srand(time(NULL));
    for (int i = 0; i < jumlahElemen; i++) {
        int angkaAcak;
        do {
            angkaAcak = (rand() % jumlahElemen) + 1; // Menghasilkan angka acak
        } while (penanda[angkaAcak] == 1); // Ulangi jika angka sudah digunakan

        idx[i] = angkaAcak;       // Simpan angka acak yang valid
        penanda[angkaAcak] = 1;   // Menandai angka yang sudah digunakan
    }

    return idx;
}

int main() {
    int jumlahSoal = 10;
    int *urutanSoal1 = ptrElemenAcak(jumlahSoal);

    for (int i = 0; i < jumlahSoal; i++) {
        printf("%d, ", urutanSoal1[i]);
    }
    printf("\n");

    free(urutanSoal1); // Membebaskan memori
    return 0;
}
