#include <iostream>
using namespace std;

int main() {
	// init
	int n;
	cin >> n;
	int **arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n]();
	}

	for (int i = 0; i < (n + 1) / 2; i++) {		// (n + 1) / 2 : n=3、4时输出2, n=5、6时输出3 ... ...
		int j = i;								// 每下一次从对角线开始
		for ( ; j < n - i - 1; j++) {			// (i每次++,表示最左边的不再执行)、(n - i - 1)这里的i表示最右边的不再执行
			arr[i][j] = arr[j][i] = i + 1;
		}
		for (int k = i ; k < j; k++) {			// 	保证对角线的元素不被执行到
			arr[k][j] = arr[j][k] = i + 1;
		}
		arr[j][j] = i + 1;
	}

	// output
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
			if (j != n - 1)	cout << " ";
		}
		cout << endl;
	}
	
	return 0;
} 