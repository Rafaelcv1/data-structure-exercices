#include <bits/stdc++.h>

using namespace std;

class FrontMiddleBackQueue {
private:
	void rebalance() {
		while (leftDeque.size() > rightDeque.size() + 1) {
			rightDeque.push_front(leftDeque.back());
			leftDeque.pop_back();
		}
		while (leftDeque.size() < rightDeque.size()) {
			leftDeque.push_back(rightDeque.front());
			rightDeque.pop_front();
		}
	}
	deque<int> leftDeque;
	deque<int> rightDeque;
public:
	FrontMiddleBackQueue() {
	}
	
	void pushFront(int val) {
		leftDeque.push_front(val);
		rebalance();
	}
	
	void pushMiddle(int val) {
		if (leftDeque.size() != rightDeque.size()) {
			rightDeque.push_front(leftDeque.back());
			leftDeque.pop_back();
		}
		leftDeque.push_back(val);
		rebalance();
	}
	
	void pushBack(int val) {
		rightDeque.push_back(val);
		rebalance();
	}
	
	int popFront() {
		if (leftDeque.size() == 0)
			return -1;
		int output = leftDeque.front();
		leftDeque.pop_front();
		rebalance();
		return output;
	}
	
	int popMiddle() {
		if (leftDeque.size() == 0)
			return -1;
		int output = leftDeque.back();
		leftDeque.pop_back();
		rebalance();
		return output;
	}
	
	int popBack() {
		if (rightDeque.size() == 0) {
			if (leftDeque.size() == 0) {
				return -1;
			} else {
				int output = leftDeque.back();
				leftDeque.pop_back();
				rebalance();
				return output;
			}
		}
		int output = rightDeque.back();
		rightDeque.pop_back();
		rebalance();
		return output;
	}
};

int main() {

FrontMiddleBackQueue q;
q.pushFront(1);   // [1]
q.pushBack(2);    // [1, 2]
q.pushMiddle(3);  // [1, 3, 2]
q.pushMiddle(4);  // [1, 4, 3, 2]
cout <<   q.popFront()     // return 1 -> [4, 3, 2]
<< " " << q.popMiddle()    // return 3 -> [4, 2]
<< " " << q.popMiddle()    // return 4 -> [2]
<< " " << q.popBack()      // return 2 -> []
<< " " << q.popFront();     // return -1 -> [] (The queue is empty)
}
