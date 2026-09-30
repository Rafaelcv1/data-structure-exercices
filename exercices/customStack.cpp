#include <bits/stdc++.h>
#include <vector>

using namespace std;

class CustomStack {
	vector<int> stack;
	int head{};
	int capacity;
public:
	CustomStack(int maxSize) : capacity(maxSize), stack(maxSize){}

	void push(int x) {
		if (head < capacity) {
			stack[head] = x;
			head++;
		}
	}
	
	int pop() {
		if (head == 0) return -1;
		int aux = stack[--head];
		return aux;
	}
	
	void increment(int k, int val) {
		for (int i = 0; i < min(k, head); i++) {
			stack[i]+=val;
		}
	}
};

int main() {
CustomStack stk(3);
stk.push(1);                          // stack becomes [1]
stk.push(2);                          // stack becomes [1, 2]
cout <<stk.pop()<< endl;                            // return 2 --> Return top of the stack 2, stack becomes [1]
stk.push(2);                          // stack becomes [1, 2]
stk.push(3);                          // stack becomes [1, 2, 3]
stk.push(4);                          // stack still [1, 2, 3], Do not add another elements as size is 4
stk.increment(5, 100);                // stack becomes [101, 102, 103]
stk.increment(2, 100);                // stack becomes [201, 202, 103]
cout << " " <<stk.pop()<< endl;                            // return 103 --> Return top of the stack 103, stack becomes [201, 202]
cout << " " <<stk.pop()<< endl;                            // return 202 --> Return top of the stack 202, stack becomes [201]
cout << " " <<stk.pop()<< endl;                            // return 201 --> Return top of the stack 201, stack becomes []
cout << " " <<stk.pop()<< endl;                            // return -1 --> Stack is empty return -1.
}
