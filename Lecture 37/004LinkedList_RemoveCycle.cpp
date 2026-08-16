#include<iostream>
#include<set>

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

// time : O(nlogn)
// space: O(n) due to set<>

void removeCycle(ListNode* head) {
	ListNode* prev = NULL;
	ListNode* cur = head;
	set<ListNode*> s;
	while (true) {
		if (s.count(cur)) {
			// remove cycle, prev is at tail
			prev->next = NULL;
			break;
		} else {
			s.insert(cur);
			prev = cur;
			cur = cur->next;
		}
	}
}

// time : O(n)
// space: O(1)

void removeCycleOptimised(ListNode* head) {
	ListNode* slow = head;
	ListNode* fast = head;

	while (true) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			break;
		}
	}

	// slow & fast are at the meeting point

	ListNode* prev = head;
	while (prev->next != slow) {
		prev = prev->next;
	}

	// prev is one-step behind meeting point

	slow = head;

	while (slow != fast) {
		prev = prev->next;
		slow = slow->next;
		fast = fast->next;
	}

	// at this point slow & fast are at the start of the cycle
	// therefore prev is at the tail

	prev->next = NULL;

}

int main() {

	ListNode* head = new ListNode(10);
	head->next = new ListNode(20);
	head->next->next = new ListNode(30);
	head->next->next->next = new ListNode(40);
	head->next->next->next->next = new ListNode(50);
	head->next->next->next->next->next = new ListNode(60);
	head->next->next->next->next->next->next = head->next;

	// removeCycle(head);

	removeCycleOptimised(head);

	printLinkedList(head);

	return 0;
}