#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

#define MAX_M 100
#define MAX_N 1000

// 坐标、价值、上一个格子颜色
struct node {
    int x, y, cost, last;
};

/* 难点：思考如何每个格子的状态
    按位存储last
    0：000 表示无色
    1：001 第一个0表示未使用魔法 01表示黄色
    2：010 第一个0表示未使用魔法 10表示红色
    3：011 未使用该状态
    4：100 未使用该状态
    5：101 第一个1表示使用了魔法 01表示黄色
    6：110 第一个1表示使用了魔法 10表示红色

    总之，第二位的0表示未使用魔法，1表示使用魔法
    第零位和第一位用来表示黄色或红色
*/

queue<node> que;

int m, n;
int mmap[MAX_M + 5][MAX_M + 5];
int vis[MAX_M + 5][MAX_M + 5];
int dir[4][2] = {1, 0,
                 0, 1,
                 -1, 0,
                 0, -1};

int main() {
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        mmap[x][y] = z + 1;  // 0无色、1红色、2黄色
    }

    // vis存每个格子的最小价值，初始化一个极大值
    memset(vis, 0x3f, sizeof(vis));

    // 起点进队列
    que.push({1, 1, 0, mmap[1][1]});

    while (!que.empty()) {
        node tmp = que.front();
        que.pop();

        // 搜到(m, m)出口
        if (tmp.x == m && tmp.y == m) {
            vis[m][m] = min(vis[m][m], tmp.cost);
            continue;
        }

        // 防止重复搜索，同时实现最优性剪枝
        if (tmp.cost < vis[tmp.x][tmp.y]) 
            vis[tmp.x][tmp.y] = tmp.cost;
        else
            continue;

        // 四个方向搜索
        for (int i = 0; i < 4; i++) {
            int x = tmp.x + dir[i][0];
            int y = tmp.y + dir[i][1];

            // 判断边界
            if (x < 1 || y < 1 || x > m || y > m) continue;

            // 不能连续使用魔法
            if (tmp.last & 0b100 && mmap[x][y] == 0) continue;

            // 搜的点分两种情况：有颜色、无颜色
            if (mmap[x][y]) {
                // 搜的地方有颜色，颜色是和上一次颜色相同cost+0(false)，不同cost+1(true)
                que.push({x, y, tmp.cost + ((tmp.last & 0b011) != mmap[x][y]), mmap[x][y]});
            } else {
                // 搜的地方没有颜色，使用魔法：分别考虑变红、变黄（上一次颜色相同cost+0(false)，不同cost+1(true)）
                que.push({x, y, tmp.cost + 2 + (tmp.last != 0b001), 0b101}); // 变红
                que.push({x, y, tmp.cost + 2 + (tmp.last != 0b010), 0b110}); // 变红
            }
        }
    }

    cout << (vis[m][m] == 0x3f3f3f3f ? -1 : vis[m][m]);

    return 0;
}