#include<iostream>

using namespace std;

void isEven(int n) {

	if (n % 2 == 0) {
		cout << "even\n";
	} else {
		cout << "odd\n";
	}

	return; // optional

}

int main() {

	isEven(4);

	isEven(5);

	return 0;
}