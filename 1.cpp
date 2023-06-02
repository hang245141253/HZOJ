#include <cstdio>

void init(int* arr, int r) {
    for (int i = 2; i <= r; i++) {
        if (arr[i]) continue;
        arr[++arr[0]] = i;
        for (int j = i; j <= r / i; j++) {
            arr[j * i] = 1;
        }
    }
}

int min_index(int *arr, int l) {
    for (int i = 1; i <= arr[0]; i++) {
        if (arr[i] == l) return i;
    }
    return -1;
}

int main() {
    int l, r;
    scanf("%d%d", &l, &r);
    int *arr = new int[r + 1]();
    init(arr, r);

    for (int i = 1; i <= arr[0]; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    printf("%d", min_index(arr, l));


    return 0;
}