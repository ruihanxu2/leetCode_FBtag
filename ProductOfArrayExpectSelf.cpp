//On On
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int> lr(n, 1);
		vector<int> rl(n, 1);
		for(int i = 1; i < n; i++){
			lr[i] = nums[i - 1] * lr[i - 1];
		}
		for(int i = n - 2; i>=0; i--){
			rl[i] = nums[i + 1] * rl[i + 1];
		}
		vector<int> res(n, 0);
		for(int i = 0; i < n; i++){
			res[i] = lr[i] * rl[i];
		}
		return res;
		
	}
};

//On O1
// 就把rl array 用一个tmp表示 construct res on the run
vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int> res(n, 1);
		for(int i = 1; i < n; i++){
			res[i] = res[i - 1] * nums[i - 1];
		}
		int rightProduct = 1;
		for(int i = n - 1; i >= 0; i--){
			res[i] = res[i] * rightProduct;
			rightProduct*=nums[i];
		}
		return res; 
	}
//Return a array of product of the array expect self