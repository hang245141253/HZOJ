#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 2 * i; j < 2 * n; j++) {
            cout << "A";
        }
        cout << endl;
    }
    return 0;   
}