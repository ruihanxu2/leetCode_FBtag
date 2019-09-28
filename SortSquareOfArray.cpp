//two pointer
vector<int> sortedSquares(vector<int>& A) {
	int neg = 0;
	int pos = 0;
	for(pos = 0; pos < A.size(); pos++){
		if(A[pos] >= 0){
			neg = pos - 1;
			break;
		}
	}
	vector<int> res;
	while(neg >= 0 && pos < A.size()){
		if(A[neg]*A[neg] > A[pos]*A[pos]){
			res.emplace_back(A[pos]*A[pos++]);
		}
		else{
			res.emplace_back(A[neg]*A[neg--]);
		}
	}
	while(neg >= 0){
		res.emplace_back(A[neg]*A[neg--]);
	}
	while(pos < A.size()){
		res.emplace_back(A[pos]*A[pos++]);
	}
	return res;
}
};
//sort
class Solution_sort {
public:
	struct Compare{
		bool operator()(const int& a, const int& b){
			return abs(a) < abs(b);
		}
	}compare;
	vector<int> sortedSquares(vector<int>& A) {
		sort(A.begin(), A.end(), compare);
		for(auto& n : A){
			n = n*n;
		}
		return A;
	}
};