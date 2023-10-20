/*************************************************************************
	> File Name: 560.cpp
	> Author: YuHang
	> Mail: hang245141253@gmail.com
	> Created Time: Fri Oct 20 15:08:32 2023
 ************************************************************************/

#include <iostream>
using namespace std;

int dp[30005];

int main() {
    int n, m, v, p;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> v >> p;
        for (int j = n; j >= v; j--) {
            dp[j] = max(dp[j], dp[j - v] + v * p);
        }
    }
    cout << dp[n];
    return 0;
}
