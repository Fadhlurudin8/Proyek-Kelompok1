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
            printf("A. Merkurius\n");
            printf("B. Mars\n");
            printf("C. Venus\n");
            printf("D. Bumi\n");
            break;
        case 6:
            printf("Pertanyaan 6: Ibukota Negara Indonesia?\n");
            printf("A. Banten\n");
            printf("B. Jakarta\n");
            printf("C. Medan\n");
            printf("D. Surabaya\n");
            break;
        case 7:
            printf("Pertanyaan 7: 100 x 3 / 2 = ?\n");
            printf("A. 160\n");
            printf("B. 150\n");
            printf("C. 120\n");
            printf("D. 130\n");
            break;
        case 8:
            printf("Pertanyaan 8: Planet terbesar di tata surya?\n");
            printf("A. Merkurius\n");
            printf("B. Pluto\n");
            printf("C. Saturnus\n");
            printf("D. Jupiter\n");
            break;
        case 9:
            printf("Pertanyaan 9: Apa hewan tercepat di dunia?\n");
            printf("A. Harimau\n");
            printf("B. Macan\n");
            printf("C. Kangguru\n");
            printf("D. Cheetah\n");
            break;
        case 10:
            printf("Pertanyaan 10: Lambang kimia untuk air?\n");
            printf("A. NaCl\n");
            printf("B. NaOH\n");
            printf("C. H2O\n");
            printf("D. O2\n");
            break;
        case 11:
            printf("Pertanyaan 11: 5 x 2 + 10 / 2 = ?\n");
            printf("A. 16\n");
            printf("B. 15\n");
            printf("C. 17\n");
            printf("D. 12\n");
            break;
        case 12:
            printf("Pertanyaan 12: Apa gunung tertinggi di dunia?\n");
            printf("A. Bromo\n");
            printf("B. Everest\n");
            printf("C. Kangchenjunga\n");
            printf("D. Lhotse\n");
            break;
        case 13:
            printf("Pertanyaan 13: Apa danau terbesar di dunia?\n");
            printf("A. Superior\n");
            printf("B. Huron\n");
            printf("C. Kaspia\n");
            printf("D. Sentani\n");
            break;
        case 14:
            printf("Pertanyaan 14: Siapa nama Presiden ke-4 Republik Indonesia?\n");
            printf("A. Megawati Soekarnoputri\n");
            printf("B. Mohammad Hatta\n");
            printf("C. B.J. Habibie\n");
            printf("D. Gus Dur\n");
            break;
        case 15:
            printf("Pertanyaan 15: Apa nama ibu kota negara Australia?\n");
            printf("A. Sydney\n");
            printf("B. Melbourne\n");
            printf("C. Canberra\n");
            printf("D. Perth\n");
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
            return (jawaban == 'A' || jawaban == 'a');
        case 6:
            return (jawaban == 'B' || jawaban == 'b');
        case 7:
            return (jawaban == 'B' || jawaban == 'b');
        case 8:
            return (jawaban == 'D' || jawaban == 'd');
        case 9:
            return (jawaban == 'D' || jawaban == 'd');
        case 10:
            return (jawaban == 'C' || jawaban == 'c');
        case 11:
            return (jawaban == 'B' || jawaban == 'b');
        case 12:
            return (jawaban == 'B' || jawaban == 'b');
        case 13:
            return (jawaban == 'C' || jawaban == 'c');
        case 14:
            return (jawaban == 'D' || jawaban == 'd');
        case 15:
            return (jawaban == 'C' || jawaban == 'c');
        default:
            return 0;
    }
}

int main() {
    int skor = 0;
    char jawaban;

    printf("Selamat datang di permainan 'Who wants to be a Millionaire Game'!\n\n");

    for (int i = 1; i <= 15; i++) {
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
                case 5: printf("A\n\n"); break;
                case 6: printf("B\n\n"); break;
                case 7: printf("B\n\n"); break;
                case 8: printf("D\n\n"); break;
                case 9: printf("D\n\n"); break;
                case 10: printf("C\n\n"); break;
                case 11: printf("B\n\n"); break;
                case 12: printf("B\n\n"); break;
                case 13: printf("C\n\n"); break;
                case 14: printf("D\n\n"); break;
                case 15: printf("C\n\n"); break;
                
            }
            printf("Permainan selesai! Anda mendapatkan uang: Rp %d juta\n", skor / 1000000);
            return 0;
        }
    }

    printf("Permainan selesai! Anda mendapatkan uang: Rp %d juta\n", skor / 1000000);
    return 0;
}
