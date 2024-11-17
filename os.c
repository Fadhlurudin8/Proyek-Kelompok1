#include <stdio.h>

#ifdef __linux__
    #include <ncurses.h>
#endif

int main(){

    #ifdef __linux__
        printf("Linux\n");
    #endif

    #ifdef __unix__ 
        printf("UNIX\n");
    #endif

    #ifdef __APPLE__
        printf("Mac\n");
    #endif

    return 0;
}
