class MedianFinder {
	priority_queue<int> rightQueue;
	priority_queue<int, vector<int>, greater<int> > leftQueue;
public:
	/** initialize your data structure here. */
	MedianFinder() {
		
	}
	
	void addNum(int num) {
		// 左边堆始终等于右边或者比右边多一个
		leftQueue.emplace(num);
		rightQueue.emplace(leftQueue.top());
		leftQueue.pop();
		if(leftQueue.size() < rightQueue.size()){
			leftQueue.emplace(rightQueue.top());
			rightQueue.pop();
		}
	}
	
	double findMedian() {
		return leftQueue.size() > rightQueue.size() ? leftQueue.top() : (leftQueue.top() + rightQueue.top()) / 2.0;
	}
};
