#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a, b, c, t;
    cin >> a >> b >> c >> t;

    double t1 = (1.0 - (1.0 / a + 1.0 / b) * t) / (1.0 / a + 1.0 / b - 1.0 / c);
    cout << fixed << setprecision(2) << t + t1 << endl;

    return 0;
}