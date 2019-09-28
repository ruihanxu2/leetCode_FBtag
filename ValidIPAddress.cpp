// illegal character
// string lenght
// leading zero
// num range
class Solution {
public:
	string parseIPV4(string IP){
		istringstream iss(IP);
		string tmp;
		for(int i = 0; i < 4; i++){
			if(!getline(iss, tmp, '.')) return "Neither";
			for(auto& c : tmp){
				if(!isdigit(c)) return "Neither";
			}
			if(tmp.size() == 0 || tmp.size() > 3) return "Neither";
			if(tmp[0] == '0' && tmp.size() > 1) return "Neither";
			
			int cur = stoi(tmp);
			
			if(cur > 255) return "Neither";
		}
		return iss.eof() ? "IPv4" : "Neither";
	}
	string parseIPV6(string IP){
		string dict = "0123456789ABCDEFabcdef";
		istringstream iss(IP);
		string tmp;
		for(int i = 0; i < 8; i++){
			if(!getline(iss, tmp, ':')) return "Neither";
			for(auto& c : tmp){
				if(dict.find(c) == string::npos) return "Neither";
			}
			if(tmp.size() == 0 || tmp.size() > 4) return "Neither";
		}
		return iss.eof() ? "IPv6" : "Neither";
	}
	string validIPAddress(string IP) {
		if(IP.find('.')!=string::npos){
			return parseIPV4(IP);
		}else if(IP.find(':')!=string::npos){
			return parseIPV6(IP);
		}else{
			return "Neither";
		}
	}
};