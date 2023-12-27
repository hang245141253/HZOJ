#include <iostream>
using namespace std;

string f(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a')	str[i] -= 32;
		else				str[i] += 32;
	}
	return str;
}

int main() {
	string str;
	cin >> str;
	
	cout << f(str) << endl;
	
	return 0;
}

/*C语言写法
#include <iostream>
using namespace std;

int main() {
	char str[20] = {};
	cin >> str;
	for (int i = 0; str[i]; i++) {
		if (str[i] > 96)	str[i] -= 32;
		else				str[i] += 32;
		cout << str[i];
	}
	
	return 0;
}
*/