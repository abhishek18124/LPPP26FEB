#include<iostream>

using namespace std;

class ListNode {

public :

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

int main() {

	ListNode* n1 = new ListNode(10);

	cout << n1->val << endl;

	ListNode* n2 = new ListNode(20);

	cout << n2->val << endl;

	n1->next = n2;

	cout << n1->next->val << endl;

	cout << n2 << endl;
	cout << n1->next << endl;

	return 0;
}