#include <iostream>
#define SUM 0
#define YU 1
#define SHU 2
#define YING 3
#define KE 4

using namespace std;

typedef struct student {
    string name;
    int grade[5];
} student;

void print_name(student* srr) {
    for (int i = 0; i < 4; i++) {
        i && cout << " ";
        cout << srr[i].name;
    }
    cout << endl;
}

void sort(student* srr, int n, int index) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (srr[j].grade[index] < srr[j + 1].grade[index])  swap(srr[j], srr[j + 1]);
            if (srr[j].grade[index] == srr[j + 1].grade[index] && srr[j].name.compare(srr[j + 1].name) > 0)   swap(srr[j], srr[j + 1]);
        } 
    }
    print_name(srr);
}

int main() {
    int n;
    cin >> n;
    student *srr = new student[n]();
    for (int i = 0; i < n; i++) {
        cin >> srr[i].name >> srr[i].grade[YU] >> srr[i].grade[SHU] >> srr[i].grade[YING] >> srr[i].grade[KE];
        srr[i].grade[SUM] = srr[i].grade[YU] + srr[i].grade[SHU] + srr[i].grade[YING] + srr[i].grade[KE];
    }

    sort(srr, n, YU);
    sort(srr, n, SHU);
    sort(srr, n, YING);
    sort(srr, n, KE);
    sort(srr, n, SUM);

    return 0;
}