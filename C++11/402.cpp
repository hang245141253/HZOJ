/*************************************************************************
	> File Name: code/HZOJ/C++11/402.cpp
	> Author: YuHang
	> Mail: hang245141253@gmail.com
	> Created Time: Thu Sep 28 10:27:33 2023
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

int n, a, b;
int k[205];
int flag[205];
queue<int> q;

void go(int nx, int x) {
    if (nx < 1 || nx > n || flag[nx])   return ;
    q.push(nx);
    flag[nx] = flag[x] + 1;
    return ;
}

int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }

    q.push(a);
    flag[a] = 1;

    while (!q.empty()) {
        int idx = q.front();

        if (idx == b) {
            cout << flag[idx] - 1;
            return 0;
        }
        q.pop();

        go(idx + k[idx], idx);
        go(idx - k[idx], idx);
    }
    cout << -1;
    return 0;
}
