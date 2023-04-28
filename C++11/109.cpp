#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    int g = n % 10;
    int s = n / 10 % 10;
    int b = n / 100 % 10;
    int q = n / 1000 % 10;

    if (!(g % 2) ||!(s % 2) ||!(b % 2) ||!(q % 2)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;   
}