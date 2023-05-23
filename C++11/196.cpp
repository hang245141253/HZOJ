#include <iostream> 
using namespace std;

int main() { 
    int f[55] = {0, 0, 1, 1, 1};
    int n;
    cin >> n;
    for (int i = 5; i < 51; i++) {
        f[i] = f[i - 2] + f[i - 3];
    }
    cout << f[n] << endl;
    return 0;
}