#include <iostream>
using namespace std;

typedef struct student {
    string name;
    int shu, yu, ying, di, sum;
} student;

int sum(int shu, int yu, int ying, int di) {
    return shu + yu + ying + di;
}

int main() {
    int n;
    cin >> n;
    student *srr = new student[n]();
    for (int i = 0; i < n; i++) {
        cin >> srr[i].name >> srr[i].shu >> srr[i].yu >> srr[i].ying >> srr[i].di;
        srr[i].sum = sum(srr[i].shu, srr[i].yu, srr[i].ying, srr[i].di);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (srr[j].sum < srr[j + 1].sum)    swap(srr[j], srr[j + 1]);
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << srr[i].name << endl;
    }

    return 0;
}