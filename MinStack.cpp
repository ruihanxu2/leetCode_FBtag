//用另一个stack记录当前的最小值
|3 4 1 2 7 9 -1
|3 3 1 1 1 1 -1
class MinStack {
public:
	MinStack() {
		
	}
	
	void push(int x) {
		if(minS.empty()) minS.emplace(x);
		else{
			if(x < minS.top()) minS.emplace(x);
			else{
				minS.emplace(minS.top());
			}
		}
		s.emplace(x);
	}
	
	void pop() {
		minS.pop();
		s.pop();
	}
	
	int top() {
		return s.top();
	}
	
	int getMin() {
		return minS.top();
	}
private:
	stack<int> minS;
	stack<int> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */