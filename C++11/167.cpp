#include <iostream>
using namespace std;

int main() {
    string A, B;
    int N;
    cin >> A >> N >> B;

    cout << A.size() << endl;

    for (int i = 0; i < A.size(); i++) {
        if (A[i] == 'a') {
            cout << i + 1 << endl;
            break;
        }
    }

    for (int i = 0; i < A.size(); i++) {
        if (i == N - 1) cout << B;
        cout << A[i];
    }

    return 0;
}