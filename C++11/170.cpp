#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        /**replace用法
         用str替换指定字符串从起始位置pos开始长度为len的字符
         string& replace (size_t pos, size_t len, const string& str);
        */
        while (str.find("Ban_smoking") != -1) {
            int pos = str.find("Ban_smoking");
            str.replace(pos, 11, "No_smoking");
        }
        cout << str << endl;
    }
    return 0;
}

/*
//麻烦做法
#include <iostream>
using namespace std;

int cmp(char* str) {
    string ban = "Ban_smoking";
    for (int i = 0; i < ban.size(); i++) {
        if (*(str + i) != ban[i])   return 0;
    }
    return 1;
}

int main() {
    int n;
    cin >> n;
    string *str = new string[n];
    string no = "No_smoking";
    for (int i = 0; i < n; i++) {
        string buf;
        cin >> buf;
        for (int j = 0; j < buf.size(); j++) {
            if (buf[j] == 'B' && cmp(&buf[j])) {
                str[i] += no;
                j += no.size();
            } else {
                str[i] += buf[j];
            }
        }
        cout << str[i] << endl;
    }

    return 0;
}

*/