/*************************************************************************
	> File Name: 48.cpp
	> Author: YuHang
	> Mail: hang245141253@gmail.com
	> Created Time: Wed Oct 25 16:23:39 2023
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 10000

int dp[MAX_N + 5];
int dp1[10005][10005];
void MLE_GG();

int main() {
    int N, V, c, v;
    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        cin >> c >> v;
        for (int j = c; j <= V; j++) {
            dp[j] = max(dp[j], dp[j - c] + v);
        }
    }
    cout << dp[V];
    return 0;
}

void MLE_GG() {
    int V, n;
    cin >> n >> V;
    for (int i = 1, v, w; i <= n; i++) {
        cin >> w >> v;
        for (int j = 1; j <= V; j++) {
            if (j < w)  // 不放，同0 1背包
                dp1[i][j] = dp1[i - 1][j];
            else        // 放，从前一种 和 当前更新过的位置 打擂台
                dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - w] + v);
        }
    }
    cout << dp1[n][V]; 
}
