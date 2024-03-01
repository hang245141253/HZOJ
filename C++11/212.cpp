#include <iostream>
#include <cstring>
using namespace std;

char str[10][25];

void bubbleSort(char* strings[], int numStrings) {
    for (int i = 0; i < numStrings - 1; i++) {
        for (int j = 0; j < numStrings - i - 1; j++) {
            if (strcmp(strings[j], strings[j + 1]) > 0) {
                // 交换两个字符串的地址
                char* temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = temp;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 10; i++)
        cin >> str[i];

    char* strings[10];
    for (int i = 0; i < 10; i++)
        strings[i] = str[i];

    bubbleSort(strings, 10);

    for (int i = 0; i < 10; i++)
        cout << strings[i] << endl;

    return 0;
}
