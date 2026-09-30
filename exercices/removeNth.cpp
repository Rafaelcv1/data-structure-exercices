struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) return nullptr;
        ListNode* hat = new ListNode(0, head);
		ListNode* slowStart = hat;
        ListNode* quickStart = hat;
		for (int i = 0; i < n; i++) {
			quickStart = quickStart->next;
		}

        while (quickStart->next != nullptr) {
			slowStart = slowStart->next;
			quickStart = quickStart->next;
        }
      if (slowStart == head) return head->next;
		slowStart->next = slowStart->next->next;
        return head;
    }
};
int main() {
	Solution s;
	ListNode* head = new ListNode(2);
	head = new ListNode(1, head);
	s.removeNthFromEnd(head, 2);
}
