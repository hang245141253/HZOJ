#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    int tmp;
    while (!q.empty()) {
        tmp = q.front();
        for (int i = 1; i <= m; i++) {
            if (i != m) q.push(q.front());
            q.pop();
        } 
    }

    cout << tmp;

    return 0;
}
