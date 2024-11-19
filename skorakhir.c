#include <stdio.h>

void printScore(int score1, int score2) {
    printf("===================================\n");
    printf("           FINAL SCORE            \n");
    printf("===================================\n");
    printf("     Team 1           Team 2      \n");
    printf("       %d               %d         \n", score1, score2);
    printf("===================================\n");

    if (score1 > score2) {
        printf("         Team 1 Wins!             \n");
    } else if (score1 < score2) {
        printf("         Team 2 Wins!             \n");
    } else {
        printf("          It's a Tie!             \n");
    }
    printf("===================================\n");
}

int main() {
    int score1, score2;

    printf("Enter score for Team 1: ");
    scanf("%d", &score1);

    printf("Enter score for Team 2: ");
    scanf("%d", &score2);

    // Display the final score and result
    printScore(score1, score2);

    return 0;
}
