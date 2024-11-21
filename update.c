#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk tampilan warna (jika terminal mendukung ANSI escape codes)
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

// Username dan password untuk login
#define USERNAME "admin"
#define PASSWORD "1234"

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

void tampilkanSkorPeserta(char peserta[], int skor) {
    printf("\n" YELLOW "=================== HASIL AKHIR ===================\n" RESET);
    printf(YELLOW "| %-20s | %-10s |\n" RESET, "Nama Peserta", "Skor");
    printf(YELLOW "==================================================\n" RESET);
    printf("| %-20s | Rp %-8d |\n", peserta, skor);
    printf(YELLOW "==================================================\n" RESET);
}

void tampilkanPemenang(char peserta[], int skor) {
    printf(GREEN "\n🎉🎊 Pemenangnya adalah: %s 🎊🎉\n" RESET, peserta);
    printf(CYAN "Dengan skor fantastis sebesar Rp %d juta!\n" RESET, skor / 1000000);
    printf(GREEN "===============================================\n" RESET);
    printf(RED "🏆 Selamat kepada sang juara! 🏆\n" RESET);
    printf(GREEN "===============================================\n" RESET);
}

int login() {
    char inputUsername[50];
    char inputPassword[50];

    printf("Masukkan Username: ");
    scanf("%s", inputUsername);
    printf("Masukkan Password: ");
    scanf("%s", inputPassword);

    if (strcmp(inputUsername, USERNAME) == 0 && strcmp(inputPassword, PASSWORD) == 0) {
        printf(GREEN "\nLogin berhasil! Selamat bermain.\n" RESET);
        return 1; // Login sukses
    } else {
        printf(RED "\nLogin gagal! Username atau password salah.\n" RESET);
        return 0; // Login gagal
    }
}

int main() {
    printf("Selamat datang di permainan '" CYAN "Siapa yang Ingin Menjadi Jutawan" RESET "'!\n\n");

    // Proses login
    if (!login()) {
        return 1; // Keluar jika login gagal
    }

    char peserta[50];
    int skor = 0;

    printf("\nMasukkan nama Anda: ");
    scanf(" %[^\n]s", peserta);

    // Mulai permainan dengan 5 pertanyaan
    for (int j = 1; j <= 5; j++) {
        char jawaban;
        tampilkanPertanyaan(j);
        printf("Masukkan jawaban Anda (A/B/C/D): ");
        scanf(" %c", &jawaban);

        if (cekJawaban(j, jawaban)) {
            printf(GREEN "Jawaban Anda benar!\n\n" RESET);
            skor += 1000000;
        } else {
            printf(RED "Jawaban Anda salah. Jawaban yang benar adalah: " RESET);
            switch (j) {
                case 1: printf("B\n\n"); break;
                case 2: printf("C\n\n"); break; 
                case 3: printf("B\n\n"); break; 
                case 4: printf("C\n\n"); break; 
                case 5: printf("C\n\n"); break;
            }
            break; // Permainan berhenti jika jawaban salah
        }
    }

    // Tampilkan skor akhir
    tampilkanSkorPeserta(peserta, skor);

    // Tampilkan pemenang
    tampilkanPemenang(peserta, skor);

    return 0;
}
