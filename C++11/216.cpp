#include <iostream>
using namespace std;

void sort(string* srr, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && srr[j].compare(srr[j - 1]) < 0; j--) {
            swap(srr[j], srr[j - 1]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    string *srr = new string[n]();
    string *arr = new string[n]();
    for (int i = 0; i < n; i++) {
        cin >> srr[i];
        for (int j = 3; j < srr[i].size(); j++) {
            arr[i] += srr[i][j];
        }
    }

    sort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}