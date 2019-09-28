int maxArea(vector<int>& height) {
	int n = height.size();
	int left = 0;
	int right = n - 1;
	int res = 0;
	while(left < right){
		res =max(res, min(height[left], height[right]) * (right - left));
		height[left] < height[right] ? left++ : right--;
	}
	return res;
}

// greedy, two pointer 从两边走
// 每次只移动矮的那个
// 如果一样移动哪个都无所谓 
//1. 不是最好， 有两个比他俩高的 2. 是最好