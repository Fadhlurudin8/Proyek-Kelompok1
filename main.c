#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *input_str(const char identitas[], int batas_panjang_input)
{
    // Mengalokasikan memori untuk mengembalikan inputan
    char *input = malloc(batas_panjang_input + 1);
    if (input == NULL) {
        printf("ERROR! \nGagal mengalokasikan memori\n");
        exit(EXIT_FAILURE);//
    }

    // Input dari user
    printf("%s: ", identitas); fgets(input, batas_panjang_input + 2, stdin);
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Memastikan input tidak kosong setelah newline dihapus
    if (strlen(input) == 0) {
        printf("ERROR! \n%s tidak boleh kosong\n", identitas);
        free(input);
        exit(EXIT_FAILURE);
    }

    // Memastikan tidak ada spasi dalam input
    if (strchr(input, ' ') != NULL){
        printf("SIGN UP FAILED! \n%s harus dalam satu kata\n", identitas);
        exit(EXIT_FAILURE);
    }

    // Memastikan input tidak melebihi batas panjang
    if (strlen(input) > batas_panjang_input) {
        printf("SIGN UP FAILED! \n%s tidak boleh lebih dari %d karakter\n", identitas, batas_panjang_input);
        free(input);
        exit(EXIT_FAILURE);
    }

    return input;
}


FILE *buka_file(char *nama_file, char *mode_file)
{
    FILE *file;
    if ((file = fopen(nama_file, mode_file)) == NULL){
            printf("ERROR! \nGagal membuka file!\n");
            exit(EXIT_FAILURE);
        }
    return file;
}

void clear()
    {printf("\e[1;1H\e[2J");} // perintah untuk membersihkan terminal

typedef struct
{
    char username[21];
    char password[11];
} akun;

int main(int argc, char *argv[])
{
    if (argc == 1){
        clear();
        printf("\t===== PROYEK PRAKTIKUM PEMROGRAMAN KELOMPOK 1 =====\n");
        printf("SIGN UP\n");
        printf("Petunjuk: Username (max 20 karakter), password (max 10 karakter)\n\n");
        
        FILE *flogin = buka_file("database/login.bin", "wb");

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

        printf("SUCCESS! \nAkun terverifikasi\n");

        return EXIT_SUCCESS;
    }

    else if (argc == 3)
    {   
        FILE *flogin = buka_file("database/login.bin", "rb");

        akun akunku;
        fread(&akunku, sizeof(akunku), 1, flogin);

        if (strcmp(argv[1], akunku.username) != 0 || strcmp(argv[2], akunku.password) != 0)
        {   
            printf("SIGN IN FAILED! \nUsername/password anda salah \nBaca selengkapnya di README.md\n"); 
            return EXIT_FAILURE;
        }
        else
        {
            clear();
            printf("\t===== PROYEK PRAKTIKUM PEMROGRAMAN KELOMPOK 1 =====\n");

            int GoBack;
                do {
                printf ("\n \t\t WHO WANTS TO BE A\n");
                printf (" \t\t    MILLIONAIRE\n\n");

                printf (" \t=================================\n");
                printf (" \t*\t  1. Mulai \t\t*\n");
                printf (" \t*\t  2. Peraturan \t\t*\n");
                printf (" \t*\t  3. Keluar \t\t*\n");
                printf (" \t=================================");

                int PlayerChoice;
                printf ("\n\t>> ");
                scanf ("%d", &PlayerChoice);

                    if (PlayerChoice == 1){
                        // isi game
                    }

                    else if (PlayerChoice == 2){
                        printf ("\n\n==================================================\n\n");
                        printf ("\t      |Peraturan Permainan|\n");
                        printf ("   ============================================\n");
                        printf ("   * 1. Pemain harus menjawab 10 pertanyaan   *\n");
                        printf ("   *    pilihan ganda secara berurutan dengan *\n");
                        printf ("   *    benar.                                *\n");
                        printf ("   * 2. Pemain diberikan x detik untuk        *\n");
                        printf ("   *    menjawab setiap soal.                 *\n");
                        printf ("   * 3. Jika pemain menjawab salah, permainan *\n");
                        printf ("   *    berakhir                              *\n");
                        printf ("   ============================================\n");
                        printf ("                                   Kembali >> ");
                        scanf ("%d", &GoBack);

                    }

                    else if (PlayerChoice == 3){
                        exit (0);
                    }

                    else {
                        // kode tidak valid
                    }
                }
                while (GoBack == 0);
    }
        
    else{
        printf("ERROR! \nFormat login: ./main username password \nBaca selengkapnya di README.md\n"); // 
    }

    return 0;
}
