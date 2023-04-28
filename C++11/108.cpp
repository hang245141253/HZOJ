#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char ch;
    cin >> ch;
    double m, n;
    cin >> m >> n;

    if (ch == 'r') cout << fixed << setprecision(2) << m * n << endl;
    else cout << fixed << setprecision(2) << m * n / 2 << endl;

    return 0;   
}