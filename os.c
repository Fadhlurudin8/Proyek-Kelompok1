#include <stdio.h>

int main(){

    #ifdef __linux__
        printf("Linux");
    #endif

    #ifdef __unix__ 
        printf("UNIX");
    #endif

    #ifdef __APPLE__
        printf("Mac");
    #endif

    return 0;
}