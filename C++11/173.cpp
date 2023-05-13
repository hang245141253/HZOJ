#include <iostream>
using namespace std;

int main() {
    string str;
    getline(cin, str);  //getline可以接收空格
    int abc = 0, num = 0, space = 0, other = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] > 64 && str[i] < 91 || str[i] > 96 && str[i] < 123)  abc++;
        else if (str[i] > 47 && str[i] < 58)    num++;
        else if (str[i] == 32)  space++;
        else    other++;
    }
    cout << abc << " " << num << " " << space << " " << other << endl;
    return 0;
}