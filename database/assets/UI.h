#include <stdio.h>

// Fungsi untuk tampilan warna (jika terminal mendukung ANSI escape codes)
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

void kepalaProgram()
{
    printf("\n=== PROYEK PRAKTIKUM PEMROGRAMAN KELOMPOK 1 ===\n\n\n\n");
}

void menuUtama()
{
    printf("        WHO WANTS TO BE A        \n");
    printf("           MILLIONAIRE           \n");
    printf("                                 \n");
    printf("=================================\n");
    printf("*          1. Mulai             *\n");
    printf("*          2. Peraturan         *\n");
    printf("*          3. Keluar            *\n");
    printf("=================================\n");
    printf(">> ");
}

void peraturan()
{
    printf("================================================\n");
    printf("|                                              |\n");
    printf("|             |Peraturan Permainan|            |\n");
    printf("| ============================================ |\n");
    printf("| * 1. Pemain harus menjawab 10 pertanyaan   * |\n");
    printf("| *    pilihan ganda secara berurutan dengan * |\n");
    printf("| *    benar dengan 3 tingkat kesulitan yang * |\n");
    printf("| *    dapat dipilih                         * |\n");
    printf("| * 2. Jika pemain salah menjawab soal,      * |\n");
    printf("| *    permainan berakhir.                   * |\n");
    printf("| * 3. Skor akhir akan ditampilkan setelah   * |\n");
    printf("| *    permainan berakhir                    * |\n");
    printf(" ==============================================\n");
    printf("                                     Kembali(y)\n");
    printf(">> ");
}

void tampilSkor(int skor) {
    printf("\n"YELLOW "======== HASIL AKHIR ========\n" RESET);
    printf(YELLOW "|         Skor: %d          |\n" RESET, skor);
    printf(YELLOW "=============================\n" RESET);
}
