class Solution_ {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int> > pq;
		for(auto num : nums){
			pq.emplace(num);
			if(pq.size() > k){
				pq.pop();
			}
		}
		return pq.top();
	}
};

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int> pq(nums.begin(), nums.end());
		int res = 0;
		while(k-- > 0){
			res=pq.top();
			pq.pop();
		}
		return res;
	}
};

class Solution__ {
public:
	int findKthLargest(vector<int>& nums, int k) {
		nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
		return nums[k - 1];
	}
};