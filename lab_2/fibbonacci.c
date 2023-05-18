#include <stdio.h>

int main(void) {
    int n = 0;
    int num_1 = 0;
    int num_2 = 1;
    int temp;
    int flag = 1;
    printf("Enter your N: ");
    scanf("%d", &n);
    for(int i = 0; i <= n; i++){
        if(num_1*num_2 == n){
            puts("yes");
            flag = 0;
            break;
        }
        else{
            temp = num_2;
            num_2 = num_2 + num_1;
            num_1 = temp;
        }
    }
    if(flag) {
        puts("no");
    }
    return 0;
}