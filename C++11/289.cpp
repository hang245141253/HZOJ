#include <iostream>
using namespace std;

/**
 * 不能排序
 * 
 * 分析样例 2 -3 2 -1 2  答案5是(选2和 2 -1 2)
 * 
 * 1，将原序列合并成是正负交替的序列
 * 如序列 1，1，-3，-2，2，3，-1，1
 * 合并成 2，-5，5，-2这样
 * 后面都基于2，-5，5，-2这样的正负交替序列讨论
 * 
 * 2，正负交替序列中，分情况讨论：
 * 正数的个数C <= 可选择连续部分M
 * 因为题目说选不超过M个，所以 <= M时只需要把所有正数选择即可
 * 
 * 正数的个数C > 可选择连续部分M。这个情况是需要重点考虑的
 * 设正数个数C个，和为S，C > M。 考虑如何减少正数的个数（还不能影响正负交替），并分析对于S的影响。
 * 每次减少1个正数的情况：
 * 情况1： -x y -z    合并完是负数
 * 情况2：  x -y z    合并完是正数
 * 经过观察发现：无论情况1、2，y的绝对值最小的时候就可以满足
 * 所以每次选择一个y的绝对值最小的并掉，这样最终剩下的S才是最大的。
 * 
 * 
 * 所以解法是：按照元素绝对值从小到大，依次消除每个元素，剩余的和值S即为结果
 * 
 * 
 * 具体编码的时候，需要三个元素合并成一个
 * 思考什么样的数据结构更方面进行删除操作：线性结构的：链表
 * 
 * 编码：
 * 1.先预处理数据成正负交替的数据(判断输入数据与前一个值是否同号 )
 * 
*/

#include <set>
#define MAX_N 100000
long long arr[MAX_N + 5];
int l[MAX_N + 5], r[MAX_N + 5]; // 双向链表

typedef pair<int, int> PII; // first存绝对值 second存arr节点下标
set<PII> h;     // 小顶堆

int st[MAX_N + 5]; // 标记节点是否被删除
void del(int x) {
    r[l[x]] = r[x]; // l[x]的r = r[x]
    l[r[x]] = l[x]; // r[x]的l = l[x]
    st[x] = 1; // 标记为1表示节点被删除
}


int main() {
    int n, m, k = 1; // k是遍历arr用的数组下标
    scanf("%d%d", &n, &m);
    scanf("%lld", arr + 1); // 先把第一个值存到arr[1]
    for (int i = 1, a; i < n; i++) {
        scanf("%d", &a);
        if (arr[k] * a < 0LL) arr[++k] =a;
        else arr[k] += a;
    }
    int cnt = 0, S = 0;
    n = k; // 更新合并后元素的数量
    for (int i = 1; i <= n; i++) {
        if (arr[i] > 0) { 
            cnt += 1;     // 统计正数个数
            S += arr[i];  // 累计所有正数的和
        }

        // 建立双向链表 保留arr[0]就是为了建立双向链表方便
        l[i] = i - 1;
        r[i] = i + 1;

        // 维护一个绝对值小顶堆
        h.insert(PII(abs(arr[i]), i));
    }

    while (cnt > m) {
        while (st[h.begin()->second]) h.erase(h.begin()); // 如果节点被删除直接擦除
        int idx = h.begin()->second;
        h.erase(h.begin());
        int left = l[idx], right = r[idx];
        if ((left > 0 && right <= n) || arr[idx] > 0) { // arr[idx] > 0 因为要去掉正数才会让S减少，去掉负数没意义
            S -= abs(arr[idx]);
            cnt -= 1;
            arr[idx] += arr[left] + arr[right];
            h.insert(PII(abs(arr[idx]), idx));
            del(left);
            del(right);
        }
    }

    printf("%lld\n", S);
    
    return 0;
}