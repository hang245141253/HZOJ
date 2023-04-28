#include <iostream>

using namespace std;

int main(int argc, char** argv) {	
	int n;
	int max, min;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	max = min = arr[0];
	for (int i = 0; i < n; i++) {
		if (max < arr[i])	max = arr[i];
		if (min > arr[i])	min = arr[i];
	}
	cout << max - min << endl;
	
	return 0;
}	