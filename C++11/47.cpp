/*************************************************************************
	> File Name: 47.cpp
	> Author: YuHang
	> Mail: hang245141253@gmail.com
	> Created Time: Thu Oct 19 18:37:05 2023
 ************************************************************************/

#include <iostream>
using namespace std;

// #define MAX_N 100
#define MAX_V 10000

// int dp[MAX_N + 5][MAX_V + 5];
// int dp[2][MAX_V + 5];  // 因为下一行只与上一行有关，因此3行数组来回滚动
int dp[MAX_V + 5]; // 只留一行，重复滚动利用

int main() {
    int V, n, v, w; // V最大承重 n物品数 v某件物品重量 w某件物品价值
    cin >> V >> n;
//    for (int i = 1; i <= n; i++) {
//        cin >> v >> w;
//        for (int j = 1; j <= V; j++) {
//            dp[i][j] = dp[i - 1][j];  // 最起码等于不放的价值
//            if (j >= v) dp[i][j] = max(dp[i][j], dp[i - 1][j - v] + w);
//        }
//    }
//    cout << dp[n][V];

//    for (int i = 1; i <= n; i++) {
//        cin >> v >> w;
//        for (int j = 1; j <= V; j++) {
//            dp[i % 2][j] = dp[(i - 1) % 2][j];  // 最起码等于不放的价值
//            if (j >= v) dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j - v] + w);
//        }
//    }
//    cout << dp[n % 2][V];
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        for (int j = V; j >= v; j--) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[V];
    return 0;
}
