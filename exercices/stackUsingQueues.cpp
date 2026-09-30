#include <bits/stdc++.h>
#include <queue>

using namespace std;

class MyStack {
private:
	queue<int> q1;
	queue<int> q2;
	void sendToOutput() {
		while (q1.size() > 1) {
			q2.push(q1.front());
			q1.pop();
		}
	}
	void sendToInput() {
		while (q2.size() > 1) {
			q1.push(q2.front());
			q2.pop();
		}
	}
public:
	MyStack() {
	}
	
	void push(int x) {
		sendToInput();
		q1.push(x);
	}
	
	int pop() {
		sendToOutput();
		int output = q2.front();
		q2.pop();
		return output;
	}
	
	int top() {
		sendToOutput();
		return q2.front();
	}
	
	bool empty() {
		return (q1.size() == q2.size() == 0);
	}
};


int main() {
	MyStack myStack;
	myStack.push(1);
	myStack.push(2);
	cout << myStack.top() << endl; // return 2
	cout << myStack.pop() << endl; // return 2
	cout << myStack.empty() << endl; // return False
	}
