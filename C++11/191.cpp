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

int get_index(int *arr, int l) {
    for (int i = 1; i <= arr[0]; i++) {
        if (arr[i] >= l) return i;
    }
    return 0;
}

int main() {
    int l, r;
    scanf("%d%d", &l, &r);
    int *arr = new int[r + 1]();
    init(arr, r);

    int min = 0x0fffffff, max = 0;
    int min_index = 0, max_index = 0;
    for (int i = get_index(arr, l); i < arr[0]; i++) {
        if (min > arr[i + 1] - arr[i]) {
            min = arr[i + 1] - arr[i];
            min_index = i;
        }
        if (max < arr[i + 1] - arr[i]) {
            max = arr[i + 1] - arr[i];
            max_index = i;
        }
    }
    if (arr[0] - get_index(arr, l) > 1) printf("%d,%d are closest, %d,%d are most distant.\n", arr[min_index], arr[min_index + 1], arr[max_index], arr[max_index + 1]);
    else printf("There are no adjacent primes.\n");
    
    return 0;
}