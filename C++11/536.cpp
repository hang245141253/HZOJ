/*************************************************************************
	> File Name: 536.cpp
	> Author: YuHang
	> Mail: hang245141253@gmail.com
	> Created Time: Fri Nov 24 09:29:14 2023
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, m, big, ans = 1;
char map[105][105];

int dir[4][2] = {
    0, 1,
    1, 0,
    0, -1,
    -1, 0
};

void dfs(int x0, int y0) {
    for (int i = 0; i < 4; i++) {
        int x = x0 + dir[i][0];
        int y = y0 + dir[i][1];
        if (map[x][y] == '1') {
            map[x][y] = '0';
            ans++;
            dfs(x, y);
        }
    }
    return ;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == '1') {
                map[i][j] = '0';
                dfs(i, j);
                big = max(big, ans);
                ans = 1;
            }
        }
    }
    cout << big << endl;
    return 0;
}
