#include <iostream>
using namespace std;
int main() {	
    int a, b;
    int cnt = 0;
    bool block = false;
    cin >> a >> b;
	for (int i = a; i <= b; i++) {

		if (i % 6 != 0) {
			continue;
		}
		
		bool flag = true;
		int num1 = i / 100;
		for (int k = 2; k * k <= num1; k++) {
			if (num1 % k == 0) {
				flag = false;
			}
		}
		
		if (flag == false) continue;
		
		flag = false;
		int num2 = i % 100;
		for (int k = 0; k < 10; k++) {
			if (num2 == k * k) {
				flag = true;
				break;
			}
		}
		
		if (flag) {
			cnt++;
			if (block) cout << " ";
			cout << i;
			block = 1;
		}
	}
	cout << endl << cnt << endl;
    return 0;
}

// #include <cstdio>
// #define MAX_N 100

// int count = 0;

// void prime(int* arr) {
//     for (int i = 2; i <= MAX_N; i++) {
//         if (arr[i]) continue;
//         for (int j = i; j <= MAX_N / i; j++) {
//             arr[j * i] = 1;
//         }
//     }
// }

// void perfect_square(int *brr) {
//     for (int i = 1; i * i <= MAX_N; i++) {
//         brr[i * i] = 1;
//     }
// }


// int is_divided6(int x) {
//     return (x % 6) ? 0 : 1;
// }

// int is_prime(int* arr, int x) {
//     x /= 100;
//     return arr[x] ? 0 : 1;
// }

// int is_perfect_square(int* brr, int x) {
//     x %= 100;
//     return brr[x] ? 1 : 0;
// }

// int main() {
//     int a, b;
//     scanf("%d%d", &a, &b);
//     int *arr = new int[MAX_N]();
//     int *brr = new int[MAX_N]();
//     prime(arr);
//     perfect_square(brr);

//     for ( ; a < b + 1; a++) {
//         if (is_divided6(a) && is_prime(arr, a) && is_perfect_square(brr, a)) {
//             printf("%d", a);
//             count++;
//             break;
//         }
//     }
//     for (a++ ; a < b + 1; a++) {
//         if (is_divided6(a) && is_prime(arr, a) && is_perfect_square(brr, a)) {
//             printf(" %d", a);
//             count++;
//         }
//     }
//     printf("\n%d\n", count);

//     return 0;
// }