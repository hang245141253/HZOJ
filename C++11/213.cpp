#include <cstdio>
#define swap(a, b) {\
	int tmp=a;\
	a=b;b=tmp;\
}

void sort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j] > arr[j - 1]; j--) {
            swap(arr[j], arr[j - 1]);
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
    int brr[6] = {};
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
        if (arr[i] == 100)      brr[0]++;
        else if (arr[i] > 89)   brr[1]++;
        else if (arr[i] > 79)   brr[2]++;
        else if (arr[i] > 69)   brr[3]++;
        else if (arr[i] > 59)   brr[4]++;
        else                    brr[5]++;
    }

    for (int i = 0; i < 6; i++) {
        i && printf(" ");
        printf("%d", brr[i]);
    }


    return 0;
}