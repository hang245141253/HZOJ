#include <cstdio>

void init(int* arr, int n, int index[]) {
    for (int i = 2; i <= n; i++) {
        if (arr[i]) continue;
        index[++index[0]] = i;
        for (int j = i; j <= n / i; j++) {
            arr[j * i] = 1;
        }
    }
    return ;
}

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    int *arr = new int[n + 1]();
    int index[n / 8] = {};
    init(arr, n, index);
    for (int x = 1; x <= index[0]; x++) {
        if (__builtin_expect(!!(arr[index[x]] == -1), 0)) break;
        if (!arr[n - index[x]]--)  cnt++;
    }
    printf("%d\n", cnt);
    
    return 0;
}