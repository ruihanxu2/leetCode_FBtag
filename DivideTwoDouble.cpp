//Try long divisions!
// 4/9
// 4/333
// 2/7
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if(numerator == 0) return "0";
		string res;
		res += (numerator < 0) ^ (denominator < 0) ? "-" : "";
		long dividend = labs( (long)numerator );
		long divisor = labs( (long)denominator );
		
		long result = dividend/divisor;
		long reminder = dividend%divisor;
		res+=to_string(result);
		if(reminder == 0) return res;
		res+='.';
		unordered_map<long, int> m; // num, pos
		while(reminder != 0){
			if(m.count(reminder)){
				res.insert(m[reminder], "(");
				res+=')';
				return res;
			}
			m[reminder] = res.size();
			reminder*=10;
			res+=to_string(reminder / divisor);
			reminder %= divisor;
		}
		return res;
	}
};
//lc166