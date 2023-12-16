#include <iostream>
#include <algorithm>
using namespace std;

string name[105];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name[i];
        for (int j = 0; j < name[i].length(); j++)
            name[i][j] = tolower(name[i][j]);
        name[i][0] -= 32;
    }

    sort(name, name + n);
    for (int i = 0; i < n; i++) {
        cout << name[i] << endl;
    }

    return 0;
}

/*
#include <iostream>
#define swap(a, b) {\
    string tmp=a;\
    a=b;b=tmp;\
}

using namespace std;

int main() {
    int n;
    cin >> n;
    string *str = new string[n]();
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    for (int i = 0; i < n; i++) {
        if (str[i][0] > 96 && str[i][0] < 123)  str[i][0] -= 32;
        for (int j = 1; j < str[i].size(); j++) {
            if (str[i][j] > 64 && str[i][j] < 91)   str[i][j] += 32;
        }
    }

    // // 冒泡排序
    // for (int i = 0; i < n - 1; i++) {
    //     for (int j = 0; j < n - i - 1; j++) {
    //         if (str[j].compare(str[j + 1]) > 0) swap(str[j], str[j + 1]);
    //     }
    // }

// 插入排序
for (int i = 1; i < n; i++) {
    for (int j = i; j > 0 && str[j].compare(str[j - 1]) < 0; j--) {
        swap(str[j], str[j - 1]);
    }
}

for (int i = 0; i < n; i++) {
    cout << str[i] << endl;
}
return 0;
}
*/