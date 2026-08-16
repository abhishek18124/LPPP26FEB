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

bool isCyclePresent(ListNode* head) {
	set<ListNode*> s;
	while (head != NULL) {
		if (s.count(head)) {
			// head is already present in the set<>
			return true; // cycle found
		} else {
			s.insert(head);
			head = head->next;
		}
	}

	// no cycle found r
	return false;
}

// time : O(n)
// space: O(1)

bool isCyclePresentOptimised(ListNode* head) {

	ListNode* slow = head;
	ListNode* fast = head;

	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true; // cycle found
		}
	}

	return false; // cycle not found

}

int main() {

	ListNode* head = new ListNode(10);
	head->next = new ListNode(20);
	head->next->next = new ListNode(30);
	head->next->next->next = new ListNode(40);
	head->next->next->next->next = new ListNode(50);
	head->next->next->next->next->next = new ListNode(60);
	head->next->next->next->next->next->next = head->next;

	if (isCyclePresent(head)) {
		cout << "cycle found" << endl;
	} else {
		cout << "no cycle found" << endl;
	}

	isCyclePresent(head) ? cout << "cycle found" << endl :
	                            cout << "no cycle found" << endl;

	isCyclePresentOptimised(head) ? cout << "cycle found" << endl :
	                                     cout << "no cycle found" << endl;

	return 0;
}