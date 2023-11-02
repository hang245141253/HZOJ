/*************************************************************************
	> File Name: 688.cpp
	> Author: YuHang
	> Mail: hang245141253@gmail.com
	> Created Time: Thu Nov  2 10:47:05 2023
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int w[1005];
int v[1005];
int k[105];
int Ki[105][1005]; // 存k组中第x个的物品编号i
int dp[1005];

int main() {
    int m, n, zu = 0;
    cin >> m >> n;
    for (int i = 1, idx; i <= n; i++) {
        cin >> w[i] >> v[i] >> idx;
        zu = max(zu, idx);
        k[idx]++;
        Ki[idx][k[idx]] = i;
    }

    // 枚举组数
    for (int idx = 1; idx <= zu; idx++) {
        // 枚举容量
        for (int j = m; j >= 1; j--) {
            // 枚举每组中每一个元素
            for (int i = 1; i <= k[idx]; i++) {
                if (j >= w[Ki[idx][i]])
                    dp[j] = max(dp[j], dp[j - w[Ki[idx][i]]] + v[Ki[idx][i]]);
            }
        }
    }
    cout << dp[m];
    return 0;
}
