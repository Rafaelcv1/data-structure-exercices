#include <bits/stdc++.h>

class Solution {
public:
	struct Node {
		int val;
		Node* next;
	};

    int findTheWinner(int n, int k) {
		Node* HEAD = new Node;
		HEAD->val = n;

		Node* init = HEAD;

		for (int i = n-1; i > 0; i--) {
			Node* n = new Node;
			n->val = i;
			n->next = HEAD;
			HEAD = n;
		}
		init->next = HEAD;

		Node* curr = init;
		while (curr->next != curr) {
			for (int i = 0; i < k - 1; i++) {
				curr = curr ->next;
			}
			Node* to_delete = curr ->next;
			curr->next = to_delete->next;
			delete to_delete;
		}
		int val = curr->val;
		delete curr;
		return val;
    }
};
