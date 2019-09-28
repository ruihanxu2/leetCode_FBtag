class MyCircularQueue {
private:
	vector<int> data;
	int front;
	int back; // q.end();
	int capacity;
	int size;
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		capacity = k;
		data.resize(k, 0);
		size = 0;
		front = 0;
		back = 0;
	}
	
	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if(isFull()) return false;
		data[back] = value;
		back = (back + 1) % capacity;
		size++;
		return true;
		
	}
	
	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if(isEmpty()) return false;
		front = (front + 1) % capacity;
		size--;
		return true;
	}
	
	/** Get the front item from the queue. */
	int Front() {
		if(isEmpty()) return -1;
		return data[front];
	}
	
	/** Get the last item from the queue. */
	int Rear() {
		if(isEmpty()) return -1;
		if(back!=0) return data[back - 1];
		return data.back();
	}
	
	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		if(size == 0) return true;
		return false;
	}
	
	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		if(size == capacity) return true;
		return false;
	}
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */