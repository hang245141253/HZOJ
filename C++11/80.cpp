#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y ,cnt;
};

int dir[4][2] = {
    0, 1,
    1, 0,
    0, -1,
    -1, 0
};

int main() {
    int n, m, sx, sy;
    cin >> n >> m;
    char mmap[505][505] = {};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 's') sx = i, sy = j;
        }
    }

    queue<node> q;
    q.push({sx, sy, 0});

    while (!q.empty()) {
        node tmp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x = tmp.x + dir[i][0];
            int y = tmp.y + dir[i][1];
            if (mmap[x][y] == '.') {
                q.push({x, y, tmp.cnt + 1});
                mmap[x][y] = '#';
            }
            if (mmap[x][y] == 'g') {
                cout << tmp.cnt + 1 << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
