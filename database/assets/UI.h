#include <stdio.h>

// Fungsi untuk tampilan warna (jika terminal mendukung ANSI escape codes)
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

void kepalaProgram()
{
    printf("\n=== PROYEK PRAKTIKUM PEMROGRAMAN KELOMPOK 1 ===\n\n\n\n");
}

void petunjukSignup()
{
    printf("                   |SIGN UP|                 \n\n");
    printf("===============================================\n");
    printf("*                  Petunjuk:                  *\n");
    printf("* Username dan password harus dalam satu kata *\n");
    printf("* (tanpa   spasi).   Username   maksimal   20 *\n");
    printf("* karakter dan password maksimal 10 karakter. *\n");
    printf("===============================================\n");
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
    printf("|              Peraturan Permainan             |\n");
    printf("| ============================================ |\n");
    printf("| * 1. Pemain harus menjawab 10 pertanyaan   * |\n");
    printf("| *    pilihan ganda secara berurutan dengan * |\n");
    printf("| *    benar dengan 3 tingkat kesulitan yang * |\n");
    printf("| *    dapat dipilih                         * |\n");
    printf("| * 2. Jika pemain salah menjawab soal,      * |\n");
    printf("| *    permainan berakhir.                   * |\n");
    printf("| * 3. Skor akhir akan ditampilkan setelah   * |\n");
    printf("| *    permainan berakhir                    * |\n");
    printf("================================================\n");
    printf("                                   Menu Utama(y)\n");
    printf(">> ");
}

void tingkatKesulitan()
{
    printf("Pilih kesulitan soal:\n");
    printf("=====================\n");
    printf("*     "GREEN"1. Mudah"RESET"      *\n");
    printf("*     "YELLOW"2. Sedang"RESET"     *\n");
    printf("*     "RED"3. Susah"RESET"      *\n");
    printf("=====================\n");
    printf("        Menu Utama(y)\n");
    printf(">> ");
}

void tampilSkor(int skor) {
    printf(YELLOW "\n======== HASIL AKHIR ========\n"RESET);
    printf(YELLOW   "|         Skor: %-2d          |\n" RESET, skor);
    printf(YELLOW   "=============================\n" RESET);
    printf(         "                Menu Utama(y)\n");
    printf(         ">> ");
}
