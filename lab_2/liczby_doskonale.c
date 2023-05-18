#include <stdio.h>

int main(void) {
    int n = 0;
    printf("Enter your N: ");
    scanf("%d", &n);
    for(int i = 5; i <= n; i++) {
        int num = i;
        int sum = 0;

        for(int j = 1; j < i; j++) {
            if (num % j == 0){
                sum = sum + j;
            }
        }
        if (sum == num) {
            printf("%d\n",num);
        }
    }
    return 0;
}
