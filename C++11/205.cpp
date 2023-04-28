#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m; 
	int** arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	} 
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	
	double sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum += arr[i][j];
		}
		cout << fixed << setprecision(6) << sum / m << endl;
		sum = 0;
	}
	
	return 0;
} 