bool isNumber(string str) {
	int state=0, flag=0; // flag to judge the special case "."
	while(str[0]==' ')  str.erase(0,1);//delete the  prefix whitespace 
	while(str[str.length()-1]==' ') str.erase(str.length()-1, 1);//delete the suffix whitespace
	for(int i=0; i<str.length(); i++){
		if('0'<=str[i] && str[i]<='9'){
			flag=1;
			if(state<=2) state=2;
			else state=(state<=5)?5:7;
		}
		else if('+'==str[i] || '-'==str[i]){
			if(state==0 || state==3) state++;
			else return false;
		}
		else if('.'==str[i]){
			if(state<=2) state=6;
			else return false;
		}
		else if('e'==str[i]){
			if(flag&&(state==2 || state==6 || state==7)) state=3;
			else return false;
		}
		else return false;
	}
	return (state==2 || state==5 || (flag&&state==6) || state==7);
}

//https://leetcode.com/problems/valid-number/discuss/23725/C%2B%2B-My-thought-with-DFA
状态机器。。


bool isNumber(string s) {
	int i = 0;
	bool flag = false;
	// preceding space
	while(s[i] == ' ') ++i;
	// sign
	if(s[i] == '+'||s[i] == '-') ++i;
	//must folow a digi
	if(!isdigit(s[i])&&s[i]!='.') return false;
	
	while(isdigit(s[i])){
		++i;
		flag = true;
	}
	if(s[i] == '.'){
		++i;
		//'.' must followed by a number
		if(!flag&&!isdigit(s[i])) return false;
		while(isdigit(s[i])) ++i;
	}
	
	if(s[i] == 'e'){
		++i;
		if(s[i] == '+'||s[i] == '-') ++i;
		if(!isdigit(s[i])) return false;
		while(isdigit(s[i])) ++i;
	}
	
	while(s[i]!='\0'){
		if(s[i]!=' ') return false;
		i++;
	}
	return true;
	
}