#include <iostream>

using namespace std;

int main() {
    int x, b, n, g;
    cin >> x >> b >> n >> g;

    if ((b <= 50 || x >= 1) && (n <= 25 || g >= 5)) cout << "ok" << endl;
    else cout << "pass" << endl;

    return 0;   
}