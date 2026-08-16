/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL) {
			return head;
		}
		ListNode* prev = head;
		ListNode* cur = head->next;
		while (cur != NULL) {
			if (cur->val == prev->val) {
				// skip the cur node
				cur = cur->next;
			} else {
				// track the cur node
				prev->next = cur;
				prev = prev->next;
				cur = cur->next;
			}
		}
		prev->next = NULL;
		return head;
	}
};