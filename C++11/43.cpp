#include <iostream>
using namespace std;
#define MAX_N 1000

int f[MAX_N + 5][MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<= i; j++) {
            cin >> f[i][j];
        }
    }

    // 反序
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            f[i][j] += max(f[i + 1][j], f[i + 1][j + 1]); 
        }
    }
    // 正序（麻烦，没有实现完）
    /*  
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            // 有问题，往上找不一定有点j、j-1，需要额外判断边界
            f[i][j] += max(f[i - 1][j], f[i - 1][j - 1]); 
        }
    }
    */
    cout << f[1][1] << endl;

    return 0;
}

/*
6
3
9 5
4 2 1
3 4 9 6
3 5 3 7 3
2 1 3 9 3 2
*/