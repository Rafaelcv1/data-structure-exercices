#include <bits/stdc++.h>
#include <stack>

using namespace std;

class MyQueue {
private:
	stack<int> inputStack;
	stack<int> outputStack;
public:
	MyQueue() {}

	void push(int x) {
		inputStack.push(x);
	}

	int pop() {
		if (outputStack.size() == 0) {
			while (inputStack.size() != 0) {
				outputStack.push(inputStack.top());
				inputStack.pop();
			}
		}
		int temp = outputStack.top();
		outputStack.pop();
		return temp;
	}

	int peek() {
		if (outputStack.size() == 0)
			while (inputStack.size() != 0) {
				outputStack.push(inputStack.top());
				inputStack.pop();
			}
		return outputStack.top();
	}

	bool empty() {
		return max(inputStack.size(), outputStack.size()) == 0;
	}
};

//["MyQueue","push","push","peek","pop","empty"]
//[[],[1],[2],[],[],[]]
int main() {
	MyQueue* obj = new MyQueue();
	obj->push(1);
	obj->push(2);
	int param_3 = obj->peek();
	int param_2 = obj->pop();
	bool param_4 = obj->empty();
}
