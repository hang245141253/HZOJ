#include <iostream>
using namespace std;

void reverse(string* srr, int n) {
    for (int i = 0; i < n; i++) {
        int head = 0, tail = srr[i].size() - 1;
        while (head < tail) {
            swap(srr[i][head], srr[i][tail]);
            head++;  tail--;
        }
    }
}

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

    reverse(srr, n);
    sort(srr, n);

    for (int i = 0; i < n; i++) {
        cout << srr[i] << endl;
    }
    return 0;
}