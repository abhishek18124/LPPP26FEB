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


void insertAtHead(ListNode*& head, int val) {

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;

}

void printLinkedList(ListNode* head) {

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

}

// time : O(n)

int findLenIterative(ListNode* head) {
	int cnt = 0;
	while (head != NULL) {
		cnt++;
		head = head->next;
	}
	return cnt;
}

int findLenRecursive(ListNode* head) {
	// base case
	if (head == NULL) {
		// f(NULL) : find the length of an empty linkedList
		return 0;
	}

	// recursive case

	// f(head) : find the length of the given linkedList

	// 1. ask your friend to find the length of the
	// sublist that starts from the node which comes
	// after the head node
	int x = findLenRecursive(head->next);

	// 2. use the answer from your friend to build the
	// final answer
	return 1 + x;
}

int main() {

	ListNode* head = NULL; // initially, linkedList empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	cout << findLenIterative(head) << endl;

	cout << findLenRecursive(head) << endl;

	return 0;
}