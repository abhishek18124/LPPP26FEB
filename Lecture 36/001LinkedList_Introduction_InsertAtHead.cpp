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

// time : O(1)

void insertAtHead(ListNode*& headPtr, int val) { // here headPtr is passed by reference since we want changes done to the headPtr inside the fn to be reflected in the caller fn
	ListNode* n = new ListNode(val);
	n->next = headPtr;
	headPtr = n;
}

// time : O(n)

void printLinkedList(ListNode* head) { // here headPtr is passed by value since we don't changes done to the headPtr inside the fn to be reflected in caller fn
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 50); printLinkedList(head);// 50
	insertAtHead(head, 40); printLinkedList(head);// 40 50
	insertAtHead(head, 30); printLinkedList(head);// 30 40 50
	insertAtHead(head, 20); printLinkedList(head);// 20 30 40 50
	insertAtHead(head, 10); printLinkedList(head);// 10 20 30 40 50

	if (head == NULL) {
		cout << "LinkedList is empty" << endl;
	}

	printLinkedList(head);


	if (head == NULL) {
		cout << "LinkedList is empty" << endl;
	}
	printLinkedList(head);

	return 0;
}