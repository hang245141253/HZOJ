#include <iostream>

using namespace std;

int main() {
    char m1, m2, l1, l2;
    cin >> m1 >> m2;
    cin >> l1 >> l2;

    bool flag;
    if (m1 - l1 == (char)-10 || m1 - l1 == (char)-7 || m1 - l1 == (char)17) {
        if (m1 - l2 == (char)-10 || m1 - l2 == (char)-7 || m1 - l2 == (char)17 || m1 == l2) cout << "MING" << endl;
        else {
            if (m2 - l2 == (char)-10 || m2 - l2 == (char)-7 || m2 - l2 == (char)17) cout << "MING" << endl;
            else cout << "LIHUA" << endl;
        }
    } else if (m1 == l1) {
        if (m2 - l2 == (char)-10 || m2 - l2 == (char)-7 || m2 - l2 == (char)17) cout << "MING" << endl;
        else if (m2 == l2) cout << "TIE" << endl;
        else cout << "LIHUA" << endl;
    } else {
        if (m2 - l1 == (char)-10 || m2 - l1 == (char)-7 || m2 - l1 == (char)17) {
            if (m2 - l2 == (char)-10 || m2 - l2 == (char)-7 || m2 - l2 == (char)17 || m2 == l2) cout << "MING" << endl;
            else cout << "LIHUA" << endl;
        } else {
            cout << "LIHUA" << endl;
        }
    }

    return 0;   
}