#include <iostream>
using namespace std;

int val[10][10];
short row[10], col[10], cell[10]; // 行 列 九宫格的集合
int ans = -1; // 如果找不到解直接就-1

// init 把已有的数字从集合中标记掉/标记回
void init(int i, int j, int x) {
    row[i] ^= (1 << x);
    col[j] ^= (1 << x);
    cell[i / 3 * 3 + j / 3] ^= (1 << x);
    return ;
}

// 求x内二进制1的数量
int count_one(int x) {
    int cnt = 0;
    while (x) 
        x &= (x - 1), cnt += 1;
    return cnt;
}

void dfs(int cnt) {
    // 出口
    if (cnt == 0) {
        int tmp = 0; // 求得分
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // 格子数字 * 得分权重
                tmp += val[i][j] * (10 - max(abs(i - 4), abs(j - 4))); // (中心点坐标的分值 - 与中心点的偏移量) 
            }
        }
        ans = max(ans, tmp);
        return ;
    }

    // 找可填数最少状态的点
    int x, y, minn = 10; // minn表示 (x, y)可取数字的数量，初始化为无限大10
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (val[i][j]) continue;
            int num = 9 - count_one(~(row[i] & col[j] & cell[i / 3 * 3 + j / 3]));  // r & c & cell是可用的数字，~后是不可用，9-不可用 = 可用，还去除的无效数位
            if (num < minn)   minn = num, x = i, y = j;
        }
    }

    // 已经找到了点，准备开搜 z是九宫格坐标
    for (int k = 1, z = x / 3 * 3 + y / 3; k <= 9; k++) {
        int kk = (1 << k);
        if ((row[x] & kk) && (col[y] & kk) && (cell[z] & kk)) { // 成立说明k值可以被填充
            init(x, y, k); // 标记掉
            val[x][y] = k;
            dfs(cnt - 1);
            val[x][y] = 0;
            init(x, y, k); // 标记回
            // 异或运算与本身就是互为逆运算
        }
    }

    return ;
}

int main() {
    int cnt = 0;
    for (int i = 0; i < 9; i++) row[i] = col[i] = cell[i] = -1; // 集合初始化为1111 11(11 1111 111)1, 只用到1-9位
    
    // 输入数独初始状态
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> val[i][j];
            if (val[i][j]) {
                init(i, j, val[i][j]);  // 标记掉已经用了的数字
            } else 
                cnt++;
        }
    }
    dfs(cnt);
    cout << ans << endl;
    return 0;
}