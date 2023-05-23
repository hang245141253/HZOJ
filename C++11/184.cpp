#include <iostream>
using namespace std;

int peach(int day) {
    if (day == 1)   return 1;
    else            return (peach(day - 1) + 1) * 2;
}

int main() {
    int n;
    cin >> n;
    cout << peach(n);
    return 0;
}