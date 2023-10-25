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
