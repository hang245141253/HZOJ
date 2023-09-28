/*************************************************************************
	> File Name: code/HZOJ/C++11/304.cpp
	> Author: YuHang
	> Mail: hang245141253@gmail.com
	> Created Time: Wed Sep 27 17:51:44 2023
 ************************************************************************/

#include <iostream>
#include <queue>
#define unlikely(x) __builtin_expect(!!(x), 0)
using namespace std;

struct coord {
    int x, y;
};

int m, n, sx, sy, ex, ey;
int mmap[155][155];
queue<coord> q;
int dir[8][2] = {
    1, 2,
    2, 1,
    -1, 2,
    2, -1,
    1, -2,
    -2, 1,
    -1, -2,
    -2, -1
};

int main() {
    cin >> m >> n;
    char x;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> x;
            if (x == '*')   mmap[i][j] = -1;
            else if (x == 'K')    sx = i, sy = j;
            else if (x == 'H')    ex = i, ey = j;
        }
    }

    q.push({sx, sy});
    mmap[sx][sy] = 1;

    while (!q.empty()) {
        coord tmp = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int x = tmp.x + dir[i][0];
            int y = tmp.y + dir[i][1];
            if (x < 1 || y < 1 || x > n || y > n || mmap[x][y]) continue;
            mmap[x][y] = mmap[tmp.x][tmp.y] + 1;
            if (unlikely(x == ex && y == ey)) {
                printf("%d\n", mmap[x][y] - 1);
                return 0;
            }
            q.push({x, y});
            
        }
    }
    return 0;
}
