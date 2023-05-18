#include <stdio.h>
#define max 210

void mark_in_grid(int grid[max][max]) {
    int x1, y1, x2, y2, temp;
    scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
    if (x1 > x2) {temp = x1; x1 = x2; x2 = temp;}
    if (y1 < y2) {temp = y1; y1 = y2; y2 = temp;}
    for (int row = y1; row > y2; row--) {
        for (int col = x1; col < x2; col++) {
            if (grid[100-row][col+100] == 0) {grid[100-row][col+100] = 1;}
            else {grid[100-row][col+100] = 0;}
        }
    }
}

int main(void) {
    int N, sum = 0, grid[max][max] = {{0}};
    printf("Enter number of rectangles[N]:");
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        printf("Enter %d. four digits:",i);
        mark_in_grid(grid);
        printf("\n");
    }
    for (int row = 0; row < 210; row++) {
        for (int col = 0; col < 210; col++) {
            if (grid[row][col] == 1) { sum++; }
        }
    }
    for (int row = 90; row < 110; row++) {
        for (int col = 90; col < 110; col++) {
            printf("%d ",grid[row][col]);
        }
        printf("\n");
    }
    printf("%d\n",sum);
    return 0;
}
