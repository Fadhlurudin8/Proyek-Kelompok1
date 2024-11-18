#include <stdio.h>
#include <stdlib.h>

void tampilkanPertanyaan(int nomor) {
    switch (nomor) {
        case 1:
            printf("Pertanyaan 1: Siapa penemu bola lampu?\n");
            printf("A. Alexander Graham Bell\n");
            printf("B. Thomas Edison\n");
            printf("C. Nikola Tesla\n");
            printf("D. Albert Einstein\n");
            break;
        case 2:
            printf("Pertanyaan 2: Apa ibu kota Prancis?\n");
            printf("A. Berlin\n");
            printf("B. Madrid\n");
            printf("C. Paris\n");
            printf("D. Roma\n");
            break;
        case 3:
            printf("Pertanyaan 3: Apa rumus fisika untuk energi kinetik?\n");
            printf("A. E = mc^2\n");
            printf("B. E_k = 1/2 mv^2\n");
            printf("C. F = ma\n");
            printf("D. P = IV\n");
            break;
        case 4:
            printf("Pertanyaan 4: Siapa penulis 'Romeo dan Juliet'?\n");
            printf("A. Charles Dickens\n");
            printf("B. Mark Twain\n");
            printf("C. William Shakespeare\n");
            printf("D. Jane Austen\n");
            break;
        case 5:
            printf("Pertanyaan 5: Apa planet terdekat dengan matahari?\n");
            printf("A. Venus\n");
            printf("B. Mars\n");
            printf("C. Merkurius\n");
            printf("D. Bumi\n");
            break;
        default:
            printf("Pertanyaan tidak ditemukan.\n");
            break;
    }
}

int cekJawaban(int nomor, char jawaban) {
    switch (nomor) {
        case 1:
            return (jawaban == 'B' || jawaban == 'b'); 
        case 2:
            return (jawaban == 'C' || jawaban == 'c'); 
        case 3:
            return (jawaban == 'B' || jawaban == 'b'); 
        case 4:
            return (jawaban == 'C' || jawaban == 'c'); 
        case 5:
            return (jawaban == 'C' || jawaban == 'c');
        default:
            return 0;
    }
}

int main() {
    int skor = 0;
    char jawaban;

    printf("Selamat datang di permainan 'Siapa yang Ingin Menjadi Jutawan'!\n\n");

    for (int i = 1; i <= 5; i++) {
        tampilkanPertanyaan(i);
        printf("Masukkan jawaban Anda (A/B/C/D): ");
        scanf(" %c", &jawaban);

        if (cekJawaban(i, jawaban)) {
            printf("Jawaban Anda benar!\n\n");
            skor += 1000000;
        } else {
            printf("Jawaban Anda salah. Jawaban yang benar adalah: ");
            switch (i) {
                case 1: printf("B\n\n"); break;
                case 2: printf("C\n\n"); break; 
                case 3: printf("B\n\n"); break; 
                case 4: printf("C\n\n"); break; 
                case 5: printf("C\n\n"); break;
            }
            printf("Permainan selesai! Anda mendapatkan uang: Rp %d juta\n", skor / 1000000);
            return 0;
        }
    }

    printf("Permainan selesai! Anda mendapatkan uang: Rp %d juta\n", skor / 1000000);
    return 0;
}
