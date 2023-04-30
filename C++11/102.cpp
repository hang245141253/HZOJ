#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a, b, c, t;
    cin >> a >> b >> c >> t;

    double t1 = (1 - (1 / a + 1 / b) * t) / (1 / a + 1 / b - 1 / c);
    cout << fixed << setprecision(2) << t + t1 << endl;

    return 0;
}