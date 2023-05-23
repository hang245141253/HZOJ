#include <iostream>
#define m a[0]
using namespace std;

int main() {
    int k, a[11];
    cin >> k >> m;
    for (int i = 1; i < 11; i++) {
        cin >> a[i];
    }

    int *f = new int[k + 1]();
    for (int x = 1; x < k + 1; x++) {
        if (x < 10) f[x] = x;
        else f[x] = (a[1] * f[x - 1] + a[2] * f[x - 2] + a[3] * f[x - 3] + a[4] * f[x - 4] + a[5] * f[x - 5] + a[6] * f[x - 6] + a[7] * f[x - 7] + a[8] * f[x - 8] + a[9] * f[x - 9] + a[10] * f[x - 10]) % m;
    }

    cout << f[k] << endl;
    

    return 0;
}