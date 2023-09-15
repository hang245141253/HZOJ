#include <iostream>
using namespace std;

int h, w, sx, sy, ans = 1;
char map[55][55];

int dir[4][2] = {
    0, 1,
    1, 0,
    0, -1,
    -1, 0
};

void dfs(int x0, int y0) {
    for (int i = 0; i < 4; i++) {
        int x = dir[i][0] + x0;
        int y = dir[i][1] + y0;
        // if (x < 0 || y < 0 || x > w || y > h) continue; // 如果从0 0开始，需要判断边界
        if (map[x][y] == '.') {
            ans++;
            map[x][y] = '#';
            dfs(x, y);
            // map[x][y] = '.'; // 连通块问题不需要回溯
            // ans--;
        }
    }
}

int main() {
    cin >> h >> w;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            cin >> map[i][j];
            if (map[i][j] == '@')   sx = i, sy = j;
        }
    }

    dfs(sx, sy);

    cout << ans << endl;
    return 0;
}
