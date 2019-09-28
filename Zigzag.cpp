string convert(string s, int n) {
	if(n==1) return s;
	int strSize=s.size();
	vector<string> res(min(strSize, n));
	int dr=1;
	int rowNum=0;
	for(int i=0; i<s.size(); i++){
		res[rowNum]+=s[i];
		
		if(rowNum==n-1) dr=-1;
		if(rowNum==0) dr=1;
		
		rowNum+=dr;
		
	}
	string str="";
	for(string s:res){
		str+=s;
	}
	return str;
}