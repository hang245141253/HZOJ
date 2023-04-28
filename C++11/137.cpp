#include <iostream>

using namespace std;

int main(int argc, char** argv) {	
	int n;
	cin >> n;
	char ch = 'A';	// 65
	char a = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			cout << (char)(ch + a++);
		}
		cout << endl;
	}
	
	return 0;
}