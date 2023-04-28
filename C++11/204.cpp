#include <iostream>

using namespace std;

int main() {	
	int n;
	cin >> n;

	// 动态申请二维数组
	int** arr = new int*[n];		
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}
	
	// 输入二维数组
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	// 输出二维数组
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == i)	cout << arr[i][j] << endl;
		}
	}

	return 0;
}	