#include <iostream>
using namespace std;

int n, ans;
int num[25];
bool flag[25 * 25] = {1};

void dfs(int p, int sum) {
    if (!flag[sum]) {
        ans++;
        flag[sum] = 1;
    }

    for (int i = p; i < n; i++) {
        sum += num[i];
        dfs(i + 1, sum);
        sum -= num[i];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}
