class TimeMap {
public:
	/** Initialize your data structure here. */
	unordered_map<string, vector<pair<int, string> > > m; // key, time, val
	TimeMap() {
		
	}
	
	void set(string key, string value, int timestamp) {
		m[key].emplace_back(make_pair(timestamp, value)) ;
	}
	
	string get(string key, int timestamp) {
		vector<pair<int, string> >& v =  m[key];
		int l = 0; 
		int r = v.size();
		while(l < r){
			int mid = (l + r) / 2;
			if(v[mid].first <= timestamp){
				l = mid + 1;
			}else{
				r = mid;
			}
		}
		if(l == 0) return "";
		return v[--l].second;
		
	}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */



class TimeMap1 {
public:
	/** Initialize your data structure here. */
	struct Compare{
		bool operator()(const int & a, const int& b ) const{
			return a > b;
		}
	};
	unordered_map<string, map<int, string, Compare>> m; // key, time, val
	TimeMap1() {
		
	}
	
	void set(string key, string value, int timestamp) {
		m[key][timestamp] = value;
	}
	
	string get(string key, int timestamp) {
		for(auto it = m[key].begin(); it!=m[key].end(); it++){
			if(it->first <= timestamp) return it->second;
		}
		return "";
	}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

unordered_map<string, map<int, string>> m;
void set(string key, string value, int timestamp) {
	m[key].insert({ timestamp, value });
}
string get(string key, int timestamp) {
	auto it = m[key].upper_bound(timestamp);
	return it == m[key].begin() ? "" : prev(it)->second;
}