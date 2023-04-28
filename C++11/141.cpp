#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    char ch = 'A';

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = i; j < n + 1; j++) {   // j: 0, 1, 2 ,3
            cout << (char)(ch + j);
        }
        for (int j = n - 1; j >= i; j--) {  // j: 2, 1, 0
            cout << (char)(ch + j);
        }
        cout << endl;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = i; j < n + 1; j++) {   // j: 0, 1, 2 ,3
            cout << (char)(ch + j);
        }
        for (int j = n - 1; j >= i; j--) {  // j: 2, 1, 0
            cout << (char)(ch + j);
        }
        cout << endl;
    }
    return 0;   
}