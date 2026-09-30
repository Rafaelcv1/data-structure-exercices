#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        while (node->next != nullptr) {
            node->val = node->next->val;
            node = node->next;
        }
        node = nullptr;
    }
};
using namespace std;

int main() {
	ListNode * nine = new ListNode(9);
	ListNode * one = new ListNode(1);
	ListNode * five = new ListNode(5);
	ListNode * four = new ListNode(4);
	four->next = five;
	five->next = one;
	one->next = nine;
	Solution s;
	s.deleteNode(five);
}
