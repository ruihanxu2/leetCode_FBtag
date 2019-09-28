// top right to bottom left then reverse one by one
class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		vector<vector<int> > tmp;
		int r = matrix.size();
		if(r == 0) return res;
		int c = matrix[0].size();
		if(c == 0) return res;
		for(int j = 0; j < c; j++){
			vector<int> cur;
			int i = 0;
			int col = j;
			while(i < r && col >=0){
				cur.emplace_back(matrix[i++][col--]);
			}
			tmp.emplace_back(cur);
		}
		for(int i = 1; i < r; i++){
			vector<int> cur;
			int j = c - 1;
			int row = i;
			while(row < r && j >=0){
				cur.emplace_back(matrix[row++][j--]);
			}
			tmp.emplace_back(cur);
		}
		for(int i = 0; i < tmp.size(); i++){
			if(i % 2 == 0){
				reverse(tmp[i].begin(), tmp[i].end());
			}
			res.insert( res.end(), tmp[i].begin(), tmp[i].end());
		}
		return res;
	}
};
// change dir
class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		int i = 0, j = 0;
		int m = matrix.size();
		vector<int> res;
		if ( m == 0 ) return res;
		int n = matrix[0].size();
		bool up = true;
		
		while( true )
		{
			ans.push_back( matrix[i][j] );
			
			if( i == ( m-1 ) && j == (n-1) ) break;
			
			if( up ){
				--i; ++j;
			}
			else{
				++i; --j;
			}
			
			if( i > m-1 ) { i = m-1; up = true; j = j + 2; }
			else if( j > n-1 ) { j = n-1; up = false; i = i + 2; }
			else if( i < 0 ) { i = 0; up = false; }
			else if( j < 0 ) { j = 0; up = true; }
		}
		
		return res;
	}
};
// index of sum is K
class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		if (matrix.empty()) {
			return {};
		}
		const int m = matrix.size();
		const int n = matrix[0].size();
		vector<int> r;
		r.reserve(m * n);
		for (int k = 0; k <= m + n - 2; k++) {
			const int start = max(0, k - n + 1);
			const int end = min(m - 1, k);
			if ((k % 2) == 0) {
				for (int i = end; i >= start; i--) {
					r.push_back(matrix[i][k - i]);
				}
			}
			else {
				for (int i = start; i <= end; i++) {
					r.push_back(matrix[i][k - i]);
				}
			}
		}
		return r;
	}
};