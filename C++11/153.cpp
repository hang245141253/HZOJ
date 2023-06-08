#include <cstdio>

int main() {
    int hrr[7] = {6, 7, 1, 2, 3, 4, 5};
    int mrr[13] = {0, 13, 14, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int y, m, q;
    scanf("%d%d%d", &y, &m, &q);
    if (m == 1 || m == 2)   y--;
    int j = y / 100, k = y % 100;
    int h = (q + 26 * (mrr[m] + 1) / 10 + k + k / 4 + j / 4 + 5 * j) % 7;
    printf("%d", hrr[h]);

    return 0;
}