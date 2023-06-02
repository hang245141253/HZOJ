#include <cstdio>

bool binary_Serach(int *arr, int min, int max, int x) {
    if (min > max)  return false;
    int mid = (min + max) / 2;
    if (arr[mid] == x)  return true;
    if (arr[mid] > x)   max = mid - 1;
    else                min = mid + 1;
    return binary_Serach(arr, min, max, x);
}

bool is_sum(int* arr, int n, int s) {
    for (int i = 0; i < n; i++) {
        if (binary_Serach(arr, i + 1, n - 1, s - arr[i])) {
            printf("Yes\n");
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = new int[n]();
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int s;
    scanf("%d", &s);

    is_sum(arr, n, s) && printf("No\n");

    return 0;
}