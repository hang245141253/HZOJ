#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv) {	
	char arr[50] = {};
	cin >> arr;
	for (int i = 0; i < strlen(arr) / 2; i++) {
		arr[i] ^= arr[strlen(arr) - i - 1];
		arr[strlen(arr) - i- 1] ^= arr[i];
		arr[i] ^= arr[strlen(arr) - i - 1];	
	}
	cout << arr << endl;

	return 0;
}	