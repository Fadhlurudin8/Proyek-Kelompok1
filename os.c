#include <stdio.h>
#include <ncurses.h>

// #ifdef __linux__
// #endif

int main(){
    char input;
    #ifdef __linux__
        printf("Linux\n");
        initscr(); 
        cbreak(); 
        noecho();
        input = getch();
        refresh();
        getch();
        endwin();
        printf("%c", input);
    #endif

    #ifdef __unix__ 
        printf("UNIX\n");
    #endif

    #ifdef __APPLE__
        printf("Mac\n");
    #endif

    return 0;
}
