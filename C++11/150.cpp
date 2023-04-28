#include <iostream>

using namespace std;

int main() {	
	int n, m;
	cin >> n >> m;

	// 动态申请二维数组
	int** arr = new int*[n];		// row	
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];		// column
	}
	
	// 输入二维数组
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	// 输出二维数组
	for (int i = 0; i < m; i++) {
		for (int j = n - 1; j > -1; j--) {
			cout << arr[j][i];
			if (j) cout << " ";
		}
		cout << endl;
	}

	return 0;
}