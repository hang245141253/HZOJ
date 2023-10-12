/*************************************************************************
	> File Name: 44.cpp
	> Author: YuHang
	> Mail: hang245141253@gmail.com
	> Created Time: Thu Oct 12 14:13:27 2023
 ************************************************************************/

#include <iostream>
using namespace std;

int a[1000005];
int dp[1000005];
int len[1000005], ans = 0;

int bs(int* arr, int l, int r, int x) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (arr[mid] < x)   return bs(arr, mid + 1, r, x);
    return bs(arr, 1, mid, x);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 1;
        len[i] = n + 1; // 初始化一个最大值
    }

    len[++ans] = a[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = bs(len, 1, ans + 1, a[i]); // 二分找最大index
        len[dp[i]] = a[i];
        ans = max(ans, dp[i]);             // 只有大的dp[i]才会ans++
    }
    cout << ans << endl;
    return 0;
}
