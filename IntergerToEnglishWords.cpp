class Solution_Recur {
public:
	vector<string> under20 = {"", "One", "Two", "Three", "Four", "Five", "Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
	vector<string> under100 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
	//0 000 000 000
	
	string helper(int n){
		if(n >= (int)1e9){
			return helper(n / (int)1e9) + " Billion" + helper(n % (int)1e9);
		}
		else if(n >= (int)1e6){
			return helper(n / (int)1e6) + " Million" + helper(n % (int)1e6);
		}
		else if(n >= (int)1e3){
			return helper(n / (int)1e3) + " Thousand" + helper(n % (int)1e3);
		}
		else if(n >= 100){
			return helper(n / 100) + " Hundred" + helper(n % 100);
		}
		else if(n >= 20){
			return " " + under100[n / 10] + helper(n % 10);
		}
		else if(n >0){
			return " " + under20[n];
		}
		return "";
	}
	
	string numberToWords(int num) {
		if(num == 0) return "Zero";
		return helper(num).substr(1);
	}
};

class Solution {
public:
	vector<string> under20 = {"", "One", "Two", "Three", "Four", "Five", "Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
	vector<string> under100 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
	//0 000 000 000
	vector<string> underMax = {"Billion", "Million", "Thousands", ""};
	vector<string> under1000(int n){
		// n < 1000
		vector<string> res;
		if(n >= 100){
			res.emplace_back(under20[n / 100]);
			res.emplace_back("Hundred");
			n%=100;
		}
		if(n >= 20){
			res.emplace_back(under100[n / 10]);
			n%=10;
		}
		if(n > 0){
			res.emplace_back(under20[n]);
		}
		return res;
	}
	string numberToWords(int num) {
		vector<string> res;
		int cur = 0;
		if(num == 0) return "Zero";
		while(num != 0){
			if(num >= 1000000000){
				vector<string> tmp = under1000(num / 1000000000);
				res.insert(res.end(), tmp.begin(), tmp.end());
				res.emplace_back("Billion");
				num %= 1000000000;
			}   
			else if(num >= 1000000){
				vector<string> tmp = under1000(num / 1000000);
				res.insert(res.end(), tmp.begin(), tmp.end());
				res.emplace_back("Million");
				num %= 1000000;
			}
			else if( num >= 1000){
				vector<string> tmp = under1000(num / 1000);
				res.insert(res.end(), tmp.begin(), tmp.end());
				res.emplace_back("Thousand");
				num %= 1000;
			}
			else if(num >= 1) {
				vector<string> tmp = under1000(num);
				res.insert(res.end(), tmp.begin(), tmp.end());
				num %= 1;
			}
		}
		string rtn;
		for(auto s : res){
			rtn+=s + " ";    
		}
		rtn.pop_back();
		return rtn;
	}
};