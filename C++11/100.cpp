#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    double sum = 0;
    double li = 0.00417;
    cin >> n;
    for (int i = 1; i <= 6; i++) {
        sum = (n + sum) * (1 + li);
    }
    cout << "$" << fixed << setprecision(2) << sum << endl;
    return 0;   
}