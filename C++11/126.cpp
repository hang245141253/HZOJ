#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double r1, r2;
    const double PI = 3.14;
    cin >> r1 >> r2;

    cout << fixed << setprecision(2) << PI * r1 * r1 - PI * r2 * r2 << endl;

    return 0;
}