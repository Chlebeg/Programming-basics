#include <stdio.h>

int main(void) {
    int N;
    printf("Enter your N:");
    scanf("%d", &N);
    int arr[250], length = 1, x, remainder, i = 2;
    //arr - our number but backwards (each number as an item in arr), length - len of our list(now),
    //x and remainder - temp numbers, i - multiply till i = N
    arr[0] = 1;
    //we start multiplying with number 1
    while (i <= N) {
        x = 0, remainder = 0;
        while (x < length) {
            arr[x] *= i;
            arr[x] += remainder;
            remainder = arr[x] / 10;
            arr[x] = arr[x] % 10;
            x++;
        }
        while (remainder != 0) {
            arr[length] = remainder % 10;
            remainder /= 10;
            length++;
        }
        i++;
    }
    length--;// because we print from len-1 to 0
    printf("Factorial of number %d is: ",N);
    while( length >= 0) {
        printf("%d",arr[length]);
        length--;
    }
    return 0;
}
