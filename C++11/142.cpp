#include <iostream>

using namespace std;

int zhishu(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int huiwen(int x) {
    int g = x % 10;
    int s = x / 10 % 10;
    int q = x / 1000 % 10;
    int w = x / 10000;
    if (g==w && s==q)   return 1;
    return 0;
}

int main() {
    int a, b;
    cin >> a >> b;
    for ( ; a <= b; a++) {
        if (zhishu(a) && huiwen(a)) {
            cout << a;
            break;
        }
    }
    for (a++ ; a <= b; a++) {
        if (zhishu(a) && huiwen(a)) cout << " " << a;
    }
    return 0;   
}