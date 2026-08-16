#include<iostream>

using namespace std;

class ListNode {
public:

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

	while (head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

}

int findLenIterative(ListNode* head) {
	int cnt = 0;
	while (head != NULL) {
		cnt++;
		head = head->next;
	}
	return cnt;
}

// time : 3n/2.const ~ O(n)
// space: O(1)

ListNode* findMidPoint(ListNode* head) {

	int n = findLenIterative(head);

	int i = 0;

	while (i < n / 2) {
		head = head->next;
		i++;
	}

	return head;

}

// time : n/2.const ~ O(n)

ListNode* findMidPointOptimised(ListNode* head) {
	if (head == NULL) {
		// linkedList is empty
		return NULL;
	}
	ListNode* slow = head;
	ListNode* fast = head->next;
	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	// ListNode* midPoint = findMidPoint(head);
	// cout << midPoint->val << endl;

	ListNode* midPoint = findMidPointOptimised(head);
	if (midPoint != NULL) {
		cout << midPoint->val << endl;
	} else {
		cout << "linkedList is empty" << endl;
	}

	return 0;
}