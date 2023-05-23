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

    for (int i = 0; i < n; i++) {
        cout << srr[i].sum << endl;
    }

    student height = srr[0];
    for (int i = 1; i < n; i++) {
        if (height.sum < srr[i].sum)   height = srr[i];
    }
    cout << height.name << endl;
    
    int max = 0, min = 100;
    for (int i = 0; i < n; i++) {
        for (int j = 0, *p = &srr[i].shu; j < 4; j++) {
            if (max < p[j]) max = p[j];
            if (min > p[j]) min = p[j];
        }
    }
    cout << max << " " << min << endl;
    
    return 0;
}