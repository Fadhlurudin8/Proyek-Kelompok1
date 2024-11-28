#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

// Fungsi untuk membersihkan terminal
void clear_terminal() {
    printf("\e[1;1H\e[2J");
}

// Fungsi ini mengisi nilai satu sampai jumlahElemen ke dalam
// sebuah pointer array dengan urutan acak.
int *ptrElemenAcak(int jumlahElemen) {
    int *idx = malloc(jumlahElemen * sizeof(int));
    int penanda[jumlahElemen];

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

char char_tanpa_buffer() {
    return _getch();
}

// Struktur untuk soal
typedef struct {
    char *soal;
    char jawaban;
} Soal;

int main() {
    int uang = 0;
    int maxSoal = 10;
    const char opsi[] = {'a', 'b', 'c', 'd'};
    char jawabanPengguna;

    // Kumpulan soal berdasarkan tingkat kesulitan
    Soal mudah[] = {
        {"Ibukota Indonesia? \n  a. Banten\n  b. Jakarta\n  c. Medan\n  d. Surabaya", 'b'},
        {"100 x 3 / 0 = ? \n  a. tak hingga\n  b. tak terdefinisi\n  c. 1\n  d. 0", 'b'},
        {"Planet terbesar di tata surya? \n  a. Merkurius\n  b. Pluto\n  c. Saturnus\n  d. Jupiter", 'd'},
        {"Hewan tercepat di dunia?\n  a. Harimau\n  b. Macan\n  c. Singa\n  d. Cheetah", 'd'},
        {"Lambang kimia untuk air?\n  a. NaCl\n  b. NaOH\n  c. H2O\n  d. O2", 'c'},
        {"5 x 2 + 10 / 2 = ?\n  a. 16\n  b. 15\n  c. 17\n  d. 12", 'b'},
        {"Gunung tertinggi di dunia?\n  a. Bromo\n  b. Everest\n  c. Kangchenjunga\n  d. Lhotse", 'b'},
        {"Danau terbesar di dunia?\n  a. Superior\n  b. Huron\n  c. Kaspia\n  d. Sentani", 'c'},
        {"Siapa nama presiden pertama Republik Indonesia?\n  a. Megawati Soekarnoputri\n  b. Mohammad Hatta\n  c. B.J. Habibie\n  d. Ir. Soekarno", 'd'},
        {"Apa nama ibu kota negara Australia?\n  a. Sydney\n  b. Melbourne\n  c. Canberra\n  d. Perth", 'c'}
    };

    Soal sedang[] = {
        {"Siapa penemu lampu pijar?\n a. Alexander Graham Bell\n b. Thomas Edison\n c. Nikola Tesla\n d. Albert Einstein", 'b'},
        {"Apa nama proses di mana tumbuhan mengubah cahaya matahari menjadi energi?\n a. Fotosintesis\n b. Respirasi\n c. Transpirasi\n d. Fermentasi", 'a'},
        {"Benua terbesar di dunia adalah...\n a. Afrika\n b. Asia\n c. Amerika Utara\n d. Eropa", 'b'},
        {"Siapa penyanyi yang dikenal dengan lagu ""My Heart Will Go On""?\n a. Whitney Houston\n b. Celine Dion\n c. Mariah Carey\n d. Adele", 'b'},
        {"Planet terdekat dengan matahari adalah...\n a. Venus\n b. Mars\n c. Merkurius\n d. Jupiter", 'c'},
        {"Lagu kebangsaan Indonesia adalah...\n a. Tanah Airku\n b. Indonesia Raya\n c. Garuda Pancasila\n d. Satu Nusa Satu Bangsa", 'b'},
        {"Sungai terpanjang di dunia adalah...\n a. Sungai Amazon\n b. Sungai Nil\n c. Sungai Yangtze\n d. Sungai Mississippi", 'b'},
        {"Kepulauan yang dikenal sebagai ""Seribu Pulau"" adalah...\n a. Maluku\n b. Bali\n c. Kepulauan Seribu\n d. Nusa Tenggara", 'c'},
        {"Bunga nasional Indonesia adalah...\n a. Melati\n b. Anggrek\n c. Mawar\n d. Kamboja", 'a'},
        {"Apa nama unsur kimia dengan simbol Au?\n a. Argentum\n b. Aluminium\n c. Emas\n d. Perak", 'c'}
    };

    Soal susah[] = {
        {"Siapa penulis novel ""Laskar Pelangi""?\n a. Andrea Hirata\n b. Pramoedya Ananta Toer\n c. Sapardi Djoko Damono\n d. Chairil Anwar", 'a'},
        {"Apa nama sistem penulisan yang digunakan oleh suku Maya?\n a. Hieroglif\n b. Cuneiform\n c. Alphabets\n d. Logogram", 'a'},
        {"Siapa yang menciptakan teori relativitas?\n a. Isaac Newton\n b. Albert Einstein\n c. Niels Bohr\n d. Stephen Hawking",'b'},
        {"Siapa yang dikenal sebagai ""Bapak Pembangunan"" di Indonesia?\n a. Sukarno\n b. Suharto\n c. B.J. Habibie\n d. Megawati Soekarnoputri", 'b'},
        {"Apa nama candi terbesar di Indonesia?\n a. Candi Borobudur\n b. Candi Prambanan\n c. Candi Mendut\n d. Candi Sewu", 'a'},
        {"Apa nama teori yang menjelaskan asal usul kehidupan di bumi?\n a. Teori Evolusi\n b. Teori Big Bang\n c. Teori Abiogenesis\n d. Teori Relativitas", 'c'},
        {"Siapa yang menulis buku ""Siti Nurbaya""?\n a. Hamka\n b. Marah Rusli\n c. Pramoedya Ananta Toer\n d. Chairil Anwar", 'b'},
        {"Apa nama teori yang menyatakan bahwa semua spesies berasal dari spesies lain melalui proses evolusi?\n a. Teori Kreasionisme\n b. Teori Evolusi\n c. Teori Spesiasi\n d. Teori Adaptasi", 'b'},
        {"Apa nama perjanjian yang mengakhiri Perang Dunia I?\n a. Perjanjian Versailles\n b. Perjanjian Trianon\n c. Perjanjian Saint-Germain\n d. Perjanjian Paris", 'a'},
        {"Siapa ilmuwan yang mengembangkan hukum gravitasi?\n a. Galileo Galilei\n b. Isaac Newton\n c. Albert Einstein\n d. Johannes Kepler", 'b'},
        {"Apa nama laut yang memisahkan Indonesia dan Australia?\n a. Laut China Selatan\n b. Laut Tasman\n c. Laut Arafuru\n d. Laut Sulu", 'b'}
    };

    Soal *kumpulanSoal = NULL;

    // Pilih tingkat kesulitan
    int pilih;
    clear_terminal();
    printf("Pilih kesulitan soal:\n1. Mudah\n2. Sedang\n3. Susah\n>> ");
    scanf("%d", &pilih);

    switch (pilih) {
        case 1:
            kumpulanSoal = mudah;
            maxSoal = sizeof(mudah) / sizeof(mudah[0]);
            break;
        case 2:
            kumpulanSoal = sedang;
            maxSoal = sizeof(sedang) / sizeof(sedang[0]);
            break;
        case 3:
            kumpulanSoal = susah;
            maxSoal = sizeof(susah) / sizeof(susah[0]);
            break;
        default:
            printf("Pilihan tidak valid.\n");
            return 1;
    }

    // Acak soal
    int *idx = ptrElemenAcak(maxSoal);

    // Main loop
    for (int i = 0; i < maxSoal; i++) {
        clear_terminal();
        printf("===================================================\n");
        printf("Soal %d:\n%s\n", i + 1, kumpulanSoal[idx[i]].soal);
        printf(">> ");

        // Input jawaban pengguna
        while (1) {
            // Ambil jawaban pengguna
            jawabanPengguna = char_tanpa_buffer();

            // Validasi input
            int valid = 0;
            for (int j = 0; j < sizeof(opsi) / sizeof(opsi[0]); j++) {
                if (jawabanPengguna == opsi[j]) {
                    valid = 1;
                    break;
                }
            }

            // Jika input tidak valid, ulangi
            if (!valid) {
                printf("\nInput tidak valid. Coba lagi: ");
                continue;
            }

            // Cek jawaban pengguna
            if (jawabanPengguna == kumpulanSoal[idx[i]].jawaban) {
                uang += 1000;
                printf("\nJawaban benar! Tekan 'n' untuk lanjut...\n");

                // Tunggu hingga pengguna menekan 'n'
                char lanjut;
                do {
                    lanjut = char_tanpa_buffer();
                } while (lanjut != 'n');

                break; // Lanjut ke soal berikutnya
            } else {
                // Jawaban salah, permainan berakhir
                printf("\nJawaban salah! Permainan berakhir.\n");
                printf("Skor akhir: %d\n", uang);
                free(idx);
                return 0;
            }
        }

    }
    clear_terminal();
    printf("Selamat! Anda berhasil menjawab semua soal dengan benar!\n");
    printf("Skor akhir: %d\n", uang);
    printf("===================================================\n");
    free(idx);

    return 0;

}
