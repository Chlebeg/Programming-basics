#include <stdio.h>
#include <string.h>
#define max 20

// program nie działa prawidłowo dla liczb których suma > 3999
// notatka: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
int change_from_roman(char *str) {
    int len = strlen(str), sum = 0;
    for (int i = 0; i < len; i++) {
        switch (str[i]) {
            case 'I':
                if (str[i+1] == 'V' || str[i+1] == 'X') {sum -= 1;}
                else {sum += 1;}
                break;
            case 'V':
                sum += 5;
                break;
            case 'X':
                if (str[i+1] == 'L' || str[i+1] == 'C') {sum -= 10;}
                else {sum += 10;}
                break;
            case 'L':
                sum += 50;
                break;
            case 'C':
                if (str[i+1] == 'D' || str[i+1] == 'M') {sum -= 100;}
                else {sum += 100;}
                break;
            case 'D':
                sum += 500;
                break;
            case 'M':
                sum += 1000;
        }
    }
    return sum;
}

void change_to_roman(int sum, char *result) {
    char a, b, c;
    char str[max] = {0};                // number: 0 pass, 1 2 3 = I II III, 4 = IV, 5 = V, 6 7 8 = VI VII VIII, 9 = IX
    int position = 0, set = 1;          // set: 1. {I,V,X}, 2. {X,L,C}, 3. {C,D,M}, 4. {M}
    while (sum != 0) {                  // np. dla set 1.: a = I, b = V , c = X
        int number = sum % 10;
        switch (set) {                      // ustalamy zestaw znaków
            case 1:
                a = 'I'; b = 'V'; c = 'X';
                break;
            case 2:
                a = 'X'; b = 'L'; c = 'C';
                break;
            case 3:
                a = 'C'; b = 'D'; c = 'M';
                break;
            case 4:
                a = b = c = 'M';
                break;
        }
        switch (number) {                   // piszemy liczbę od tyłu np. CCCLXXIX będzie XIXXLCCC
            case 3:
                str[position] = a;
                position++;
            case 2:
                str[position] = a;
                position++;
            case 1:
                str[position] = a;
                position++;
                break;
            case 4:
                str[position] = b;
                str[position+1] = a;
                position += 2;
                break;
            case 5:
                str[position] = b;
                position++;
                break;
            case 8:
                str[position] = a;
                position++;
            case 7:
                str[position] = a;
                position++;
            case 6:
                str[position] = a;
                str[position+1] = b;
                position += 2;
                break;
            case 9:
                str[position] = c;
                str[position+1] = a;
                position += 2;
                break;
            case 0:
                break;
        }
        sum -= number;
        sum /= 10;
        set++;
    }
    int length = strlen(str);
    for (int j = 0; j < length; j++) {      // odwracamy liczbę by była właściwie zapisana
        result[j] = str[length - 1 - j];
    }
}

int main(void) {
    char X_rom[max], Y_rom[max];
    printf("Give two space seperated Roman numbers:");
    scanf("%s %s",X_rom,Y_rom);
    int X_ara, Y_ara;
    X_ara = change_from_roman(X_rom);
    Y_ara = change_from_roman(Y_rom);
    printf("Your numbers (Arabic): %d ,%d\n",X_ara,Y_ara);
    int sum = X_ara + Y_ara;
    printf("Sum of two (Arabic): %d\n",sum);
    char result[max] = {0};
    change_to_roman(sum, result);
    printf("Sum of two (Roman): %s",result);
    return 0;
}