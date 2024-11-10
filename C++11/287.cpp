#include <iostream>
#include <set>
using namespace std;

/**
 * 很容易想到从小往大了合并的话是最节约体力的
 * 
*/

typedef pair<int, int> PII;

int main() {
    int n;
    set<PII> s;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        s.insert(PII(a, i));
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int a = s.begin()->first;
        s.erase(s.begin());
        int b = s.begin()->first;
        s.erase(s.begin());
        ans += a + b;
        s.insert(PII(a + b, n + i));
    }
    printf("%d", ans);
    return 0;
}