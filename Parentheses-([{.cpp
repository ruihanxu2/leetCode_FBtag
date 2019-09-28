bool isValid(string s) {
	stack<char> S;
	bool res = true;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == '('||s[i] == '['||s[i] == '{')
			S.push(s[i]);
		else if (S.empty()) return false;
		else{
			char top = S.top();
			if(top == '('){
				if(s[i] != ')') return false;
			}
			else if(top == '['){
				if(s[i] != ']') return false;
			}
			else if(top == '{'){
				if(s[i] != '}') return false;
			}
			//match
			S.pop();
		}
	}
	return S.empty()? true:false;
}
//如果右括号，stacktop必须对应左括号