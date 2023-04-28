#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int m, n;
    double sum = 0;
    double li = 0.00417;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        sum = (m + sum) * (1 + li);
    }
    cout << "$" << fixed << setprecision(2) << sum << endl;
    return 0;   
}