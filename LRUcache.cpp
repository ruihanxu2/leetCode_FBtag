class LRUCache {
private:
	list<pair<int, int> > cache; // key value
	unordered_map<int, list<pair<int, int> >::iterator> dict;
	int capacity;
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}
	
	int get(int key) {
		if(!dict.count(key)) return -1;
		auto it = dict[key];
		cache.splice(cache.begin(), cache, it);
		return it->second;
	}
	
	void put(int key, int value) {
		if(dict.count(key)){
			dict[key]->second = value;
			auto it = dict[key];
			cache.splice(cache.begin(), cache, it);
		}
		else{
			if(cache.size() == capacity){
				// need to pop
				auto toPop = cache.back();
				cache.pop_back();
				dict.erase(toPop.first);
			}
			cache.emplace_front(make_pair(key, value));
			dict[key] = cache.begin();
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */