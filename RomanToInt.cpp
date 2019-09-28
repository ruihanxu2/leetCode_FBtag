int romanToInt(string s) {
	unordered_map <char, int>  dict={{'I',1}, {'V',5}, 
	{'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
	int dec=0;
	for(int i=0;i<s.size()-1;i++){
		if(dict[s[i]]<dict[s[i+1]])
			dec+=-dict[s[i]];
		else
			dec+=dict[s[i]];
	}
	dec+=dict[s.back()];
	return dec;
}

//找规律，罗马数字 只有 IV ：当前小于下一个时候
//才是负的