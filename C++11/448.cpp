#include <iostream>

using namespace std;

int yes(int num, int n, int* arr) {
	for (int i = 0; i < n; i++)	{
		if (num == arr[i])	return i + 1;
	}
	return 0;
}

int main(int argc, char** argv) {	
	int n, num;
	cin >> n;
	int* arr = new int[n];		// 动态申请数组
	for (int i = 0; i < n; i++)	cin >> arr[i];
	cin >> num;
	cout << yes(num, n, arr);

	return 0;
}	