#include <iostream>
using namespace std;

int main() {
    string A, B;
    int N;
    cin >> A >> N >> B;

    if (A.size() > 100) cout << 100 << endl;
    else                cout << A.size() << endl;

    string C;
    for (int i = 0; i < A.size(); i++) {
        if (i == N - 1) C += B;
        C += A[i];
    }
    cout << C << endl;

    for (int i = C.size(), count = 0; i > 0; i--, count++) {
        if (C[i] == 'x') {
            cout << count << endl;
            break;
        }
    }

    return 0;
}