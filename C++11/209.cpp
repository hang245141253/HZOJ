#include <cstdio>
#define swap(a, b) \
            a ^= b, \
            b ^= a, \
            a ^= b

void sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1])    swap(arr[j], arr[j + 1]);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = new int[n]();
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }


    return 0;
}