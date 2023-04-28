#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double r;
    const double PI = 3.14;
    cin >> r;

    cout << fixed << setprecision(2) << 2 * PI * r << endl;
    cout << fixed << setprecision(2) << PI * r * r << endl;

    return 0;
}