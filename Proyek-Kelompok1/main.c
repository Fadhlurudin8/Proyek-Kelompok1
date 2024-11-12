#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *input_str(const char string[], int batas_panjang_input)
{
    char *input = malloc(batas_panjang_input + 1);
    if (input == NULL) {
        printf("Gagal mengalokasikan memori\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", string);
    if (fgets(input, batas_panjang_input + 1, stdin) == NULL) {
        free(input);
        return NULL;
    }

    // Hapus karakter newline jika ada
    input[strcspn(input, "\n")] = '\0';

    // Memastikan input tidak melebihi batas panjang
    if (strlen(input) > batas_panjang_input) {
        printf("Tidak boleh lebih dari %d karakter\n", batas_panjang_input);
        free(input);
        exit(EXIT_FAILURE);
    }

    return input;
}

typedef struct
{
    char username[21];
    char password[11];
} akun;

int main()
{
    printf("\e[1;1H\e[2J");
    FILE *flogin;

    if ((flogin = fopen("database/login.bin", "wb")) == NULL){
        printf("Gagal membuka file!\n");
        return EXIT_FAILURE;
    }

    printf("\nRegistrasi\n");
    printf("Petunjuk: username (max 20 karakter) dan password (max 10 karakter)\n");

    // Ambil input dari pengguna
    char *username = input_str("Username: ", 20);
    char *password = input_str("Password: ", 10);

    // Membuat struct akun dan mengisi username dan password
    akun akunku;
    strncpy(akunku.username, username, sizeof(akunku.username) - 1);
    akunku.username[sizeof(akunku.username) - 1] = '\0'; // Pastikan null-terminated
    strncpy(akunku.password, password, sizeof(akunku.password) - 1);
    akunku.password[sizeof(akunku.password) - 1] = '\0'; // Pastikan null-terminated

    // Tulis struct akun ke file biner
    fwrite(&akunku, sizeof(akunku), 1, flogin);

    // Bersihkan memori yang dialokasikan
    free(username);
    free(password);

    fclose(flogin);

    printf("Akun terverifikasi.\n");

    return 0;
}
