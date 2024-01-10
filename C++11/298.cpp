#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_N 65
int n;
int sum;     // 总棍长
int length;  // 单个大棍长

// 为什么开short数组？ 因为C++14的short数组莫名的快
short a[MAX_N + 5];
short flag[MAX_N + 5];  // 标记小棍是否被使用

// 第cnt大棍数， 当前大棍长度crt_len， 小棍下标start
bool dfs(int cnt, int crt_len, int strat) {
    if (cnt * length == sum)    return true;                // 大棍数*大棍长 = 总长：找到了解                                                                                                                                                                                     
    if (crt_len == length)      return dfs(cnt + 1, 0, 0);  // 当前大棍组装好了，拼新的大棍

    // 从当前大棍中枚举小棍
    for (int i = strat; i < n; i++) {
        // 剪枝4-1(按照组合数方式枚举)
        if (flag[i])                    continue;  // 小棍已经被用过了，不能再用
        if (crt_len + a[i] > length)    continue;  // 剪枝1 可行性剪枝(组装大棍时超过枚举大棍长度了)

        flag[i] = true;
        if (dfs(cnt, crt_len + a[i], i + 1))    return true;  // 要知道下一次拼接的小棍是true，才能确定本次拼接的小棍是可行的
        // 代码能走到这里的话，说明下一次拼接小棍肯定不可行，所以本次拼接肯定不可行
        flag[i] = false;  // 回溯

        // 剪枝4-3(如果小棍拼接的是大棍中第一个时失败，则一定失败):保证字典序，否则可能会提前搜到部分大棍答案，到最后会被推翻重新排。冗余
        if (!crt_len)                           return false;
    
        // 剪枝4-4(如果小棍拼接的是大棍中最后一个时失败，则一定失败),因为再往后枚举，枚举到的肯定是比它更小拼成它这个长度的棍，但实际上这个长度是不能被需要的，不然这个小棍会被后面的大棍所用，等长实际上是可以互换的。所以冗余。
        if (crt_len + a[i] == length)           return false;

        // 剪枝4-2(如果当前小棍拼接失败，略过后面所有长度相等的木棍)
        int j = i;
        while (j < n && a[j] == a[i]) j++;
        i = j - 1;
    }

    return false; // 没有能用的小棍了
}

int main() {
    while (scanf("%d", &n), n != 0) {
        sum = length = 0;
        memset(a, 0, sizeof(a));
        memset(flag, 0, sizeof(flag));

        for (int i = 0; i < n; i++) scanf("%hd", &a[i]), sum += a[i];

        // 剪枝3 优化搜索顺序
        sort(a, a + n);
        reverse(a, a + n);

        length = 1;  // 大棍长从1开始枚举
        while (length <= sum) {
            // 剪枝1 可行性优化
            if (sum % length == 0 && dfs(0, 0, 0)) {
                printf("%d\n", length);
                break;  // 相当于剪枝2，最优性优化，因为第一次输出的长度必定是最短的
            }
            length++;
        }
    }
    return 0;
}