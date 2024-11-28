#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "cross-platform.h"

void clear_terminal()
    {printf("\e[1;1H\e[2J");} 

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
        int indexAcak;
        do {
            indexAcak = rand() % jumlahElemen; // Menghasilkan angka acak
        } while (penanda[indexAcak] == 1); // Ulangi jika angka sudah digunakan

        idx[i] = indexAcak;       // Simpan angka acak yang valid
        penanda[indexAcak] = 1;   // Menandai angka yang sudah digunakan
    }

    return idx;
}

typedef struct {
    char *soal;
    char jawaban;
} Pertanyaan;

int main() {
    int uang = 0;
    int maxSoal = 10;
    int *idx = ptrElemenAcak(maxSoal);
    const short int opsi[] = {'a', 'b', 'c', 'd'};
    char jawabanPengguna;
    
    Pertanyaan kumpulanSoal[10] = {
        {"Ibukota Indonesia? \n  a. Banten\n  b. Jakarta\n  c. Medan\n  d. Surabaya", 'b'},
        {"100 x 3 / 2 = ? \n  a. 160\n  b. 150\n  c. 120\n  d. 130", 'b'},
        {"Planet terbesar di tata surya? \n  a. Merkurius\n  b. Pluto\n  c. Saturnus\n  d. Jupiter", 'd'},
        {"Hewan tercepat di dunia?\n  a. Harimau\n  b. Macan\n  c. Singa\n  d. Cheetah", 'd'},
        {"Lambang kimia untuk air?\n  a. NaCl\n  b. NaOH\n  c. H2O\n  d. O2", 'c'},
        {"5 x 2 + 10 / 2 = ?\n  a. 16\n  b. 15\n  c. 17\n  d. 12", 'b'},
        {"Gunung tertinggi di dunia?\n  a. Bromo\n  b. Everest\n  c. Kangchenjunga\n  d. Lhotse", 'b'},
        {"Danau terbesar di dunia?\n  a. Superior\n  b. Huron\n  c. Kaspia\n  d. Sentani", 'c'},
        {"Siapa nama presiden pertama Republik Indonesia?\n  a. Megawati Soekarnoputri\n  b. Mohammad Hatta\n  c. B.J. Habibie\n  d. Ir. Soekarno", 'd'},
        {"Apa nama ibu kota negara Australia?\n  a. Sydney\n  b. Melbourne\n  c. Canberra\n  d. Perth", 'c'}
    };

    for (int i = 0; i < maxSoal; i++) {
        clear_terminal();
        printf("===================================================\n");
        printf("  Soal %d:\n  %s \n", i + 1, kumpulanSoal[idx[i]].soal);
        printf("  >> ");

        while (1) {  
            jawabanPengguna = '0';
            jawabanPengguna = char_tanpa_buffer();

            int flag = 0;
            for (int i = 0; i < sizeof(opsi)/sizeof(opsi[0]); i++)
            {    
                if (jawabanPengguna == opsi[i])
                {
                    flag = 1;
                    break;
                }
            }
                    
            if (!flag)
                continue;

            if (jawabanPengguna == kumpulanSoal[idx[i]].jawaban) 
            {
                uang += 1000000;
                printf("Jawaban Anda benar. Tekan n untuk melanjutkan..");
                
                char lanjut;
                do{
                    lanjut = char_tanpa_buffer();
                } while(lanjut != 'n');
                
                break;
            }

            else 
            {
                clear_terminal();
                printf("\nJawaban anda salah! Permainan berakhir.\n");
                free(idx);
                return 0;
            }
        }
    }        

    // Jika semua soal dijawab benar
    clear_terminal();
    printf("Selamat! Anda berhasil menjawab semua soal dengan benar!\n");
    printf("Skor akhir: %d\n", uang);
    printf("===================================================\n");
    free(idx);
    
    return 0;
    
}
