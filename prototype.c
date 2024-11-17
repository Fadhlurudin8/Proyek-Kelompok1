#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "database/assets/cross-platform.h"

// Fungsi untuk membersihkan terminal
void clear_terminal()
    {printf("\e[1;1H\e[2J");} 

/* Fungsi untuk menginput identitas
   Contoh penggunaan: input_str("Nama", 50);
   Contoh di atas akan meminta user untuk menginput nama dengan panjang maksimal 50 */
char *input_str(const char identitas[], int batas_panjang_input)
{
    // Mengalokasikan memori untuk mengembalikan inputan
    char *input = malloc(batas_panjang_input + 1);
    if (input == NULL) {
        printf("\n  ======================================\n");
        printf("  | ERROR: Gagal mengalokasikan memori |\n");
        printf("  ======================================\n\n");
        exit(1);
    }

    // Input dari user
    printf("  %s: ", identitas); fgets(input, batas_panjang_input + 2, stdin);
    size_t len = strlen(input);
    
    // Menghilangkan '\n' dari inputan fgets()
    if (len > 0 && input[len - 1] == '\n')
        input[len - 1] = '\0';

    // Memastikan input tidak kosong
    if (strlen(input) == 0) {
        clear_terminal();
        printf("\n=== PROYEK PRAKTIKUM PEMROGRAMAN KELOMPOK 1 ===\n\n\n");
        printf("\n  ======================================\n");
        printf("  | ERROR: %s tidak boleh kosong |\n", identitas);
        printf("  ======================================\n\n");
        free(input);
        exit(1);
    }

    // Memastikan tidak ada spasi dalam input
    if (strchr(input, ' ') != NULL){
        clear_terminal();
        printf("\n=== PROYEK PRAKTIKUM PEMROGRAMAN KELOMPOK 1 ===\n\n\n");
        printf("\n  ==================================================\n");
        printf("  | SIGN UP FAILED: %s harus dalam satu kata |   \n", identitas);
        printf("  ==================================================\n\n");
        free(input);
        exit(1);
    }

    // Memastikan input tidak melebihi batas panjang
    if (strlen(input) > batas_panjang_input) {
        clear_terminal();
        printf(" \n=== PROYEK PRAKTIKUM PEMROGRAMAN KELOMPOK 1 ===\n\n\n");
        printf("\n  ==============================================\n");
        printf("  | SIGN UP FAILED: %s tidak boleh lebih |\n", identitas);
        printf("  |                 dari %d karakter           |\n", batas_panjang_input);
        printf("  ==============================================\n\n");
        free(input);
        exit(1);
    }

    return input;
}

// Fungsi untuk mengakses file dan menentukan mode eksekusi
FILE *buka_file(char *nama_file, char *mode_file)
{
    FILE *file;
    // File gagal diakses
    if ((file = fopen(nama_file, mode_file)) == NULL){
            printf("  ==============================\n");
            printf("  | ERROR: Gagal membuka file! |\n");
            printf("  ==============================\n\n");
            exit(1);
        }

    return file;
}

// Mendefinisikan sebuah struct untuk menyimpan akun permainan
typedef struct
{
    char username[21];
    char password[11];
} akun;

int main(int argc, char *argv[])
{
    // Pembuatan akun
    if (argc == 1){
        clear_terminal();
        printf("\n=== PROYEK PRAKTIKUM PEMROGRAMAN KELOMPOK 1 ===\n\n\n");
        printf("\n                   |SIGN UP|                 \n\n");
        printf("  ===========================================\n");
        printf("  *     *Petunjuk:                          *\n");
        printf("  *      Username maksimal 20 karakter      *\n");
        printf("  *      Password maksimal 10 karakter      *\n");
        printf("  ===========================================\n\n");
        
        FILE *flogin = buka_file("database/login.bin", "wb"); // mengakses file biner dalam mode tulis

        // Ambil input dari pengguna
        char *username = input_str("Username", 20);
        char *password = input_str("Password", 10);

        // Membuat struct akun dan mengisi username dan password
        akun akunku;
        strcpy(akunku.username, username);
        strcpy(akunku.password, password);

        // Tulis struct akun ke file biner
        fwrite(&akunku, sizeof(akunku), 1, flogin);

        // Bersihkan memori yang dialokasikan
        free(username); free(password);

        fclose(flogin);

        // Akun berhasil dibuat
        clear_terminal();
        printf("\n=== PROYEK PRAKTIKUM PEMROGRAMAN KELOMPOK 1 ===\n\n\n");
        printf("\n  =======================================\n");
        printf("  | SIGN UP SUCCESS: Akun terverifikasi |\n");
        printf("  =======================================\n\n");

        return 0;
    }

    // Sign in
    else if (argc == 3)
    {   
        FILE *flogin = buka_file("database/login.bin", "rb"); // mengakses file biner dalam mode baca

        // Membuat struct akun untuk menampung struct di file biner
        akun akunku;
        fread(&akunku, sizeof(akunku), 1, flogin);

        // Salah username/password
        if (strcmp(argv[1], akunku.username) != 0 || strcmp(argv[2], akunku.password) != 0)
        {   
            clear_terminal();
            printf("\nSIGN IN FAILED: Username/password anda salah \nBaca selengkapnya di README.md\n\n"); 
            return 1;
        }
        
        else
        {
            while (1) 
            {
                clear_terminal();
                #ifdef  __linux__ || __unix__ || __APPLE__
                initscr();
                #endif
                printf("\n=== PROYEK PRAKTIKUM PEMROGRAMAN KELOMPOK 1 ===\n\n\n");
                printf ("\n \t WHO WANTS TO BE A\n");
                printf (" \t    MILLIONAIRE\n\n");
                
                // Fitur
                printf ("  =================================\n");
                printf ("  *          1. Mulai             *\n");
                printf ("  *          2. Peraturan         *\n");
                printf ("  *          3. Keluar            *\n");
                printf ("  =================================\n ");
                fflush(stdout);
                
                char PlayerChoice = char_tanpa_buffer();
                // User menekan 1
                if (PlayerChoice == '1'){
                    break; // ganti dengan isi game
                }

                // User menekan 2
                else if (PlayerChoice == '2'){
                    // Menampilkan aturan sampai user menekan y
                    do{
                        clear_terminal();
                        printf ("\n\n================================================\n\n");
                        printf ("             |Peraturan Permainan|\n");
                        printf ("  ============================================\n");
                        printf ("  * 1. Pemain harus menjawab 10 pertanyaan   *\n");
                        printf ("  *    pilihan ganda secara berurutan dengan *\n");
                        printf ("  *    benar.                                *\n");
                        printf ("  * 2. Pemain diberikan x detik untuk        *\n");
                        printf ("  *    menjawab setiap soal.                 *\n");
                        printf ("  * 3. Jika pemain menjawab salah, permainan *\n");
                        printf ("  *    berakhir                              *\n");
                        printf ("  ============================================\n");
                        printf ("                                    Kembali(y)");
                        PlayerChoice = char_tanpa_buffer();
                    } while(PlayerChoice != 'y');
                }

                // User menekan 3
                else if (PlayerChoice == '3'){
                    clear_terminal();
                    break;
                }

                // User menekan selain 1, 2, dan 3
                else {
                    continue;
                }
            }
        }
    }

    // Argumen yang diberikan bukan 1 dan 3    
    else
    {
        clear_terminal();
        printf("\nERROR: \nFormat login: ./<Nama Program> <Username> <Password> \nBaca selengkapnya di README.md\n\n"); // 
    }

    return 0;
}
