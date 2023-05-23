#include <iostream>
using namespace std;

int f(int x) {
    if (x < 1)          return 0;
    else if (x == 1)    return 1;
    else if (x & 1)     return 3 * f((x + 1) / 2) - 1;
    else                return 3 * f(x / 2) - 1;
}

int main() {
    int x;
    cin >> x;
    cout << f(x);
    return 0;
}