#include <iostream>
using namespace std;

int main() {
    string str;
    getline(cin, str);  // getline可以接收空格
    int abc = 0, num = 0, space = 0, other = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
            abc++;
        else if (str[i] >= '0' && str[i] <= '9')
            num++;
        else if (str[i] == ' ')
            space++;
        else
            other++;
    }
    cout << abc << " " << num << " " << space << " " << other << endl;
    return 0;
}