/*************************************************************************
	> File Name: code/HZOJ/C++11/565.cpp
	> Author: YuHang
	> Mail: hang245141253@gmail.com
	> Created Time: Thu Sep 28 16:07:04 2023
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = ((n << 16) & 0xffff0000 | ((n >> 16) & 0x0000ffff));
    cout << ans;
    return 0;
}
