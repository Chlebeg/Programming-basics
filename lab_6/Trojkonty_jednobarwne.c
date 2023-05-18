#include <stdio.h>
#define max 100                 // przy liczbie punktów > 10 należy zwiększyć max-a

int find_triangles(int grid[max][max],int P) {              // przekazujemy 2D tablice, liczbę punktów
    int sum = 0;                                            // kolor czarny = 0, kolor czerwony = 1
    for (int i = 1; i <= P; i++) {                          // przechodzimy przez wszystkie kombinacje punktów
        for (int j = i + 1; j <= P; j++) {
            for (int k = j + 1; k <= P; k++) {              // porównujemy czy wszystkie połączenia mają ten sam kolor
                if (grid[i-1][j-1] == 0 && grid[i-1][k-1] == 0 && grid[j-1][k-1] == 0) {
                    sum++;                                  // dla czarnego
                }
                if (grid[i-1][j-1] == 1 && grid[i-1][k-1] == 1 && grid[j-1][k-1] == 1) {
                    sum++;                                  // dla czerwonego
                }
            }
        }
    }
    return sum;
}

int main(void) {
    int P, R, full_grid[max][max] = {0};                    // tworzymy 2D tablicę połączeń pokolorowaną na czarno [0]
    printf("Enter two space seperated numbers: Number of points[P], Number of red lines[R]");
    scanf("%d %d",&P,&R);
    for (int i=0; i<R; i++) {                               // wypełniamy tablicę połączeniami koloru czerwonego[1]
        int x, y;
        scanf(" %d %d",&x ,&y);
        full_grid[x-1][y-1] = 1;
        full_grid[y-1][x-1] = 1;
    }
    int sum = 0;
    sum += find_triangles(full_grid, P);                // wywołujemy funkcję sprawdzającą dla obu kolorów
    printf("\n%d",sum);
    return 0;
}