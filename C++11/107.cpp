#include <iostream>

using namespace std;

int main() {
    int a;
    cin >> a;
    if (!(a % 7) && (a % 2)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;   
}