#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a <= c && d <= b) || (c <= a && b <= d)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;   
}