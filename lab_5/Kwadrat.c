#include <stdio.h>
#include <stdlib.h>
#define max 100

void auto_grid_maker(int N,int grid[max][max]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            int a = rand() % 10;
                grid[row][col] = a;
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

void manual_grid_maker(int N,int grid[max][max]) {
    int number = 0;
    printf("You need to fill the grid with numbers from 0-100,\nnumbers greater than > 100 will be converted with mod(100)\n");
    for (int row = 0; row < N; row++) {
        printf("Please enter %d row of your grid, with space seperated numbers:", row+1);
        for (int col = 0; col < N; col++) {
            scanf(" %d", &number);
            grid[row][col] = number % 100;
        }
    }
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {printf("%d ", grid[row][col]);}
        printf("\n");
    }
}

void check_every_position(int N, int k, int grid[max][max]) {
    int q = 0, list_of_squares[max][2];
    for (int row = 1; row < (N-1); row++) {
        for (int col = 1; col < (N-1); col++) {
            int r = 1;
            while (row-r>=0 && row+r<N && col-r>=0 && col+r<N) {
                int sum = 0;
                for (int x = row-r; x <= row+r; x++) {
                    sum += grid[x][col-r];
                    sum += grid[x][col+r];
                }
                for (int y = col-r+1; y <= col+r-1; y++) {
                    sum += grid[row-r][y];
                    sum += grid[row+r][y];
                }
                if (sum == k) {
                    list_of_squares[q][0] = row;
                    list_of_squares[q][1] = col;
                    q++;
                }
                    r++;
            }
        }
    }
    printf("Found %d squares\n",q);
    if (q>0) {
        for (int i = 0; i < q; i++){
            printf("%d %d\n",list_of_squares[i][0],list_of_squares[i][1]);
        }
    }
}

int main(void) {
    int N , k; char decision;
    printf("Enter size of the grid[N]:");
    scanf("%d", &N);
    if (N <= 2) {                                               // tablica musi być >=3 by mógł istnieć jakikolwiek kwadrat
        printf("Too small grid to find any square");
        return 2;
    }
    int grid[max][max];
    printf("Enter sum of elements on the boundary[k]:");
    scanf(" %d", &k);
    printf("Do you want to make grid manually? [Y/N]");
    scanf(" %c", &decision);
    if (decision == 'Y') { manual_grid_maker(N,grid); }
    else { auto_grid_maker(N,grid); }
    check_every_position(N,k,grid);
    printf("\n");
    return 0;
}