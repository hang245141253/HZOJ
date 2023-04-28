#include <iostream>

using namespace std;

int main(int argc, char** argv) {	
	char arr[50] = {};
	cin >> arr;
	int i = 0;
	while (arr[i]) {
		if ((arr[i] > 64 && arr[i] < 90) || (arr[i] > 96 && arr[i] < 122))	arr[i++]++;
		else if (arr[i] == 90)	arr[i++] = 65;	//	Z -> A
		else if (arr[i] == 122)	arr[i++] = 97;	//	z -> a
		else	i++; 
	}
	cout << arr << endl;

	return 0;
}

/*
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv) {	
	char arr[50] = {};
	cin >> arr;
	for (int i = 0; i < strlen(arr); i++) {
		if ((arr[i] > 64 && arr[i] < 90) || (arr[i] > 96 && arr[i] < 122))	arr[i]++;
		else if (arr[i] == 90)	arr[i] = 65;	//	Z -> A
		else if (arr[i] == 122)	arr[i] = 97;	//	z -> a
		else	; 
	}
	cout << arr << endl;

	return 0;
}	
*/