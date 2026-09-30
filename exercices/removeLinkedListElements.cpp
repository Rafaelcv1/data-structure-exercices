struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

		ListNode* dummy = new ListNode(-1, head);
		ListNode* curr = head;
		while (curr->next != nullptr) {
			if (curr->next->val == val) {
				ListNode* to_delete = curr->next;
				curr->next = to_delete->next;
				delete to_delete;
			} else {
				curr = curr->next;
			}
		}
		ListNode* new_head = dummy->next;
		delete dummy;
		return new_head;

    }
};
int main() {
	Solution s;
	ListNode* head = new ListNode(7);
	head = new ListNode(7, head);
	head = new ListNode(7, head);
	head = new ListNode(7, head);
	s.removeElements(head, 7);
}
