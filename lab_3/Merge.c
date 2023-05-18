#include <stdio.h>
#include <stdlib.h>

int bubble_sort(int arr[], int n) {
    for (int i=0; i < n; i++) {
        for (int j=0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int a = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = a;
            }
        }
    }
}

int merge(int t1[], int t2[], int t3[], int N1, int N2) {
    int i, j;
    i = 0;
    j = 0;
    while (i < N1 && j < N2) {
        if (t1[i] <= t2[j]) {
            t3[i + j] = t1[i];
            i++;
        }
        else {
            t3[i + j] = t2[j];
            j++;
        }
    }
    while (i < N1) {
        t3[i + j] = t1[i];
        i++;
    }
    while (j < N2) {
        t3[i + j] = t2[j];
        j++;
    }
    int k = 0;
    for (int i = 0; i < N1+N2; i++){
        if (t3[i] != t3[i+1]){
            printf("%d ", t3[i]);
            k++;
        }
    }
    printf("\n%d ", k);
}

int main(void) {
    int N1, N2;
    printf("Enter your length of t1:");
    scanf("%d", &N1);
    printf("Enter your length of t2:");
    scanf("%d", &N2);
    int N3 = N1 + N2;
    int t1[N1], t2[N2], t3[N3];

    for (int i = 0; i <= N1; i++){
        t1[i] = rand() % 10;
    }
    for (int i = 0; i <= N2; i++){
        t2[i] = rand() % 10;
    }
    bubble_sort(t1,N1);
    bubble_sort(t2,N2);

    for (int i = 0; i < N1; i++)
        printf("%d ", t1[i]);
    printf("\n");
    for (int i = 0; i < N2; i++)
        printf("%d ", t2[i]);
    printf("\n");
    merge(t1,t2,t3,N1,N2);

    return 0;
}