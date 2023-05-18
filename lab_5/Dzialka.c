#include <stdio.h>
#include <stdlib.h>
#define max 100

void auto_grid_maker(int N,int grid[max][max]) {
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

void manual_grid_maker(int N,int grid[max][max]) {
    int number = 0;
    printf("You need to fill the grid with 1 and 0,\nnumbers greater than > 1 will be converted with mod(2)\n");
    for (int row = 0; row < N; row++) {
        printf("Please enter %d row of your grid, with space seperated numbers:", row+1);
        for (int col = 0; col < N; col++) {
            scanf(" %d", &number);
            grid[row][col] = number % 2;
        }
    }
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {printf("%d ", grid[row][col]);}
        printf("\n");
    }
}

int check_this_point(int N, int grid[max][max], int row, int col) {
    int max_point = 1, x = 1, y = 1;
    while (grid[row+x][col] == 0 && (row+x) < N) {x++;}         // Sprawdzam jakie może być max rozmiar pola
    while (grid[row][col+y] == 0 && (col+y) < N) {y++;}         // Przypadek 1:
    if (x == 1 || y == 1) {                                     // jak jedna z wartości x/y = 1 to mamy prostokąt o polu y/x
        if (x >= y) {max_point = x;}
        else {max_point = y;}
        return max_point;
    }
    for (int i = 1; i < x; i++) {                               // Przypadek 2:
        for (int j = 1; j < y; j++) {                           // możliwa działka x > 1 na y > 1
            if (grid[row+i][col+j] != 0) {                      // lecę po kolumnie = col i sprawdzam jak daleko w prawo może być pole
                y = j;                                          // gdy natrafię na 1 to zawężam pole szukania do y = j
                break;
            }
        }
        int value_here = (i+1)*(y);                             // Po znalezieniu możliwego max pola porównuję go z obecnie największym polem
        if (value_here > max_point) {max_point = value_here;}
    }
//    printf ("row: %d",row); printf (" col:%d \n",col);
//    printf ("%d",i); printf (" %d \n",j);
    return max_point;
}

void find_field(int N, int grid[max][max]) {
    int max_field = 0, max_point = 0;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == 0) {max_point = check_this_point(N,grid,row,col);}
            if (max_point > max_field) {max_field = max_point;}
        }
    }
    printf("Max field is: %d",max_field);
}

int main(void) {
    int N; char decision;
    printf("Enter size of the grid:");
    scanf("%d", &N);
    int grid[max][max];
    printf("Do you want to make grid manually? [Y/N]");
    scanf(" %c", &decision);
    if (decision == 'Y') { manual_grid_maker(N,grid); }
    else { auto_grid_maker(N,grid); }
    find_field(N,grid);
    printf("\n");
    return 0;
}