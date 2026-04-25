#include<iostream>

using namespace std;

void greet() {
	cout << "\nhi\n";
}

int main() {

	cout << "\nI am inside the main(), before greet()\n";

	greet();

	cout << "\nI am inside the main(), after greet()\n";

	return 0;
}