#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int f[n + 1] = {0, 1, 1};
    const int x = 1000000007;
    for (int i = 3; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % x;
    }

    cout << f[n] << endl;
    return 0;
}