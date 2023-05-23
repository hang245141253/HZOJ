#include <iostream>
#include <cmath>
#include <iomanip>
#define PI acos(-1)
using namespace std;

// c^2 = a^2 + b^2 - 2ab * cosC
// cos()函数采用一个以弧度为单位的强制性参数

double Cosine_Theorem(double a, double b, double C) {
    //将角度转换为弧度
    C = C * PI / 180;
    return sqrt(a * a + b * b - 2 * a * b * cos(C));
}

int main() {
    double a, b, C;
    cin >> a >> b >> C;
    cout << fixed << setprecision(6) << Cosine_Theorem(a, b, C) << endl;

    return 0;
}