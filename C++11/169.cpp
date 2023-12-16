#include <iostream>
#include <map>
using namespace std;

map<char, int> pwd;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char ch;
        int num;
        cin >> ch >> num;
        pwd[ch] = num;
    }
    string str;
    cin >> str;
    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        ans += pwd[str[i]];
    }
    cout << ans << endl;
    return 0;
}

// int main() {
//     // 因为有128个字符，利用字符的ASCII值作为下标存密码值
//     int n, num[128] = {};
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         char a;
//         int b;
//         cin >> a >> b;
//         num[(int)a] = b;
//     }
//     string str;
//     cin >> str;
//     int ans = 0;
//     for (int i = 0; i < str.size(); i++) {
//         ans += num[(int)str[i]];
//     }
//     cout << ans << endl;
//     return 0;
// }

// int main() {
//     int N;
//     cin >> N;
//     int *arr = new int[N];
//     char *str = new char[N];
//     for (int i = 0; i < N; i++) {
//         cin >> str[i] >> arr[i];
//     }
//     string passwd;
//     cin >> passwd;

//     int sum = 0;
//     for (int i = 0; i < passwd.size(); i++) {
//         for (int j = 0; j < N; j++) {
//             if (str[j] == passwd[i]) {
//                 sum += arr[j];
//                 continue;
//             }
//         }
//     }
//     cout << sum << endl;
//     return 0;
// }