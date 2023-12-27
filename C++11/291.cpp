#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_N 18

int N, W, ans;
int cat[MAX_N + 5];  // 猫重量
int car[MAX_N + 5];  // 缆车当前载重

void dfs(int id, int cnt) {     // id猫编号、cnt缆车编号
    if (cnt >= ans)    return;  // 最优性剪枝
    if (id == N) {
        ans = cnt;
        return;  // 出口
    }

    for (int i = 0; i < cnt; i++) {
        if (cat[id] + car[i] > W)    continue;  // 可行性剪枝
        car[i] += cat[id];
        dfs(id + 1, cnt);
        car[i] -= cat[id];
    }
    // 新开一辆车
    car[cnt] = cat[id];
    dfs(id + 1, cnt + 1);
    car[cnt] = 0;

    return;
}

int main() {
    cin >> N >> W;
    ans = N;  // 顶多1猫1车
    for (int i = 0; i < N; i++) cin >> cat[i];
    // 优化搜索顺序
    sort(cat, cat + N);
    reverse(cat, cat + N);
    dfs(0, 0);
    cout << ans << endl;

    return 0;
}