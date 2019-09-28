class Solution {
	class MonotonicQueue{
	private:
		deque<int> q;
	public:
		int max(){
			return q.front();
		}
		void push(int num){
			while(!q.empty() && q.back() < num){
				q.pop_back();
			}
			q.emplace_back(num);
		}
		void pop(){
			q.pop_front();    
		}
		
	};
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		MonotonicQueue q;
		for(int i = 0; i < nums.size(); i++){
			q.push(nums[i]);
			if(i >= k){
				int out = nums[i - k];
				if(q.max() == out){
					q.pop();
				}
			}
			
			if(i >= k -1){
				res.emplace_back(q.max());
			}
		}
		return res;
	}
	
	
	
	vector<int> maxSlidingWindow_bst(vector<int>& nums, int k) {
		vector<int> res;
		multiset<int> window;
		for(int i = 0; i < nums.size(); i++){
			window.insert(nums[i]);
			if(window.size()>=k){
				res.emplace_back(*window.rbegin());
				auto it = window.find(nums[i - k + 1]);
				window.erase(it);
			}
		}
		return res;
	} 
};