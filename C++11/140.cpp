#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    char ch = 'A';

    for (int i = 1; i <= n; i++, ch++) {
        for (int j = i; j < n; j++) {
            cout << " ";
        }
        for (int k = 0; k < (i - 1) * 2 + 1; k++) {   //  (i-1)*2+1 : 1, 3, 5 , ...
            cout << (char)(ch);
        }
        cout << endl;
    }
    ch -= 2;
    for (int i = n - 1; i >= 1; i--, ch--) {
        for (int j = i; j < n; j++) {
            cout << " ";
        }
        for (int k = 0; k < (i - 1) * 2 + 1; k++) {   //  (i-1)*2+1 : 1, 3, 5 , ...
            cout << (char)(ch);
        }
        cout << endl;
    }
    return 0;   
}