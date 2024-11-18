#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    char soal[100];
    char jawaban[20];
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

int cekJawaban(char jawabanPengguna[], char jawabanBenar[][20], int jumlahJawaban) {
    for (int i = 0; i < jumlahJawaban; i++) {
        if (strcasecmp(jawabanPengguna, jawabanBenar[i]) == 0) {
            return 1;  // Jawaban benar
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));  // Inisialisasi angka acak berdasarkan waktu
    Pertanyaan soal[10] = {
        {"Ibukota Indonesia? \n a. Banten\n b. Jakarta\n c. Medan\n d. Surabaya", {"b"}},
        {"100 x 3 / 2 = ? \n a. 160\n b. 150\n c. 120\n d. 130", {"b"}},
        {"Planet terbesar di tata surya? \n a. Merkurius\n b. Pluto\n c. Saturnus\n d. Jupiter", {"d"}},
        {"Hewan tercepat di dunia?\n a. Harimau\n b. Macan\n c. Singa\n d. Cheetah", {"d"}},
        {"Lambang kimia untuk air?\n a. NaCl\n b. NaOH\n c. H2O\n d. O2", {"c"}},
        {"5 x 2 + 10 / 2 = ?\n a. 16\n b. 15\n c. 17\n d. 12", {"15"}},
        {"Gunung tertinggi di dunia?\n a. Bromo\n b. Everest\n c. Kangchenjunga\n d. Lhotse", {"b"}},
        {"Danau terbesar di dunia?\n a. Superior\n b. Huron\n c. Kaspia\n d. Sentani", {"c"}},
        {"Siapa nama presiden pertama Republik Indonesia?\n a. Megawati Soekarnoputri\n b. Mohammad Hatta\n c. B.J. Habibie\n d. Ir. Soekarno", {"d"}},
        {"Apa nama ibu kota negara Australia?\n a. Sydney\n b. Melbourne\n c. Canberra\n d. Perth", {"c"}}
    };
    
    int uang = 0, maxSoal = 10;
    int used[10] = {0};  // Menyimpan soal yang sudah dipakai

    printf("Selamat datang di Game Quiz!\n");
    printf("Jawab 10 soal dengan benar untuk memenangkan permainan.\n");
    printf("Anda hanya memiliki waktu 15 detik untuk setiap soal.\n");
    printf("Jika salah atau waktu habis, Anda akan tereliminasi.\n\n");

    for (int i = 0; i < maxSoal; i++) {
        int idx = getSoalAcak(maxSoal, used);
        char jawabanPengguna[20];

        printf("===================================================\n");
        printf("Soal  %d            : %s \n", i + 1, soal[idx].soal);
        printf("Jawaban Anda       : ", jawabanPengguna);
        fgets(jawabanPengguna, sizeof(jawabanPengguna), stdin);
        jawabanPengguna[strcspn(jawabanPengguna, "\n")] = 0;  // Menghilangkan karakter newline

        // Catat waktu saat soal dimulai
        time_t waktuMulai = time(NULL);
        time_t waktuSekarang;

        // Tunggu jawaban dengan batas waktu 15 detik
        int jawabanDiberikan = 0;  // Flag apakah jawaban diberikan tepat waktu
        while (1) {
            waktuSekarang = time(NULL);
            if (waktuSekarang - waktuMulai >= 15) {
                printf("Waktu habis! Anda tereliminasi.\n");
                printf("Skor akhir: %d\n", uang);
                return 0;  // Game berakhir jika waktu habis
            }
        if (jawabanDiberikan) {
        if (cekJawaban(jawabanPengguna, soal[idx].jawaban, 3)) {
            uang += 10 ;
            printf("Benar! Uang Anda   : %d Juta\n\n", uang);
        } else {
            printf("Salah! Anda tereliminasi.\n");
            printf("Skor akhir      : %d Juta\n", uang);
            printf("Silakan coba lagi!\n");
            printf("===================================================\n");
            return 0;  // Game berakhir jika salah
        }
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

}
