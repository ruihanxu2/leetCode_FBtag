class Solution {
public:
	int findMaxLen(vector<int> wood, int k) {
		int l = 1;
		int r = *max_element(wood.begin(), wood.end());
		int res;
		while (l<r) {
			int mid = l + (r-l)/2;
			if (isValid(wood, mid, k) < k) {
				r = mid-1;    
			}
			else {
				res = mid;
				l = mid + 1;    
			}
		}
		return res;
	}
private:
	int isValid(vector<int> wood, int len, int k) {
		int count = 0;
		for (int val : wood) {
			count += val/len;
		}
		return count;
	}
};
int main() {
	Solution s = Solution();
	vector<int> wood = {5,9,7};
	
	cout << s.findMaxLen(wood, 3);
}

/*
Given an int array wood representing the length of n pieces of wood and an int k. It is required to cut these pieces of wood such that more or equal to k pieces of the same length len are cut. What is the longest len you can get?

Example 1:

Input: wood = [5, 9, 7], k = 3
Output: 5
Explanation: 
5 -> 5
9 -> 5 + 4
7 -> 5 + 2
Example 2:

Input: wood = [5, 9, 7], k = 4
Output: 4
Explanation: 
5 -> 4 + 1
9 -> 4 * 2 + 1
7 -> 4 + 3

*/