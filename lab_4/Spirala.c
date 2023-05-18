#include <stdio.h>

int main(void) {
    int N;
    printf("Enter size of the grid: ");
    scanf("%d", &N);
    int row = 0, col = 0, boundary = N - 1, Leftsize = N - 1, rotations = 1;
    char move = 'r'; // Which direction we move: r = right, l = left, u = up, d = down
    int grid[N][N];

    for (int i = 1; i < N * N + 1; i++) {
        grid[row][col] = i;
        switch (move) {
            case 'r':
                col += 1;
                break;
            case 'l':
                col -= 1;
                break;
            case 'u':
                row -= 1;
                break;
            case 'd':
                row += 1;
                break;
            default:
                col += 1;
        }
        if (i == boundary) {
            boundary += Leftsize;
            if (rotations) {
                rotations = 0;
            }
            else {
                rotations = 1;
                Leftsize -= 1;
            }
            switch (move) {
                case 'r':
                    move = 'd';
                    break;
                case 'd':
                    move = 'l';
                    break;
                case 'l':
                    move = 'u';
                    break;
                case 'u':
                    move = 'r';
                    break;
                default:
                    move = 'd';
            }
        }
    }
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            printf("%d ",grid[row][col]);
        }
        printf("\n");
    }
    return 0;
}
