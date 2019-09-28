
vector<vector<int> > multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
	vector<vector<int> > res;
	int Arow = A.size();
	int Brow = B.size();
	if(Arow == 0 || Brow == 0) return res;
	int Acol = A[0].size();
	int Bcol = B[0].size();
	if(Acol == 0 || Bcol == 0) return res;
	res.resize(Arow, vector<int>(Bcol, 0));
	unordered_set<int> ANonZero; // row
	unordered_set<int> BNonZero; // col
	for(int i = 0; i < Arow; i++){
		for(int j = 0; j < Acol; j++){
			if(A[i][j]!=0){
				ANonZero.insert(i);
				break;
			}    
		}
	}
	for(int j = 0; j < Bcol; j++){
		for(int i = 0; i < Brow; i++){
			if(B[i][j]!=0){
				BNonZero.insert(j);
				break;
			}  
		}
	}
	for(int i = 0; i < Arow; i++){
		for(int j = 0; j < Bcol; j++){
			if(ANonZero.count(i) && BNonZero.count(j)){
				for(int k = 0; k < Acol; k++){
					res[i][j]+=A[i][k]*B[k][j];
				}
			}
		}
	}
	return res;
}
