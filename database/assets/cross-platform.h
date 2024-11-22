// Platform Windows
#ifdef _WIN32
    #include <conio.h>
// Platform UNIX, Linux, dan Mac
#elif __linux__ || __unix__ || __APPLE__
    #include <termios.h>
    #include <unistd.h>
#else
    #error "Sistem operasi tidak didukung"
#endif

/* Fungsi untuk input char tanpa buffer 
   Berguna untuk buat opsi pilihan kepada user*/
char charTanpaBuffer()
{
    char input;
    #ifdef _WIN32
        input = _getch(); // input char tanpa buffer dan echo
    #elif __linux__ || __unix__ || __APPLE__
        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);           // Simpan pengaturan terminal saat ini
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);         // Nonaktifkan mode kanonik dan echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Terapkan pengaturan baru

        input = getchar();                        // Ambil karakter dari input
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Kembalikan pengaturan terminal lama
    #endif
    
    return input;
}
