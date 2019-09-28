class Solution {
public:
	bool isNumber(string s) {
		int i = 0;
		bool numBeforeDeciPoint = false;
		while(isspace(s[i])) i++;
		
		if(s[i] == '+' || s[i] == '-') i++;
		if(!isdigit(s[i]) && s[i]!='.') return false;
		while(isdigit(s[i])){
			numBeforeDeciPoint = true;
			i++;
		}
		if(s[i] == '.'){
			//must flow a digit if not leading dig
			i++;
			if(!numBeforeDeciPoint && !isdigit(s[i])) return false;
			while(isdigit(s[i])) i++;
		}
		if(s[i] == 'e'){
			i++;
			if(s[i] == '+' || s[i] == '-'){
				i++;
			}
			if(!isdigit(s[i])) return false;
			while(isdigit(s[i])) i++;
		}
		
		while(i < s.size()){
			if(!isspace(s[i])) return false;
			i++;
		}
		return true;
	}
};