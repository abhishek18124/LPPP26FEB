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

ListNode* reverseIterative(ListNode* head) {

	ListNode* cur = head;
	ListNode* prev = NULL;

	while (cur != NULL) {
		ListNode* temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}

	return prev;
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

// time : 3n/2.const ~ O(n)
// space: O(1)

bool isPalindrome(ListNode* head) {

	ListNode* midPoint = findMidPointOptimised(head);
	ListNode* head2 = midPoint->next;
	midPoint->next = NULL;

	head2 = reverseIterative(head2);

	while (head2 != NULL) {
		if (head->val != head2->val) {
			return false;
		}
		head = head->next;
		head2 = head2->next;
	}

	return true;

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	isPalindrome(head) ? cout << "palindrome" << endl : cout << "not a palindrome" << endl;

	return 0;
}