#include <iostream>

using namespace std;

int main() {	
	int L, M, count = 0;
	cin >> L >> M;

	// ()初始化为0, +1带上右端点
	int* lrr = new int[L + 1]();

	// 动态申请二维数组
	int** mrr = new int*[M];		
	for (int i = 0; i < M; i++) {
		mrr[i] = new int[2];
	}
	
	// 输入二维数组
	for (int i = 0; i < M; i++) {
		cin >> mrr[i][0] >> mrr[i][1];
	}

	// 被砍树用1表示
	for (int i = 0; i < M; i++) {
		for (int j = mrr[i][0]; j <= mrr[i][1]; j++) {
			lrr[j] = 1;
		}
	}

	// 统计lrr[] 为0有树的数目
	for (int i = 0; i < L + 1; i++) {
		if (!lrr[i])	count++;
	}
	cout << count << endl;

	return 0;
}	