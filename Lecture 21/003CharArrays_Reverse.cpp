#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {

	char str[] = "hello";

	cout << str << endl;

	int n = strlen(str);

	// reverse(str, str + n);
	reverse(str, str + 2); // [0, 2)

	cout << str << endl;

	return 0;
}