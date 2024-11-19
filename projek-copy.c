#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "cross-platform.h"

typedef struct {
    char soal[1000];
    char jawaban;
} Pertanyaan;

// Fungsi untuk mendapatkan soal acak
int getSoalAcak(int jumlahSoal, int used[]) {
    int idx;
    do {
        idx = rand() % jumlahSoal;
    } while (used[idx] == 1);  // Memastikan soal belum pernah dipakai
    used[idx] = 1;
    return idx;
}

// int cekJawaban(char jawabanPengguna, char jawabanBenar, int jumlahJawaban) {
//     for (int i = 0; i < jumlahJawaban; i++) {
//         if (strcasecmp(jawabanPengguna, jawabanBenar[i]) == 0) {
//             return 1;  // Jawaban benar
//         }
//     }
//     return 0;
// }

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
    int uang = 0, maxSoal = 10;
    int *idx = ptrElemenAcak(maxSoal);
    char jawabanPengguna;
    
    Pertanyaan kumpulanSoal[maxSoal] = {
        {"Ibukota Indonesia? \n a. Banten\n b. Jakarta\n c. Medan\n d. Surabaya", 'b'},
        {"100 x 3 / 2 = ? \n a. 160\n b. 150\n c. 120\n d. 130", {"b"}},
        {"Planet terbesar di tata surya? \n a. Merkurius\n b. Pluto\n c. Saturnus\n d. Jupiter", 'd'},
        {"Hewan tercepat di dunia?\n a. Harimau\n b. Macan\n c. Singa\n d. Cheetah", 'd'},
        {"Lambang kimia untuk air?\n a. NaCl\n b. NaOH\n c. H2O\n d. O2", 'c'},
        {"5 x 2 + 10 / 2 = ?\n a. 16\n b. 15\n c. 17\n d. 12", 'b'},
        {"Gunung tertinggi di dunia?\n a. Bromo\n b. Everest\n c. Kangchenjunga\n d. Lhotse", 'b'},
        {"Danau terbesar di dunia?\n a. Superior\n b. Huron\n c. Kaspia\n d. Sentani", 'c'},
        {"Siapa nama presiden pertama Republik Indonesia?\n a. Megawati Soekarnoputri\n b. Mohammad Hatta\n c. B.J. Habibie\n d. Ir. Soekarno", 'd'},
        {"Apa nama ibu kota negara Australia?\n a. Sydney\n b. Melbourne\n c. Canberra\n d. Perth", 'c'}
    };
    

    printf("Selamat datang di Game Quiz!\n");
    printf("Jawab 10 soal dengan benar untuk memenangkan permainan.\n");
    printf("Anda hanya memiliki waktu 15 detik untuk setiap soal.\n");
    printf("Jika salah atau waktu habis, Anda akan tereliminasi.\n\n");



    int countdown = 15; // Waktu hitung mundur
    int inputReceived = 0; // Penanda apakah input sudah diterima

    time_t startTime, currentTime;

    // Ambil waktu saat program mulai
    time(&startTime);

    for (int i = 0; i < maxSoal; i++) {

        
        while (countdown > 0) {
            // Ambil waktu saat ini
            time(&currentTime);

            // Hitung selisih waktu
            if (difftime(currentTime, startTime) >= 1.0) {
                startTime = currentTime; // Reset waktu awal
                countdown--;             // Kurangi waktu hitung mundur
                printf("Hitung mundur: %d\n", countdown);
            }

            // Periksa apakah ada input dari pengguna
            if (!inputReceived) {
                printf("===================================================\n");
                printf("Soal  %d            : %s \n", i + 1, kumpulanSoal[idx[i]].soal);
                printf("Jawaban Anda       : ");
                jawabanPengguna = char_tanpa_buffer();
                if (jawabanPengguna) {
                    inputReceived = 1; // Tandai bahwa input diterima
                    break;
                }
            }
        }

        // Kondisi akhir
        if (inputReceived){
            if (jawabanPengguna == kumpulanSoal[idx[i]].jawaban)
                printf("Jawaban anda benar");
            else
                printf("Jawaban anda salah");
        }
        
        else {
            printf("Waktu habis!\n");
        }
        
        // Jeda 5 detik sebelum soal berikutnya
        printf("Jeda 5 detik sebelum soal berikutnya...\n\n");
        sleep(5);
    }

        

    // Jika semua soal dijawab benar
    printf("Selamat! Anda berhasil menjawab semua soal dengan benar!\n");
    printf("Skor akhir: %d\n", uang);
    printf("===================================================\n");
    
    return 0;
    
}
