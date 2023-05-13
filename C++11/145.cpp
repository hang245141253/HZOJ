#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string *str = new string[n];
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    int max = str[0].size();
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (max < str[i].size()) {
            max = str[i].size();
            index = i;
        }
    }
    cout << str[index] << endl;
    
	return 0;
}


/*二维数组解法，C语言风格
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
	char **str = new char*[n];
	for (int i = 0; i < n; i++) {
        str[i] = new char[100]();
    }
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    int max = strlen(str[0]);
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (max < strlen(str[i])) {
            max = strlen(str[i]);
            index = i;
        }
    }
    cout << str[index] << endl;
    
	return 0;
}
*/
