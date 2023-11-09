/*************************************************************************
	> File Name: 356.cpp
	> Author: YuHang
	> Mail: hang245141253@gmail.com
	> Created Time: Thu Nov  9 13:59:10 2023
 ************************************************************************/

#include <iostream>
using namespace std;

#define N 300

int s[N + 5];
int dp[N + 5][N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)    cin >> s[i], s[i] += s[i - 1];
    // 枚举区间长度
    for (int len = 2; len <= n; len++) {
        // 区间长度为len时，能枚举的**次数**
        for (int cnt = 1; cnt <= n - len + 1; cnt++) {
            int l = cnt, r = cnt + len - 1; //  头尾指针
            // 在每一个小区间中 动规出 大区间的最优值
            dp[l][r] = 0x7fffffff;
            for (int k = l; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}
