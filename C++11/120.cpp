#include <iostream>

using namespace std;

int main() {
    int y, m, d;
    cin >> y >> m >> d;

    if (m < 1 || d < 1 || m > 12 || d > 31) cout << "NO" << endl;
    else if ((m==4 || m==6 || m==9 || m==11) && d > 30) cout << "NO" << endl;
    else if (((y % 4 == 0 && y % 100) || y % 400 == 0) && m == 2 && d > 29) cout << "NO" << endl;
    else if (!((y % 4 == 0 && y % 100) || y % 400 == 0) && m == 2 && d > 28)  cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;   
}