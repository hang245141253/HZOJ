#include <iostream>
using namespace std;

long long pow(int n) {
    if (n == 1) return 2;
    return 2 * pow(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << pow(n) << endl;
    return 0;
}