// constraints n <= 8

#include<iostream>

using namespace std;

void f(int n, char out[], int i, int oc, int cc) {

	// base case
	if (i == 2 * n) {
		out[i] = '\0';
		cout << out << endl;
		return;
	}

	// recursive case

	// f(i, oc, cc) : take decisions for out[i....2n-1] s.t. oc '(' and cc ')' are used so far

	// decide out[i]

	// option 1 : use '('
	if (oc < n) {
		out[i] = '(';
		oc++;
		f(n, out, i + 1, oc, cc);
		oc--;
	}

	// option 2 : use ')'
	if (cc < oc) {
		out[i] = ')';
		cc++;
		f(n, out, i + 1, oc, cc);
		cc--;
	}
}

int main() {

	int n = 3;

	char out[20];

	f(n, out, 0, 0, 0);

	return 0;
}