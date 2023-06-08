#include <cstdio>

int run(int y) {
    return !(y % 4) && y % 100 || !(y % 400) ? 1 : 0;
}

void yesterday(int y, int m, int d, int (*drr)[13]) {
    if (d > 1) d--;
    else {
        if (m > 1) m--;
        else {
            m = 12;
            y--;
        }
        d = drr[run(y)][m];
    }
    printf("%d %d %d\n", y, m, d);
}

void tomorrow(int y, int m, int d, int (*drr)[13]) {
    if (d < drr[run(y)][m]) d++;
    else {
        d = 1;
        if (m < 12) m++;
        else {
            m = 1;
            y++;
        }
    }
    printf("%d %d %d\n", y, m, d);
}

int main() {
    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    int drr[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    yesterday(y, m, d, drr);
    tomorrow(y, m, d, drr);
    
    return 0;
}