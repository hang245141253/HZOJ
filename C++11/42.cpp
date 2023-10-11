/*************************************************************************
	> File Name: 42.cpp
	> Author: YuHang
	> Mail: hang245141253@gmail.com
	> Created Time: Wed Oct 11 18:29:22 2023
 ************************************************************************/

#include <iostream>
using namespace std;

int val[25];
int f[25][10005];

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)    cin >> val[i];
    for (int i = 1; i <= m; i++) {
        f[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= val[i]) f[i][j] += f[i][j - val[i]];
            f[i][j] %= 9973;
        }
    }
    cout << f[m][n];
    return 0;
}
