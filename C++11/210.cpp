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
    for (int i = 0; i < n; i++) {
        cin >> srr[i];
    }

    sort(srr, n);

    for (int i = 0; i < n; i++) {
        i && printf(" ");
        cout << srr[i];
    }
    return 0;
}