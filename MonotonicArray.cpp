
bool isMonotonic(vector<int>& A) {
	bool inc = true;
	bool dec = true;
	for(int i = 0; i < (int)A.size() - 1; i++){
		if(A[i] < A[i + 1]){
			dec = false;
		}
		if(A[i] > A[i + 1]){
			inc = false;
		}
	}
	return inc || dec;
}
