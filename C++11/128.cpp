#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {	
	int n;
	double sum = 0;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}
	
	for (int i = 0; i < n; i++) {
		sum += arr[i]; 
	}
	cout << fixed << setprecision(2) << sum / n << endl;
	
	return 0;
}	