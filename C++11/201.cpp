#include <iostream>
#define swap(a, b) a^=b, b^=a, a^=b
 
int main() {
    int n;
    scanf("%d", &n);
    int *arr = new int[n]();
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            swap(arr[j], arr[j - 1]);
        }
    }

    int count = 0;
    std::string str;
    char tmp[10] = {0};
    for (int i = 0; i < n; i++) {
        if (arr[i] == arr[i - 1])   continue;
        count++;
        if (__builtin_expect(i, 1)) str += " ";
        sprintf(tmp, "%d", arr[i]);
        str += tmp;
    }
    printf("%d\n", count);
    std::cout << str;

    return 0;
}

/*
    int count = 0;
    char srr[999] = {0};
    FILE *fp = fopen(".\\1.txt", "w+a+");
    for (int i = 0; i < n; i++) {
        if (arr[i] == arr[i - 1])   continue;
        count++;
        i && fprintf(fp , " ");
        fprintf(fp , "%d", arr[i]);
    }
    printf("%d\n", count);
    fclose(fp);

    FILE *fp1 = fopen(".\\1.txt", "r+");
    if (fp1) {
        while (fscanf(fp1, "%[^\n]s", srr) != EOF) {
            getchar();
            printf("%s", srr);
        }
    }
*/