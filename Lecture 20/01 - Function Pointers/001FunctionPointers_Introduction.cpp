#include<iostream>

using namespace std;

void greet() {
	cout << "namaste" << endl;
}

int add(int a, int b) {
	return a + b;
}

bool ascending(int a, int b) {
	return a > b; // return true if a > b otherwise return false
}

int main() {

	// cout << &greet << endl;
	// cout << greet << endl;
	// cout << (void*)&greet << endl;
	// cout << (void*)greet << endl << endl;

	// void (*gptr)() = &greet;
	// // cout << gptr << endl;
	// cout << (void*)gptr << endl;
	// greet();
	// (*gptr)();
	// gptr(); // when you dereference a fn pointer, it means you are trying to call the it points to. Using * is optional
	// (*greet)();

	// cout << (void*)&add << endl;
	// cout << (void*)add << endl << endl;

	int (*aptr)(int, int) = add;
	// cout << (void*)aptr << endl;
	cout << add(1, 2) << endl;
	cout << (*aptr)(1, 2) << endl;
	cout << aptr(1, 2) << endl;
	cout << (*add)(1, 2) << endl;

	// cout << (void*)&ascending << endl;
	// cout << (void*)ascending << endl;

	bool (*ascptr)(int, int) = ascending;
	// cout << (void*)ascptr << endl;
	cout << ascending(3, 2) << endl;
	cout << (*ascptr)(3, 2) << endl;
	cout << ascptr(3, 2) << endl;
	cout << (*ascending)(3, 2) << endl;

	return 0;
}