//找到数组里过半的数

//sort find mid
sort(nums.begin(), nums.end());
return nums[(nums.size() - 1) / 2]; 
//hash
unordered_map<int, int> freq;
		int target = nums.size() / 2 + 1;
		for(int n : nums){
			freq[n]++;
			if(freq[n] == target) return n;
		}
		return 0;

//voting algorithm
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int count = 0;
		int candidate;
		for(int n : nums){
			if(count == 0){
				candidate = n;

			}
			
			count += n == candidate ? 1 : -1;
			
		}
		return candidate;
		
	}
};