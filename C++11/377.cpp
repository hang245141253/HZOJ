#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    char str[305];
    cin >> str;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') {
            s.push(i);
        } else if (str[i] == ')') {
            if (s.empty()) {
                cout << "NO" << endl;
                return 0;
            }
            s.pop();
        }
    }
    if (s.empty()) cout << "YES" << endl;
    else         cout << "NO" << endl;
    
    return 0;
}
