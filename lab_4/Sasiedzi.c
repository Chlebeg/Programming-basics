#include <stdio.h>
#include <stdlib.h>
#define max 100

void Grid_maker(int N,int grid[max][max]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            int a = rand() % 10;
            if (a >= 5) {
                grid[row][col] = 1;
            } else {
                grid[row][col] = 0;
            }
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

void Look_for_ones(int N, int R, int grid[max][max], int row, int col) {
    int sum = 0;
    for (int start_row = row - R; start_row <= row + R; start_row++) {
        for (int start_col = col - R; start_col <= col + R; start_col++) {
            if ((start_row < 0) || (start_row >= N) || (start_col < 0) || (start_col >= N)) {}
            else {
                if (grid[start_row][start_col] == 1) {sum++;}
            }
        }
    }
    printf("%d ",sum);
}

void Check_every_position(int N,int R,int grid[max][max]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            Look_for_ones(N, R, grid, row, col);
        }
        printf("\n");
    }
}

int main(void) {
    int N, R;
    printf("Enter size of the grid:");
    scanf("%d", &N);
    printf("Enter radius for the checking:");
    scanf("%d", &R);
    int grid[max][max];
    Grid_maker(N,grid);
    printf("\n");
    Check_every_position(N,R,grid);
    return 0;
}