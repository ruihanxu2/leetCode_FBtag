/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
   stack<NestedInteger> s;
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		int n = nestedList.size();
		for(int i = n - 1; i >= 0; i--){
			s.emplace(nestedList[i]);
		}
	}

	int next() {
		int res = s.top().getInteger();
		s.pop();
		return res;
	}

	bool hasNext() {
		while(!s.empty()){
			auto cur = s.top();
			if(cur.isInteger()) return true;
			s.pop();
			auto list = cur.getList();
			for(int i = (int)list.size() - 1; i >=0; i--){
				s.emplace(list[i]);
			}
			
		}
		return false;
		
	}
};

class NestedIterator {
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		begins.emplace(nestedList.begin());
		ends.emplace(nestedList.end());
	}

	int next() {
		int res = begins.top()->getInteger();
		 begins.top()++;
		return res;
	}
	bool hasNext() {
		while(begins.size()){
			if(begins.top() == ends.top()){
				begins.pop();
				ends.pop();
			}
			else{
				auto cur = begins.top();
				if(cur->isInteger()) return true;
				
				begins.top()++;
				begins.emplace(cur->getList().begin());
				ends.emplace(cur->getList().end());
			}
		}
		return false;
	}

private:
	stack<vector<NestedInteger>::iterator> begins, ends;
};
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */