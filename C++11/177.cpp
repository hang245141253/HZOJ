#include <iostream>
using namespace std;

int main() {
    string l;
    cin >> l;
    for (int i = 0; i < l.size(); i++) {
        for (int j = i * (l.size() - 2) % l.size(); j < l.size() + (i * (l.size() - 2) % l.size()); j++) {
            printf("%c", l[j % l.size()]);
        }
        printf("\n");
    }
    return 0;
}

/*
l[j * (l.size() - 2) % l.size()]

01234  0 * (l.size() - 2) % l.size() = 0   0+l.size()=5
34012  1 * (l.size() - 2) % l.size() = 3   3+l.size()=8
12340  2 * (l.size() - 2) % l.size() = 1   1+l.size()=6
40123  3 * (l.size() - 2) % l.size() = 4   ...
23401  4 * (l.size() - 2) % l.size() = 2
 */