#include <iostream>

using namespace std;

int main(int argc, char** argv) {	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (!(i % 7))	cout << i << endl;
	}
	
	return 0;
}	