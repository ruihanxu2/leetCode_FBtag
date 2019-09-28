// not duplicate num
// all O(1)
class RandomizedSet {
	unordered_map<int, int> m;// num, pos
	vector<int> nums;
public:
	/** Initialize your data structure here. */
	RandomizedSet() {
		srand(time(NULL));
	}
	
	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if(m.count(val)) return false;
		nums.emplace_back(val);
		m[val] = nums.size() - 1;
		return true;
	}
	
	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if(!m.count(val)) return false;
		int tmp = nums.back();
		nums[m[val]] = tmp;
		m[tmp] = m[val];
		nums.pop_back();
		m.erase(val);
		
		return true;
	}
	
	/** Get a random element from the set. */
	int getRandom() {
		int randomNum = (rand() % nums.size());
		return nums[randomNum];
	}
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

//----------duplicates
class RandomizedCollection {
	vector<int> nums;
	unordered_map<int, unordered_set<int> > m; // num, pos
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {
		srand(time(NULL));
	}
	
	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		bool res = true;
		if(m.count(val)) res = false;
		m[val].insert(nums.size());
		nums.emplace_back(val);
		return res;
	}
	
	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		
		if (m[val].empty()) return false;
		int toChange = nums.size()-1;
		int tmp = nums.back();
		int toRemove = *(m[val].begin()); 
		m[val].erase(toRemove);
		
		nums[toRemove] = tmp;
		m[tmp].insert(toRemove); // order important. if only 1 element available, then no need to update tail element info
		m[tmp].erase(toChange);
			

		nums.pop_back();
		
		return true;
	}
	
	/** Get a random element from the collection. */
	int getRandom() {
		return nums[rand()%nums.size()];
	}
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */