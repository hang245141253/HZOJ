#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    char ch = 'A';

    for (int i = 1; i <= n; i++, ch++) {
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        //  2 * i - 1 : 1, 3, 5 , ...
        for (int k = 0; k < 2 * i - 1; k++) {
            printf("%c", ch);
        }
        printf("\n");
    }
    ch -= 2;
    for (int i = n - 1; i >= 1; i--, ch--) {
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        //  2 * i - 1 : 1, 3, 5 , ...
        for (int k = 0; k < 2 * i - 1; k++) {
            printf("%c", ch);
        }
        printf("\n");
    }
    return 0;
}