#include <utility>
class MinStack {
public:
    MinStack() {
    }
    
    void push(int value) {
		v[head].first = value;
		if (head == 0) {
			v[head].second = value;
		} else if (v[head-1].second > value) {
				v[head].second = value;
		} else {
				v[head].second = v[head-1].second;
		}
		head++;
    }
    
    void pop() {
		head--;
    }
    
    int top() {
		return v[head-1].first;
    }
    
    int getMin() {
		return v[head-1].second;
    }
private:
	int head{};
	std::pair<int, int> v[30000];
};

int main() {
	
	MinStack* obj = new MinStack();
	obj->push(-2);
	obj->push(0);
	obj->push(-3);
	int param_1 = obj->getMin();
	obj->pop();
	int param_2 = obj->top();
	int param_3 = obj->getMin();
}
//["MinStack","push","push","push","getMin","pop","top","getMin"]
//[[],[-2],[0],[-3],[],[],[],[]]
