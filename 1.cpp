#include <cstdio>
#define MAX_N 100

int count = 0;

void prime(int* arr) {
    for (int i = 2; i < MAX_N; i++) {
        if (arr[i]) continue;
        for (int j = i; j < MAX_N; j += i) {
            arr[j] = 1;
        }
    }
}

void perfect_square(int *brr) {
    for (int i = 4; i * i < MAX_N; i++) {
        brr[i * i] = 1;
    }
}


int is_divided6(int x) {
    return (x % 6) ? 0 : 1;
}

int is_prime(int* arr, int x) {
    x /= 100;
    printf("**%d**\n" , x);
    return arr[x] ? 0 : 1;
}

int is_perfect_square(int* brr, int x) {
    x %= 100;
    return brr[x] ? 1 : 0;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int *arr = new int[MAX_N]();
    int *brr = new int[MAX_N]();
    prime(arr);
    perfect_square(brr);

    for ( ; a < b + 1; a++) {
        if (is_prime(arr, a)) {
            printf("%d ", a);
        }
    }

    return 0;
}