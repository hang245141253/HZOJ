#include <iostream>
using namespace std;

typedef struct height {
    int num, h;
}height;

int main() {
    int n;
    cin >> n;
    height *arr = new height[n + 1]();

    for (int i = 1; i < n + 1; i++) {
        arr[i].num = i;
        cin >> arr[i].h;
    }

    // maopao
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n - i + 1; j++) {
            if (arr[j].h > arr[j + 1].h)    swap(arr[j], arr[j + 1]);
        }
    }

    for (int i = 1; i < n + 1; i++) {
        (i - 1) && cout << " ";
        cout << arr[i].num;
    }

    return 0;
}