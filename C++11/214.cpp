#include <cstdio>
#define swap(a, b) a^=b, b^=a, a^=b

int main() {
    int n;
    scanf("%d", &n);
    int *arr = new int[n]();
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int k;
    scanf("%d", &k);

    //insert sort
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j] > arr[j - 1]; j--) {
            swap(arr[j], arr[j - 1]);
        }
    }

    double sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    printf("%.2lf\n", sum / k);
    delete(arr);
    return 0;
}