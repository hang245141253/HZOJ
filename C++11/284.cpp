#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

/**
 * d是保质期 p是利润
 * 每天只能卖一个，要保证利润最大
 * 1.保质期短的肯定要往前放，先卖掉
 * （按照保质期剩余天数排序，天数相同的话利润大的放前面）
 * 2.维护一个当前最优方案(就按照这个方案一天天的卖货)的集合
 * 111 不可能， 122 也不可能， 123 ok， 133 也ok
 * 得出结论：这个集合 元素的数量n <= 最晚过期商品的日期d
 * 对于每次新商品是否加入集合，考虑新商品的过期日期d'
 * 如果 d' > n 直接加入
 * 如果 d' = n 替换掉利润最小的
 * 如果 d' < n 不可能，排序后不会有这样的结果
 * 书写结构体排序
*/

struct Data {
    int p, d;
} arr[10005];

bool f(Data x, Data y) {
    if (x.d != y.d) return x.d < y.d;
    return x.p > y.p;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].p >> arr[i].d;
    }
    sort(arr, arr + n, f);

    // // print_debug
    // for (int i = 0; i < n; i++) {
    //     printf("[%d] d:%d, p:%d\n", i, arr[i].d, arr[i].p);
    // }

/**
 * 数据已经准备好，思考如何维护这个最优方案集合：
 * 需要操作：
 * 直接加入（添加元素）
 * 比较最小利润商品（查看最小利润商品）
 * 如果比较结果新商品利润更大，删除利润小的添加利润大的（删除元素）
 * 
 * 一眼小顶堆
*/

    typedef pair<int, int> PII;  // 商品利润p,商品编号i
    set<PII> s; // 用set来模拟小顶堆
    for (int i = 0; i < n; i++) {
        if (arr[i].d > s.size())    s.insert(PII(arr[i].p, i));
        else {  // 这里一定是等于的情况，因为小于的情况不存在
            if (arr[i].p > s.begin()->first) {  // 新商品利润更大再替换
                s.erase(s.begin());
                s.insert(PII(arr[i].p, i));
            }
        }
    }

    int ans = 0;
    for (auto x : s) {
        ans += x.first;
    }

    cout << ans << endl;

    return 0;
}