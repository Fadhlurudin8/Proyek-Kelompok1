#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "database/assets/cross-platform.h"
#include "database/assets/soal.h"
#include "database/assets/UI.h"

// prototipe fungsi
void clearTerminal();
char *ptrInputString(const char identitas[], int batasPanjangInput);
FILE *bukaFile(char *namaFile, char *modeFile);
int *ptrElemenAcak(int jumlahElemen);

// Struct untuk menyimpan akun
typedef struct
{
    char username[21];
    char password[11];
} akun;

int main(int argc, char *argv[])
{
    // Sign up
    if (argc == 1){
        clearTerminal();
        kepalaProgram();
        petunjukSignup();
        printf("\n");
        
        FILE *flogin = bukaFile("database/login.bin", "wb"); // mengakses file biner dalam mode tulis

        // Ambil input dari pengguna
        char *username = ptrInputString("Username", 20);
        char *password = ptrInputString("Password", 10);

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
        clearTerminal();
        printf("=======================================\n");
        printf("| "GREEN"SIGN UP SUCCESS:"RESET" Akun terverifikasi |\n");
        printf("=======================================\n\n");

        return 0;
    }

    // Sign in
    else if (argc == 3)
    {   
        FILE *flogin = bukaFile("database/login.bin", "rb"); // mengakses file biner dalam mode baca

        // Membuat struct akun untuk menampung struct di file biner
        akun akunku;
        fread(&akunku, sizeof(akunku), 1, flogin);

        // Salah username/password
        if (strcmp(argv[1], akunku.username) != 0 || strcmp(argv[2], akunku.password) != 0)
        {   
            clearTerminal();
            printf(RED"\nSIGN IN FAILED:"RESET" Username/password anda salah \nBaca selengkapnya di README.md\n\n"); 
            fclose(flogin);
            return 1;
        }
        
        else
        {
            char PlayerChoice;
            // Menampilkan opsi sampai user memilih opsi keluar
            clearTerminal();
            kepalaProgram();
            menuUtama();
            do 
            {    
                PlayerChoice = charTanpaBuffer();
                // User memilih opsi mulai
                if (PlayerChoice == '1'){
                    clearTerminal();
                    int soalBenar = 0;
                    int skor = 0;
                    int maxSoal = 10;
                    int nomorSoal;
                    const char opsi[] = {'a', 'b', 'c', 'd'};
                    char jawabanPengguna;
                    short int validasiInput;
                    Soal *kumpulanSoal = NULL;

                    // Pilih tingkat kesulitan
                    clearTerminal();
                    tingkatKesulitan();
                    char pilih;

                    do{
                        pilih = charTanpaBuffer(); 
                        switch (pilih) 
                        {
                            case '1':
                                kumpulanSoal = mudah;
                                maxSoal = sizeof(mudah) / sizeof(mudah[0]);
                                break;
                            case '2':
                                kumpulanSoal = sedang;
                                maxSoal = sizeof(sedang) / sizeof(sedang[0]);
                                break;
                            case '3':
                                kumpulanSoal = susah;
                                maxSoal = sizeof(susah) / sizeof(susah[0]);
                                break;
                            default:
                                continue;
                        }
                        break;
                    } while(pilih != 'y' && pilih != 'Y');

                    if (pilih == 'y' || pilih =='Y')
                    {
                        clearTerminal();
                        kepalaProgram();
                        menuUtama();
                        continue;
                    }

                    // Acak soal
                    int *ptrUrutanSoal = ptrElemenAcak(maxSoal);

                    // Main loop
                    for (nomorSoal = 1; nomorSoal <= maxSoal; nomorSoal++) {
                        clearTerminal();
                        printf("===================================================\n");
                        printf("Soal %d:\n%s\n", nomorSoal, kumpulanSoal[ptrUrutanSoal[nomorSoal - 1]].soal);
                        printf(">> ");

                        // Input jawaban pengguna
                        while (1) {
                            jawabanPengguna = charTanpaBuffer();

                            // Validasi input
                            validasiInput = 0;
                            for (int j = 0; j < sizeof(opsi) / sizeof(opsi[0]); j++) {
                                if (jawabanPengguna == opsi[j]) {
                                    validasiInput = 1;
                                    break;
                                }
                            }

                            // Jika input tidak valid, ulangi
                            if (!validasiInput) continue;

                            // Cek jawaban pengguna
                            if (jawabanPengguna == kumpulanSoal[ptrUrutanSoal[nomorSoal - 1]].jawaban) {
                                soalBenar += 1;
                                skor += 10;
                                printf(GREEN"Jawaban benar! Tekan n untuk lanjut..."RESET);

                                // Tunggu hingga pengguna menekan 'n'
                                char lanjut;
                                do {lanjut = charTanpaBuffer();} 
                                while (lanjut != 'n' && lanjut != 'N');
                                
                                break; // Lanjut ke soal berikutnya
                            } 
                            
                            else {
                                // Jawaban salah, permainan berakhir
                                printf(RED"Jawaban salah!"RESET GREEN" Jawaban yang benar adalah %c.\n"RESET"Permainan berakhir.\n", kumpulanSoal[ptrUrutanSoal[nomorSoal - 1]].jawaban);
                                if (soalBenar == 0) printf("Anda gagal menjawab satu soalpun dengan benar!\n");
                                else printf("Anda berhasil menjawab %d soal dengan benar!\n", soalBenar);
                                tampilSkor(skor);
                                free(ptrUrutanSoal);
                                char kembali;
                                do{kembali = charTanpaBuffer();} while(kembali != 'y' && kembali != 'Y');
                                break;
                            }
                        }

                        // Kembali ke menu utama setelah salah menjawab soal
                        if (jawabanPengguna != kumpulanSoal[ptrUrutanSoal[nomorSoal - 1]].jawaban && validasiInput){
                            clearTerminal();
                            kepalaProgram();
                            menuUtama();
                            break;
                        }
                    }

                    // Berhasil menjawab semua soal dengan benar
                    if (soalBenar == maxSoal){
                        clearTerminal();
                        printf(GREEN"Selamat! Anda berhasil menjawab semua soal dengan benar!\n"RESET);
                        tampilSkor(skor);
                        free(ptrUrutanSoal);
                        
                        // Kembali ke menu utama
                        char kembali = charTanpaBuffer();
                        if (kembali == 'y' || kembali == 'Y') {
                            clearTerminal();
                            kepalaProgram();
                            menuUtama();
                            continue;
                        }
                    }
                }

                // User memilih opsi peraturan
                else if (PlayerChoice == '2'){
                    // Menampilkan aturan sampai user memilih kembali
                    clearTerminal();
                    peraturan();
                    do{
                        PlayerChoice = charTanpaBuffer();
                        if (PlayerChoice == 'y')
                        {
                            clearTerminal();
                            kepalaProgram();
                            menuUtama();
                        }
                    } while(PlayerChoice != 'y');          
                }

                // User menekan selain 1, 2, dan 3
                else continue;

            } while(PlayerChoice != '3'); 
            
            fclose(flogin);
            clearTerminal();
            printf("\n==================================\n");
            printf(  "* Senang bermain dengan Anda ^_^ *\n");
            printf(  "==================================\n\n");
        }
    }

    // Argumen yang diberikan bukan sebanyak 1 atau 3    
    else
    {
        clearTerminal();
        printf(RED"\nERROR:"RESET" \nFormat login: ./<Nama Program> <Username> <Password> \nBaca selengkapnya di README.md\n\n"); // 
    }

    return 0;
}

// 1. Fungsi untuk membersihkan terminal
void clearTerminal() {
    printf("\e[1;1H\e[2J");
}

/* 2. Fungsi untuk menginput identitas
   Contoh penggunaan: ptrInputString("Nama", 50);
   Contoh di atas akan meminta user untuk menginput nama dengan panjang maksimal 50 */
char *ptrInputString(const char identitas[], int batasPanjangInput)
{
    // Mengalokasikan memori untuk mengembalikan inputan
    char *input = malloc(batasPanjangInput + 1);
    if (input == NULL) {
        printf("\n======================================\n");
        printf("  | "RED"ERROR:"RESET" Gagal mengalokasikan memori |\n");
        printf("  ======================================\n\n");
        exit(1);
    }

    // Input dari user
    printf("%s: ", identitas); fgets(input, batasPanjangInput + 2, stdin);
    size_t len = strlen(input);
    
    // Menghilangkan '\n' dari inputan fgets()
    input[strcspn(input, "\n")] = 0;

    // Memastikan input tidak kosong
    if (strlen(input) == 0) {
        clearTerminal();
        printf("\n======================================\n");
        printf("  | "RED"ERROR:"RESET" %s tidak boleh kosong |\n", identitas);
        printf("  ======================================\n\n");
        free(input);
        exit(1);
    }

    // Memastikan tidak ada spasi dalam input
    if (strchr(input, ' ') != NULL){
        clearTerminal();
        printf("\n==================================================\n");
        printf(  "| "RED"SIGN UP FAILED:"RESET" %s harus dalam satu kata |   \n", identitas);
        printf(  "==================================================\n\n");
        free(input);
        exit(1);
    }

    // Memastikan input tidak melebihi batas panjang
    if (strlen(input) > batasPanjangInput) {
        clearTerminal();
        printf("\n==============================================\n");
        printf(  "| "RED"SIGN UP FAILED:"RESET" %s tidak boleh lebih       |\n", identitas);
        printf(  "|                 dari %d karakter           |\n", batasPanjangInput);
        printf(  "==============================================\n\n");
        free(input);
        exit(1);
    }

    return input;
}

// 3. Fungsi untuk mengakses file dan menentukan mode eksekusi
FILE *bukaFile(char *namaFile, char *modeFile)
{
    FILE *file;
    // File gagal diakses
    if ((file = fopen(namaFile, modeFile)) == NULL){
            printf("\n==============================\n");
            printf(  "| "RED"ERROR:"RESET" Gagal membuka file! |\n");
            printf(  "==============================\n\n");
            exit(1);
        }

    return file;
}

// 4. Fungsi ini mengisi nilai nol sampai jumlahElemen - 1 ke dalam
// sebuah pointer array dengan urutan acak.
int *ptrElemenAcak(int jumlahElemen) {
    // Gunakan variabel statis untuk memastikan srand hanya dipanggil sekali
    static int sudahDiinisialisasi = 0;
    if (!sudahDiinisialisasi) {
        srand(time(NULL)); // Inisialisasi seed acak
        sudahDiinisialisasi = 1; // Tandai bahwa srand sudah dipanggil
    }

    int *ptrIndex = malloc(jumlahElemen * sizeof(int));
    if (ptrIndex == NULL) {
        printf("\n======================================\n");
        printf(  "| "RED"ERROR:"RESET" Gagal mengalokasikan memori |\n");
        printf(  "======================================\n\n");
        exit(1);
    }

    int penanda[jumlahElemen];
    for (int i = 0; i < jumlahElemen; i++) {
        penanda[i] = 0; // Inisialisasi ke 0
    }
    
    for (int i = 0; i < jumlahElemen; i++) {
        int indexAcak;
        do {
            indexAcak = rand() % jumlahElemen; // Menghasilkan angka acak
        } while (penanda[indexAcak] == 1); // Ulangi jika angka sudah digunakan

        ptrIndex[i] = indexAcak;       // Simpan angka acak yang valid
        penanda[indexAcak] = 1;   // Menandai angka yang sudah digunakan
    }

    return ptrIndex;
}
