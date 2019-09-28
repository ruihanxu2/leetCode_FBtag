class Solution {
public:
	string toGoatLatin(string S) {
		unordered_set<int> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
		istringstream ss(S);
		string res;
		string tmp;
		string append = "";
		while(ss>>tmp){
			append+="a";
			if(vowels.count(tmp[0])){
				tmp+="ma";
			}
			else{
				char c = tmp[0];
				tmp.erase(0, 1);
				tmp+=c;
				tmp+="ma";
			}
			
			tmp+=append;
			res+=tmp+" ";
		}
		res.pop_back();
		return res;
	}
};