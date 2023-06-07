#include <cstdio>
#define swap(a, b) a^=b, b^=a, a^=b

void find_column_max(int** arr, int m, int n) {
    for (int j = 0; j < n; j++) {
        int max = 0;
        for (int i = 0; i < m; i++) {
            if (max < arr[i][j])    max = arr[i][j];
        }
        printf("%d\n", max);
    }
}

void two2one(int **arr, int *brr, int m, int n){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            brr[i * n + j] = arr[i][j];
        }
    }
}

void sort_print(int* brr, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i; j > 0 && brr[j] > brr[j - 1]; j--) {
            swap(brr[j], brr[j - 1]);
        }
    }

    double sum = 0;
    for (int i = 0; i < length; i++) {
        i && printf(" ");
        printf("%d", brr[i]);
        sum += brr[i];
    }
    int avg = (int)(sum / length + 0.5);
    printf("\n%d\n", avg);

    int conut = 0;
    for (int i = 0; i < length; i++) {
        if (!(brr[i] < avg))   conut++;
    }
    printf("%d\n", conut);
}

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    int **arr = new int*[m]();
    int *brr = new int[m * n]();
    for (int i = 0; i < m; i++) {
        arr[i] = new int[n]();
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    find_column_max(arr, m, n);
    two2one(arr, brr, m, n);
    sort_print(brr, m * n);
    
    return 0;
}