#include <cstdio>

bool binary_Serach(int *arr, int min, int max, int x) {
    if (min > max)  return false;
    int mid = (min + max) / 2;
    if (arr[mid] == x)   return true;
    if (arr[mid] > x)    max = mid - 1;
    else                 min = mid + 1;
    return binary_Serach(arr, min, max, x);
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = new int[n]();
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int k, s;
    scanf("%d%d", &k, &s);

    if (binary_Serach(arr, 0, n, s - k))    printf("Yes\n");
    else    printf("No\n");

    return 0;
}