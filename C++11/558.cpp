/*************************************************************************
	> File Name: 558.cpp
	> Author: YuHang
	> Mail: hang245141253@gmail.com
	> Created Time: Fri Oct 20 15:00:13 2023
 ************************************************************************/

#include <iostream>
using namespace std;

int dp[1005];

int main() {
    int T, M, t, c;
    cin >> T >> M;
    for (int i = 1; i <= M; i++) {
        cin >> t >> c;
        for (int j = T; j >= t; j--) {
            dp[j] = max(dp[j], dp[j - t] + c);
        }
    }
    cout << dp[T];
    return 0;
}
