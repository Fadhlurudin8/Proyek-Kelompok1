// Platform Windows
#ifdef _WIN32
    #include <conio.h>
// Platform UNIX, Linux, dan Mac
#elif __linux__ || __unix__ || __APPLE__
    #include <ncurses.h>
#else
    #error "Sistem operasi tidak didukung"
#endif

/* Fungsi untuk input char tanpa buffer 
   Berguna untuk buat opsi pilihan kepada user*/
char char_tanpa_buffer()
{
    char input;
    #ifdef _WIN32
    {
        input = _getch();
        return input;
    }
    
    #elif __linux__ || __unix__ || __APPLE__
    {
        initscr(); cbreak(); noecho();
        input = getch();
        // refresh();
        // endwin();
        return input;
    }

    #endif
}
