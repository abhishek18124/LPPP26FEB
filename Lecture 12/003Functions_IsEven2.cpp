#include<iostream>

using namespace std;

bool isEven(int n) {

	// if (n % 2 == 0) {
	// 	return true;
	// } else {
	// 	return false;
	// }

	// if (n % 2 == 0) {
	// 	return true;
	// }

	// return false;

	// return n % 2 == 0 ? true : false;

	return n % 2 == 0;

}

int main() {

	bool ans;
	ans = isEven(4);
	cout << ans << '\n';

	cout << isEven(5) << '\n';

	// if a fn call returns a value, you can
	// treat that fn call as an expression

	if (isEven(7)) {
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}

	isEven(9) ? cout << "even" << endl : cout << "odd" << endl;

	return 0;
}