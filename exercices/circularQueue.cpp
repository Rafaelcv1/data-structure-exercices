#include <bits/stdc++.h>

class MyCircularQueue {
	std::vector<int> circularQueue;
	int head;
	int tail;
	int size{};
	int capacity{};
public:
	MyCircularQueue(int k) {
		for (int i = 0; i < k; i++) {
			circularQueue.push_back(0);
		}
		capacity = k;
	}
	bool enQueue(int value) {
		if (isFull())
			return false;

		circularQueue[tail] = value;
		tail = (tail+1) % capacity;
		size++;
		return true;
	}
	bool deQueue() {
		if (isEmpty())
			return false;
		head = (head+1)%capacity;
		size--;
		return true;
	}
	int Front() {
		if (isEmpty())
			return -1;
		return circularQueue[head];
	}
	int Rear() {
		if(isEmpty())
			return -1;
		return circularQueue[(tail-1+capacity)%capacity];
	}
	bool isEmpty() {
		return !size;
	}
	bool isFull() {
		return (head == tail && size);
	}
};

using namespace std;
//"MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
int main() {
	MyCircularQueue* obj = new MyCircularQueue(3);
	cout << obj->enQueue(1) << " " <<
	obj->enQueue(2) << " " <<
	obj->enQueue(3) << " " <<
	obj->enQueue(4) << " " <<
	obj->Rear() << " " <<
	obj->isFull() << " " <<
	obj->deQueue() << " " <<
	obj->enQueue(4) << " " <<
	obj->Rear() << endl;
}
