/*************************************************************************
	> File Name: 559.cpp
	> Author: YuHang
	> Mail: hang245141253@gmail.com
	> Created Time: Wed Oct 25 17:35:51 2023
 ************************************************************************/

#include <iostream>
using namespace std;

int dp[1005], s[1005], f[1005];

int main() {
    int M, N;
    cin >> M >> N;
    for (int i = 1; i <= N; i++) {
        cin >> s[i] >> f[i];
        for (int j = M; j >= f[i]; j--) {
            dp[j] = max(dp[j], dp[j - f[i]] + s[i]);
        }
    }
    cout << dp[M];
    return 0;
}
