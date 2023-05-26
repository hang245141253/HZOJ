#include <cstdio>

// 递归
int binary_Search(int *arr, int min, int max, int x) {
    if (min > max)     return -1;  // 注意不要 >=
    int mid = (min + max) >> 1;
    if (x == arr[mid])  return mid;
    if (x < arr[mid])   max = mid - 1;
    else                min = mid + 1;
    return binary_Search(arr, min, max, x);
}

// 循环
int binary_Search(int *arr, int max, int x) {
    int min = 0, mid;
    while (min <= max) {
        mid = (max + min) >> 1;
        if (x == arr[mid])  return mid;
        if (x < arr[mid])   max = mid - 1;
        else    min = mid + 1;
    }
    return -1;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int *nrr = new int[n + 5]();
    for (int i = 0; i < n; i++) {
        scanf("%d", &nrr[i]);
    }
    int *krr = new int[k + 5]();
    
    for (int i = 0; i < k; i++) {
        scanf("%d", &krr[i]);
        i && printf(" ");
        printf("%d", binary_Search(nrr, 0, n - 1, krr[i]) + 1);
        // printf("%d", binary_Search(nrr, n - 1, krr[i]) + 1);
    }
    printf("\n");

    return 0;
}