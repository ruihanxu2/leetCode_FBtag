string simplifyPath(string path) {
	string res;
	vector<string> s;
	stringstream ss(path);
	string tmp;
	while(getline(ss, tmp, '/')){
		if(tmp == "" || tmp == ".") continue;
		else if(tmp == ".."){
			if(!s.empty()) s.pop_back();
		}
		else{
			s.emplace_back(tmp);
		}
	}
	for(string str : s){
		res+="/" + str;
	}
	return res.size() == 0 ? "/" : res;
}
