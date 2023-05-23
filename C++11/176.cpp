#include <iostream>
using namespace std;

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    int count = 0;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] == str2[0]) {
            bool flag = true;
            for (int j = 0; j < str2.size(); j++) {
                if (str2[j] != str1[i + j]) {
                    flag = false;
                    break;
                }
            }
            flag && count++;
        }
    }
    cout << count;
    return 0;
}