#include <iostream>
using namespace std;

int main() {
	// init
	int n, m, sum = 0;
	cin >> n >> m;
	int **arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	// inputi
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	// process
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			sum += arr[j][i];
		}
		cout << sum << endl;
		sum = 0;
	}

	return 0;
} 