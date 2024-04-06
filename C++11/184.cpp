#include <iostream>
using namespace std;

// F(N)表示，几个挑子能吃n天，不要被题目中的第几天迷惑
int peach(int day) {
    if (day == 1)   return 1; // 剩下一个肯定只能吃1天 就是边界条件
    return (peach(day - 1) + 1) * 2; // 重点考虑n天和n - 1天之间的联系
}

// 想不出联系可以代数，比如一开始有个10个果子，第一天吃完还剩下10 / 2 - 1 = 4个
// 递的递是假设已知了后面一天剩几个，所以4个是已知的
// 考虑怎么拿公式从4 也就是(n - 1)天推到n天，也就是(4 + 1) * 2 即递归公式

int main() {
    int n;
    cin >> n;
    cout << peach(n);
    return 0;
}