string multiply(string num1, string num2) {
	int n1 = num1.size();
	int n2 = num2.size();
	vector<int> res(n1+n2, 0);
	for(int i = n1-1; i >=0 ; i--){
		for(int j = n2 - 1; j >= 0; j--){
			int a = num1[i] - '0';
			int b = num2[j] - '0';
			int mul = a * b;
			int pos = n1 + n2 -2 -i -j;
			res[pos] += a * b;
			res[pos+1] += res[pos] / 10;
			res[pos] %= 10;
			
		}
	}
	//reverse(res.begin(), res.end());
	while(res.back() == 0&&res.size() > 1){
		res.pop_back();
	}
	string s;
	for(auto it = res.rbegin(); it!=res.rend(); it++ ){
		s+=(*it + '0');
	}
	return s;
}
