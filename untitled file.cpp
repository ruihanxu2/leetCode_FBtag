#include <vector>
#include <iostream>


using namespace std;


void dfs(int pos, long sum, vector<int>& cur, vector<vector<int> >& res, string s, int target, long prevOp){

	
	if(pos == s.size()){
		if(sum == target){
			res.emplace_back(cur);
		}
		return;
	}
	long curNum = prevOp*10 + (s[pos] - '0');
	//+ 
	
	cur.emplace_back(curNum);
	sum+=curNum;
	dfs(pos + 1, sum, cur, res, s, target, 0);
	sum-=curNum;
	cur.pop_back();
	
	
	cur.emplace_back(-curNum);
	sum-=curNum;
	dfs(pos + 1, sum, cur, res, s, target, 0);
	sum+=curNum;
	cur.pop_back();
	
	dfs(pos + 1, sum, cur, res, s, target, curNum);
}



void findNum(string s , int t){
	vector<vector<int> > res;
	vector<int> cur;
	dfs(0, 0, cur, res, s, t, 0);
	for(auto v : res){
		for(auto n : v){
			cout<<n<<" ";
		}
		cout<<endl;
	}
}


int main(){
	
	string a = "123456789";
	int t = 100;
	findNum(a, t);
	return 0;
}