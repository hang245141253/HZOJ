#include <cstdio>

int main() {
    int h, m, s, t;
    scanf("%d%d%d%d", &h, &m, &s, &t);
    char xm[24][7] = {
        "am", "am", "am", "am", "am", "am", "am" ,"am", "am", "am", "am", "am",
        "pm", "pm", "pm", "pm", "pm", "pm", "pm", "pm", "pm", "pm", "pm", "pm"
    };
    int hour[24] = {
        12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
    };
    
    int index = (h + t / 3600) % 24;
    s += t % 60;
    m += t / 60 % 60;

    printf("%d:%d:%d%s\n",
            hour[index + (m + s / 60) / 60],
            (m + s / 60) % 60,
            s % 60,
            xm[index]
          );
    printf("%.2lf%%\n", (double)(t) / 86400.0 * 100);
    
    return 0;
}