#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv) {	
	char arr[100] = {};
	cin >> arr;
	int count = 0;
	for (int i = 0; i < strlen(arr); i++) {
		if (arr[i] == 'A')	count++;
	}
	cout << count << endl;

	return 0;
}	