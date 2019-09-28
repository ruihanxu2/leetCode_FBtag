class Solution{
private:
	struct Element{
		bool isOperator = false;
		int val = 0;
		char op = '+';
	};
public:
	int calc(int l , int r, char op){
		switch(op){
			case '+': return l + r;
			case '-': return l - r;
			case '*': return l * r;
			case '/': return l / r;
            default : return 0;
		}
        
	}
	int getPrec(char op){
			switch(op){
				case '+': return 1;
				case '-': return 1;
				case '*': return 2;
				case '/': return 2;
                default : return 0;
			}
		}
	int evalPostfix(vector<Element> postfix){
		stack<int> s;
		for(int i = 0; i < postfix.size(); i++){
			if(postfix[i].isOperator){
				int r = s.top();
				s.pop();
				int l = s.top();
				s.pop();
				s.emplace(calc(l, r , postfix[i].op));
			}
			else{
				s.emplace(postfix[i].val);
			}
		}
		return s.top();
	}
	vector<Element> infix2Postfix(string s){
		vector<Element> res;
		stack<char> operatorStack;
		int n = s.size();
		for(int l = 0, r = 0; l < n ; r++, l = r){
			if(isdigit(s[r])){
				while(isdigit(s[r])){
					r++;
				}
				int val = stoi(s.substr(l, r - l));
				r--;
				Element cur;
				cur.val = val;
				res.emplace_back(cur);
			}
            else if(s[r] == ' '){
				continue;
			}
			else if(s[r] == '('){
				operatorStack.emplace('(');
			}
			else if(s[r] == ')'){
				while(!operatorStack.empty() && operatorStack.top() != '('){
					char c = operatorStack.top();
					operatorStack.pop();
					Element top;
					top.isOperator = true;
					top.op = c;
					res.emplace_back(top);
				}
				operatorStack.pop();
			}
			else{
				// op
				char cur = s[r];
				while(!operatorStack.empty() && getPrec(operatorStack.top()) >= getPrec(s[r])){
					char c = operatorStack.top();
					operatorStack.pop();
					Element top;
					top.isOperator = true;
					top.op = c;
					res.emplace_back(top);
				}
				operatorStack.emplace(cur);
			}
		}
        while(!operatorStack.empty()){
					char c = operatorStack.top();
					operatorStack.pop();
					Element top;
					top.isOperator = true;
					top.op = c;
					res.emplace_back(top);
				}
        return res;
	}
	int calculate(string s){
        
        vector<Element> postfix = infix2Postfix(s);
		return evalPostfix(postfix);
	
    }
	
};