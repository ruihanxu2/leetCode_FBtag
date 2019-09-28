class Solution {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
		int n1 = A.size();
		int n2 = B.size();
		int j = 0;
		int i = 0;
		vector<vector<int>> res;
		while(i < n1 && j < n2){
			int low = max(A[i][0], B[j][0]);
			int high = min(A[i][1], B[j][1]);
			if(low <= high){
				res.emplace_back(vector<int>{low, high});
			}
			if(A[i][1] < B[j][1]) i++;
			else j++;
		}
		return res;
	}
};