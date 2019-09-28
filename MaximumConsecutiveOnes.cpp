
int longestOnes(vector<int>& A, int K) {
	int res = 0;
	int left = 0;
	int right = 0;
	for(; right < A.size(); right++){
		if(A[right] == 0){
			K--;
			while(K < 0){
				if(A[left] == 0) {
					K++;
				}
				left++;
			}
		}
		res = max(res, right - left + 1);
	}
	return res;
}

int longestOnes(vector<int>& A, int K) {
	int i = 0, j;
	for (j = 0; j < A.size(); ++j) {
		if (A[j] == 0) K--;
		if (K < 0 && A[i++] == 0) K++;
	}
	return j - i;
}