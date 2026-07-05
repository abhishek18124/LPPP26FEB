#include<iostream>

using namespace std;

void f(int n, char src, char dst, char hlp) {

	// base case
	if (n == 0) {
		return;
	}

	// recursive case

	// f(n) : move n disks from src to dst using hlp

	// 1. move n-1 disks from src to hlp using dst

	f(n - 1, src, hlp, dst);

	// 2. move largest disk from src to dst

	cout << "move disk from " << src << " to " << dst << endl;

	// 3. move n-1 disks from hlp to dst using src

	f(n - 1, hlp, dst, src);

}

int main() {

	int n = 5;

	f(n, 'A', 'C', 'B');

	return 0;
}