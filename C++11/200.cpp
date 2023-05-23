#include <iostream>
#include <iomanip>
using namespace std;

typedef struct sequence {
    double fz, fm;
} sequence;


void print_sequence(int i, sequence* arr) {
    cout << fixed << setprecision(0) << arr[i].fz << "/" << arr[i].fm << endl;
}

double value_sequence(int i, sequence* arr) {
    return arr[i].fz / arr[i].fm;
}

int main() {
    int n;
    cin >> n;
    sequence *arr = new sequence[n]();
    arr[0].fz = 4;
    arr[0].fm = 7;
    arr[1].fz = 7;
    arr[1].fm = 11;

    for (int i = 2; i < n; i++) {
        arr[i].fz = arr[i - 1].fz + arr[i - 2].fz;
        arr[i].fm = arr[i - 1].fm + arr[i - 2].fm;
    }
    print_sequence(n - 1, arr);

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += value_sequence(i, arr);
    }
    cout << fixed << setprecision(2) << sum << endl;
    
    return 0;
}