/*************************************************************************
	> File Name: 398.cpp
	> Author: YuHang
	> Mail: hang245141253@gmail.com
	> Created Time: Fri Sep 22 09:28:08 2023
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, step;
};

int n, m;
int mmap[405][405];
queue<node> q;

int dir[8][2] = {
    2, 1,
    2, -1,
    1, -2,
    -1, -2,
    -2, -1,
    -2, 1,
    -1, 2,
    1, 2,
};

int main() {
    int x0, y0;
    cin >> n >> m >> x0 >> y0;
    q.push({x0, y0, 0});
    
    while (!q.empty()) {
        node tmp = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int x = tmp.x + dir[i][0];
            int y = tmp.y + dir[i][1];
            if (x < 1 || x > n || y < 1 || y > m) continue;
            if (!mmap[x][y]) {
                q.push({x, y, tmp.step + 1});
                mmap[x][y] = tmp.step + 1;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j != 1) cout << " ";
            if (!mmap[i][j])   mmap[i][j] = -1;
            if (i == x0 && j == y0)  mmap[i][j] = 0;
            cout << mmap[i][j];
        } putchar('\n');
    }
	return 0;
}
