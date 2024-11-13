#include <stdio.h>
#include#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *input_str(const char identitas[], int batas_panjang_input)
{
    // Mengalokasikan memori untuk mengembalikan inputan
    char *input = malloc(batas_panjang_input + 1);
    if (input == NULL) {
        printf("ERROR! \nGagal mengalokasikan memori\n");
        exit(EXIT_FAILURE);
    }

    // Input dari user
    printf("%s: ", identitas); scanf(" %[^\n]", input);

    // Memastikan tidak ada spasi dalam input
    if (strchr(input, ' ') != NULL){
        printf("SIGN UP FAILED! \n%s harus dalam satu kata\n", identitas);
        exit(EXIT_FAILURE);
    }

    // Memastikan input tidak melebihi batas panjang
    if (strlen(input) > batas_panjang_input) {
        printf("SIGN UP FAILED: %s tidak boleh lebih dari %d karakter\n", identitas, batas_panjang_input);
        free(input);
        exit(EXIT_FAILURE);
    }

    return input;
}


FILE *buka_file(char *nama_file, char *mode_file)
{
    FILE *file;
    if ((file = fopen(nama_file, mode_file)) == NULL){
            printf("ERROR: Gagal membuka file!\n");
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

        printf("SUCCESS: Akun terverifikasi.\n");

        return EXIT_SUCCESS;
    }

    else if (argc == 3)
    {   
        FILE *flogin = buka_file("database/login.bin", "rb");

        akun akunku;
        fread(&akunku, sizeof(akunku), 1, flogin);

        if (strcmp(argv[0], akunku.username) == 1 || strcmp(argv[1], akunku.password) == 1)
        {   
            printf("SIGN IN FAILED: Username/password anda salah \nBaca selengkapnya di README.md\n"); 
            return EXIT_FAILURE;
        }
        else
        {
            clear();
            printf("\t===== PROYEK PRAKTIKUM PEMROGRAMAN KELOMPOK 1 =====\n");
            // inti permainan disini
        }
    }
        
    else{
        printf("ERROR!\n Format login: ./main username password \n Baca selengkapnya di README.md"); // 
    }

    return 0;
}
}
