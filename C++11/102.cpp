#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a, b, c, t;
    cin >> a >> b >> c >> t;

    double t1 = (1 - (1 / (double)a + 1 / (double)b) * t) / (1 / (double)a + 1 / (double)b - 1 / (double)c);
    cout << fixed << setprecision(2) << (double)t + t1 << endl;

    return 0;   
}