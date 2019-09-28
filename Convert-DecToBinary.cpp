string toHex(int num) {
	if(num == 0) return "0";
	string m = "0123456789abcdef";
	string res;
	int mask = 15;
	
	for(int i = 0; i < 8; i++){
		res+=m[mask & num];
		num>>=4;
	}
	for(int i = 7; i >= 0; i--){
		if(res[i]=='0') res.pop_back();
		else{
			break;
		}
	}
	reverse(res.begin(), res.end());
	return res;
}
