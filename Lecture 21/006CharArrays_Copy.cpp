#include<iostream>
#include<cstring>

using namespace std;

// time : O(len of s2=)

void stringCopy(char s1[], char s2[]) {

	int i = 0;
	int j = 0;

	while (s2[j] != '\0') {
		s1[i] = s2[j];
		i++;
		j++;
	}

	s1[i] = '\0';

}

int main() {

	char s1[100] = "abcde";
	char s2[] = "xyz";

	cout << s1 << endl;

	// stringCopy(s1, s2);
	strcpy(s1, s2); // we are copying s2 into s1

	cout << s1 << endl;

	return 0;
}