#include <stdio.h>

#ifdef __linux__
    #include <ncurses.h>
#endif

int main(){
    char input;
    #ifdef __linux__
        printf("Linux\n");
        initscr(); cbreak(); noecho();
        input = getch();
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
