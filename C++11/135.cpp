#include <cstdio>

int run(int y) {
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0 ? 1 : 0;
}

int main() {
    int x, y, m, d;
    scanf("%d%d%d%d", &x, &y, &m, &d);
    int mrr[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                      {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
                     };


    while (x) {
        if (d < mrr[run(y)][m]) d++;
        else {
            d = 1;
            if (m < 12) m++;
            else {
                m = 1;
                y++;
            }
        }
        x--;
    }

    printf("%d %d %d\n", y, m, d);

    return 0;
}