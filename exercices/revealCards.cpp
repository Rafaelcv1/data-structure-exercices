#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
		sort(deck.begin(), deck.end());
		queue<int> indexes;
		vector<int> ansDeck(deck.size());

		for (int i = 0; i < deck.size(); i++)
			indexes.push(i);

		for (int card: deck) {
			ansDeck[indexes.front()] = card;
			indexes.pop();
			
			if (!indexes.empty()) {
				indexes.push(indexes.front());
				indexes.pop();
			}
		}
		return ansDeck;
    }
};
