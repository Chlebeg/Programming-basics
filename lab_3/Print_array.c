#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    printf("Enter your length of the array:");
    scanf("%d", &N);
    int t[N];
    for (int i = 0; i <= N; i++){
        t[i] = rand() % 10;
    }
    for (int i = 0; i < N; i++)
        printf("%d ", t[i]);
    printf("\n");
    int k, flag;
    printf("Enter your parameter k:");
    scanf("%d", &k);
    printf("Which direction should the function print: [left=1,right=(sth different)]");
    scanf("%d", &flag);
    if (flag == 1) {
        for (int i = k; i > 0; i--) {
            printf("%d ", t[i-1]);
        }
        for (int i = N; i > k; i--) {
            printf("%d ", t[i-1]);
        }
    }
    else{
        for (int i = 0; i <= (N-k); i++) {
            printf("%d ", t[k-1+i]);
        }
        for (int i = 0; i < k-1; i++) {
            printf("%d ", t[i]);
        }
    }
}