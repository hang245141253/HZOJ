#include <iostream>
using namespace std;

int max(int* arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (max < arr[i])   max = arr[i];
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n]();
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << max(arr, n) << endl;
    return 0;
}