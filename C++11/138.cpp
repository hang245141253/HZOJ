#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < 2 * i; j++) {
            cout << "A";
        }
        cout << endl;
    }
    return 0;   
}