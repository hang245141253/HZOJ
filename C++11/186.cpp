#include <iostream>
using namespace std;

/*
0.语义信息: f(n)表示, 对数组arr第n位开始往后递归
1.递推公式为: f(n) = f(n + arr)
2.边界条件: arr[n] == 0
3.返回结果: count
*/
int f(int n, int* arr, int* count) {
    if (arr[n] == 0) return *count;
    else {
        (*count)++;
        return f(n + arr[n], arr, count);
    }
}

int main() {
    int n, count = 0;;
    cin >> n;
    int *arr = new int[n + 100]();
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // 传入arr下标0，而非传入arr[0]本身的值
	cout << f(0, arr, &count) << endl;

    return 0;
}