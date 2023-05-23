#include <iostream>

using namespace std;

bool zhishu(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (!(x % i)) return false;
    }
    return true;
}

bool huiwen(int x) {
    if (__builtin_expect(!!(x < 0), 0)) return false;
    int y = 0, z = x;
    while (x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return z == y;
}

int main() {
    int a, b;
    cin >> a >> b;
    for ( ; a <= b; a++) {
        if (zhishu(a) && huiwen(a)) {
            cout << a;
            break;
        }
    } // 继续刚才的循环
    for (a++ ; a <= b; a++) {
        if (zhishu(a) && huiwen(a)) cout << " " << a;
    }

    return 0;   
}