#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int t1[10], *p1;
    double t2[10], *p2;
    for (int i = 0; i < 10; i++){
        t1[i] = rand() % 10;
    }
    for (int i = 0; i < 10; i++){
        t2[i] = rand() % 10;
    }
    printf("int numbers and addresses:\n");
    for (int i = 0; i < 10; i++) {
        printf("N:%d ", t1[i]);
        printf("A:%p ", &t1[i]);
        printf("\n");
    }
    printf("double numbers and addresses:\n");
    for (int i = 0; i < 10; i++) {
        printf("N:%lf ", t2[i]);
        printf("A:%p ", &t2[i]);
        printf("\n");
    }
    printf("int numbers and addresses with pointer:\n");
    for (int i = 0; i < 10; i++) {
        p1 = &t1[i];
        printf("N:%d ", *p1);
        printf("A:%p ", p1);
        printf("\n");
    }
    printf("double numbers and addresses with pointer:\n");
    for (int i = 0; i < 10; i++) {
        p2 = &t2[i];
        printf("N:%lf ", *p2);
        printf("A:%p ", p2);
        printf("\n");
    }
}