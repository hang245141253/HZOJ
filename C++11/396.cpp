/*************************************************************************
	> File Name: code/HZOJ/C++11/396.cpp
	> Author: YuHang
	> Mail: hang245141253@gmail.com
	> Created Time: Wed Sep 27 17:19:27 2023
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct coord {
    int x, y;
};

int n;
int mmap[35][35];
int dir[4][2] = {
    1, 0,
    0, 1,
    0, -1,
    -1, 0
};
queue<coord> q;


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mmap[i][j];
        }
    }

    q.push({0, 0});
    mmap[0][0] = 2;

    while (!q.empty()) {
        coord tmp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = tmp.x + dir[i][0];
            int ny = tmp.y + dir[i][1];
            // 不n + 1则边界0只有一半
            if (nx < 0 || ny < 0 || nx > n + 1 || ny > n + 1) continue;
            if (!mmap[nx][ny]) {
                mmap[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            (j != 1) && putchar(' ');
            if (mmap[i][j] == 2) mmap[i][j] = 0;
            else if (!mmap[i][j]) mmap[i][j] = 2;
            printf("%d", mmap[i][j]);
        } putchar('\n');
    }

    return 0;
}
