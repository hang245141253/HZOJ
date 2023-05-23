#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.14;

double S(double r, double h) {
    double DI = (PI + 4) * r * r;
    double CE = (PI * r + 2 * r + sqrt(8 * r * r)) * h;
    return DI + CE;
}

int main() {
    double r, h;
    cin >> r >> h;
    cout << fixed << setprecision(2) << S(r, h) << endl;

    return 0;
}