#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int *arr = new int[N];
    char *str = new char[N];
    for (int i = 0; i < N; i++) {
        cin >> str[i] >> arr[i];
    }
    string passwd;
    cin >> passwd;

    int sum = 0;
    for (int i = 0; i < passwd.size(); i++) {
        for (int j = 0; j < N; j++) {
            if (str[j] == passwd[i]) {
                sum += arr[j]; 
                continue;
            }
        }
    }
    cout << sum << endl;
    return 0;
}