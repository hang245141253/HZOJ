#include <iostream>
#include <queue>
using namespace std;

struct node {
    int idx, cnt;
};

int n, x, y;
int a[105][105], vis[105];
queue<node> q;

int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    q.push({x, 0});

    while (!q.empty()) {
        node tmp = q.front();
        q.pop();

        for (int j = 1; j <= n; j++) {
            if (a[tmp.idx][j] && !vis[j]) {
                if (j == y) {
                    cout << tmp.cnt;
                    return 0;
                }
                q.push({j, tmp.cnt + 1});
                vis[j] = 1;
            }
        }
    }

    return 0;
}
