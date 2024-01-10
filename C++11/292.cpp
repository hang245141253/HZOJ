#include <algorithm>
#include <iostream>

using namespace std;

const int N = 9;
int row[N], col[N], cell[3][3]; // 行、列、九宫格 
char str[86];  // 81个字符 + 5
int ones[1 << N]; // 打表存下标的数对应有几个二进制的1，范围0~9
int map[1 << N];  // 1->1   10->2   100->3等

// 1 找到一个整数x的二进制表示中最低位的1所代表的值
inline int lowbit(int x) {
    return x & -x;
}

// 2
void init() {
    for (int i = 0; i < N; i++) 
        row[i] = col[i] = (1 << N) - 1; // 511 = 1 1111 1111，默认每个1-9都能用
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++)
            cell[i][j] = (1 << N) - 1;  // 511 = 1 1111 1111
    return;
}

// 3 求可选方案的交集，配合ones数组使用
inline int get(int x, int y) {
    return row[x] & col[y] & cell[x / 3][y / 3];
}


// 4 true找到答案，false没找到答案
bool dfs(int cnt) {
    if (!cnt) return true;

    // 剪枝1 找出可选方案数最少的空格
    int minv = 10; // 最多9个二进制1，所以初始化为10
    int x, y;      // 记录待搜索.的坐标
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            if (str[i * 9 + j] == '.') {
                int t = ones[get(i, j)];
                if (t < minv) 
                    minv = t, x = i, y = j;
            }

    // 枚举x y这个格子
    for (int i = get(x, y); i; i -= lowbit(i)) {
        int t = map[lowbit(i)];   // 枚举可用的数字

        // 修改状态
        row[x] -= 1 << t;
        col[y] -= 1 << t;
        cell[x / 3][y / 3] -= 1 << t;
        str[x * 9 + y] = '1' + t;

        if (dfs(cnt - 1))  return true;

        // 恢复现场
        row[x] += 1 << t;
        col[y] += 1 << t;
        cell[x / 3][y / 3] += 1 << t;
        str[x * 9 + y] = '.';
    }

    return false;
}


// 0
int main(int argc, char const *argv[]) {
    for (int i = 0; i < N; i++) map[1 << i] = i;
    for (int i = 0; i < (1 << N); i++) {
        int s = 0;
        for (int j = i; j; j -= lowbit(j))  s++;
        ones[i] = s; // i的二进制表示中有s个1
    }

    while (cin >> str, str[0] != 'e') {
        init();

        int cnt = 0; // 统计可以填的数，倒着搜用
        // 把已有的数填入，i j是横纵坐标，k是线性坐标0-80
        for (int i = 0, k = 0; i < N; i++) {
            for (int j = 0; j < N; j++, k++) {
                if (str[k] != '.') {
                    int t = str[k] - '1'; // 字符‘1’~‘9’ 映射到 整型0-8
                    // 在1 1111 1111中去掉已有的数
                    row[i] -= 1 << t;
                    col[j] -= 1 << t;
                    cell[i / 3][j / 3] -= 1 << t;
                }
                else cnt++;
            }
        }
        dfs(cnt);
        cout << str << endl;
    }
    return 0;
}
