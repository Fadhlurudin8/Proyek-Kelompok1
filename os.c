#include <ncurses.h>

int main() {
    initscr();
    cbreak();              // Non-buffered input
    noecho();              // Non-echo input
    printw("Tekan tombol untuk melanjutkan (tanpa Enter): ");
    refresh();
    char c = getch();      // Tunggu input
    printw("\nAnda menekan: %c\n", c);
    refresh();
    getch();
    endwin();
    return 0;
}