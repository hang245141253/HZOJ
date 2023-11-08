/*************************************************************************
	> File Name: 562.cpp
	> Author: YuHang
	> Mail: hang245141253@gmail.com
	> Created Time: Wed Nov  8 11:24:44 2023
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0, tmp; i < n; i++) {
        cin >> tmp;
        ans ^= tmp;
    }
    cout << ans;
    return 0;
}
