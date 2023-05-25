#include <cstdio>
// cout真的比printf占用很多资源！！！
void init(int* arr, int N, int M) {
    for (int i = 2; i <= N; i++) {
        if (arr[i]) continue;
        for (int j = i; j <= N / i; j++) {
            arr[j * i] = 1;
        }
        if (__builtin_expect(!(i < M), 1)) printf("%d\n", i);
    }
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int *arr = new int[N + 1]();
    init(arr, N, M);
    return 0;
}

