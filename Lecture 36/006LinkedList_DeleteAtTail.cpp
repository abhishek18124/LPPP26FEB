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

void deleteAtHead(ListNode*& head) {

	if (!head) { // head == NULL
		// linkedList is empty
		return;
	}

	ListNode* temp = head;
	head = head->next;
	delete temp;
}

// time : O(n)
// space: O(1)

void deleteAtTail(ListNode*& head) {

	if (head == NULL) {
		// linkedList is empty
		return;
	}

	// linkedList is non-empty

	if (head->next == NULL) {
		// linkedList has 1 node
		deleteAtHead(head);
		return;
	}

	ListNode* prev = NULL;
	ListNode* cur = head;

	while (cur->next != NULL) {
		prev = cur;
		cur = cur->next;
	}

	// prev is pointing to second last node

	// and cur is pointing to last node i.e. tail node

	prev->next = NULL;
	delete cur;

}

int main() {

	ListNode* head = NULL; // linked list is initially empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head); // 10 20 30 40 50

	deleteAtTail(head);

	printLinkedList(head); // 10 20 30 40

	return 0;
}