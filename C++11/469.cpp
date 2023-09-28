/*************************************************************************
	> File Name: code/HZOJ/C++11/469.cpp
	> Author: YuHang
	> Mail: hang245141253@gmail.com
	> Created Time: Thu Sep 28 11:21:51 2023
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x, n, ans = 0;
    cin >> x >> n;

    int bit = 1;
    while (n) {
        ans += n % 10 * bit;
        n /= 10;
        bit *= x;
    }

    cout << ans << endl;
    return 0;
}
