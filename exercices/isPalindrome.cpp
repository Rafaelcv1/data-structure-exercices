#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return true;
		
		//find middle or the second part, sets slow to the middle
		ListNode* fast = head;
		ListNode* slow = head;

		while (fast->next != nullptr && fast->next->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}

		//reverts second half, sets curr to end
		ListNode* prev = nullptr;
		ListNode* curr = slow->next;
		while (curr != nullptr) {
			ListNode* nextTemp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextTemp;
		}
		ListNode* end = prev;

		//checks if palindrome
		ListNode* firstHalf = head;
		ListNode* secondHalf = end;
		bool isValid = true;

		while (isValid && secondHalf != nullptr) {
			if (firstHalf->val != secondHalf->val)
				isValid = false;
			firstHalf = firstHalf->next;
			secondHalf = secondHalf->next;
		}

		//reverts again the list
		prev = nullptr;
		curr = end;
		while (curr != nullptr) {
			ListNode* nextTemp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextTemp;
		}
		slow->next = prev;

		return isValid;
	}
};

int main() {
	Solution s;
	ListNode* head = new ListNode(1);
	head = new ListNode(2, head);
	cout << s.isPalindrome(head);
}
