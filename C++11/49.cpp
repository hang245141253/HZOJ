/*************************************************************************
	> File Name: 49.cpp
	> Author: YuHang
	> Mail: hang245141253@gmail.com
	> Created Time: Fri Nov 10 15:51:28 2023
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 100
int v[MAX_N + 5];
int w[MAX_N + 5];
int s[MAX_N + 5];
int dp[MAX_N + 5][100005];
int dp2[100005];


/*
    多重背包：
    第1种物品有3个 <==> 有3个第1种物品(0, 1背包)


*/

void one() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i] >> s[i];
    }
    
    // 枚举物品
    for (int i = 1; i <= n; i++) {
        // 枚举包
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            // 种类数不能超过s[i] 并且 个数不能超过包容量
            for (int k = 1; k <= s[i] && j >= w[i] * k; k++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i] * k] + v[i] * k);
            }
        }
    }

    cout << dp[n][m];
}

void two() {
    int m, n;
    cin >> m >> n;
    // 枚举物品
    for (int i = 1; i <= n; i++) {
        int w, v, s;
        cin >> w >> v >> s;
        // 把多重当01背包
        for (int k = 1; k <= s; k++) {
            // 枚举包(01背包倒着遍历)
            for (int j = m; j >= w; j--) {
                dp2[j] = max(dp2[j], dp2[j - w] + v);
            }
        }
    }
    cout << dp2[m];
}

void binary() {
    int m, n;   
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int w, v, s;
        cin >> w >> v >> s;
        for (int k = 1; s > 0; k <<= 1, s -= k) {
            k = min(k, s);
            for (int j = m; j >= w * k; j--) {
                dp2[j] = max(dp2[j], dp2[j - w * k] + v * k);
            }
        }
    }
    cout << dp2[m];
}

int main() {
    //one();
    //two();
    binary();
    return 0;
}
