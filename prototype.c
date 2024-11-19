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
    input[strcspn(input, "\n")] = 0;

    // Memastikan input tidak kosong
    if (strlen(input) == 0) {
        clear_terminal();
        printf("\n  ======================================\n");
        printf("  | ERROR: %s tidak boleh kosong |\n", identitas);
        printf("  ======================================\n\n");
        free(input);
        exit(1);
    }

    // Memastikan tidak ada spasi dalam input
    if (strchr(input, ' ') != NULL){
        clear_terminal();
        printf("\n  ==================================================\n");
        printf("  | SIGN UP FAILED: %s harus dalam satu kata |   \n", identitas);
        printf("  ==================================================\n\n");
        free(input);
        exit(1);
    }

    // Memastikan input tidak melebihi batas panjang
    if (strlen(input) > batas_panjang_input) {
        clear_terminal();
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
            printf("\n  ==============================\n");
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
        printf("\n  === PROYEK PRAKTIKUM PEMROGRAMAN KELOMPOK 1 ===\n\n\n\n");
        printf("                     |SIGN UP|                 \n\n");
        printf("  ===============================================\n");
        printf("  *                  Petunjuk:                  *\n");
        printf("  * Username dan password harus dalam satu kata *\n");
        printf("  * (tanpa   spasi).   Username   maksimal   20 *\n");
        printf("  * karakter dan password maksimal 10 karakter. *\n");
        printf("  ===============================================\n\n");
        
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
        printf("\n  === PROYEK PRAKTIKUM PEMROGRAMAN KELOMPOK 1 ===\n\n\n\n");
        printf("  =======================================\n");
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
            printf("\n  SIGN IN FAILED: Username/password anda salah\n  Baca selengkapnya di README.md\n\n"); 
            fclose(flogin);
            return 1;
        }
        
        else
        {
            char PlayerChoice;
            // Menampilkan opsi sampai user memilih opsi keluar
            clear_terminal();
            printf("\n  === PROYEK PRAKTIKUM PEMROGRAMAN KELOMPOK 1 ===\n\n\n\n");
            printf ("          WHO WANTS TO BE A\n");
            printf ("             MILLIONAIRE\n\n");
            
            // Opsi
            printf ("  =================================\n");
            printf ("  *          1. Mulai             *\n");
            printf ("  *          2. Peraturan         *\n");
            printf ("  *          3. Keluar            *\n");
            printf ("  =================================\n ");
            do 
            {    
                PlayerChoice = char_tanpa_buffer();
                // User memilih opsi mulai
                if (PlayerChoice == '1'){
                    clear_terminal();
                    break; // ganti dengan isi game
                }

                // User memilih opsi peraturan
                else if (PlayerChoice == '2'){
                    // Menampilkan aturan sampai user memilih kembali
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
                    printf ("                                    Kembali(y)\n");
                    do{
                        PlayerChoice = char_tanpa_buffer();
                        if (PlayerChoice == 'y')
                        {
                            clear_terminal();
                            printf("\n  === PROYEK PRAKTIKUM PEMROGRAMAN KELOMPOK 1 ===\n\n\n\n");
                            printf ("          WHO WANTS TO BE A\n");
                            printf ("             MILLIONAIRE\n\n");
                            
                            // Opsi
                            printf ("  =================================\n");
                            printf ("  *          1. Mulai             *\n");
                            printf ("  *          2. Peraturan         *\n");
                            printf ("  *          3. Keluar            *\n");
                            printf ("  =================================\n ");
                        }
                    } while(PlayerChoice != 'y');          
                }

                // User menekan selain 1, 2, dan 3
                else
                    continue;

            } while(PlayerChoice != '3'); 
            
            fclose(flogin);
            clear_terminal();
            printf("\n  ==================================\n");
            printf("  * Senang bermain dengan Anda ^_^ *\n");
            printf("  ==================================\n\n");
        }
    }

    // Argumen yang diberikan bukan sebanyak 1 atau 3    
    else
    {
        clear_terminal();
        printf("\n  ERROR:\n  Format login: ./<Nama Program> <Username> <Password>\n  Baca selengkapnya di README.md\n\n"); // 
    }

    return 0;
}
