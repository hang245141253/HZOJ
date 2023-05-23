#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int g = n % 10;
    int s = n / 10 % 10;
    int b = n / 100 % 10;
    int q = n / 1000 % 10;
    cout << g + s + b + q << endl;

    return 0;   
}