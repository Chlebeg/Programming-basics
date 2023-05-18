#include <stdio.h>

int main(void) {
    int n, prime_flag;
    printf("Enter your N: ");
    scanf("%d", &n);
    for (int number; number < n; number++) {
        prime_flag = 1;
        for (int i = 2; i < number; i++)
            if (number % i == 0) {
                prime_flag = 0;
                break;
            }
        if (prime_flag) {
            if (number < 10)
                printf("%d, ", number);
            else {
                int descending_flag = 1;
                int copy_number = number;
                int digit = copy_number % 10;
                while (copy_number / 10 > 0) {
                    copy_number /= 10;
                    if (digit < copy_number % 10) {
                        descending_flag = 0;
                        break;
                    }
                    digit = copy_number % 10;
                }
                if (descending_flag)
                    printf("%d, ", number);
            }
        }
    }
    return 0;
}