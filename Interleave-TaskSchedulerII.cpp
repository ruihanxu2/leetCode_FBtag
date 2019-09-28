/*
Task Scheduler
1.每个task运行完后有m个cool down period，在这期间不可以运行同样的task
2.cooldown period里可以随便运行其他的task
3.不能改变运行的顺序

例题：
[1, 1, 2, 1, 2] M = 2

运行方式：
1 _ _ 1 2 _ 1 2
output: 8 （需要8个time unit）

followup：
如果m远远小于k（k是task种类数，怎么优化）
用lru cache优化。。。代码没写完，于是gg了。

*/
// 1 -> 3
// 

//time
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

int calcTime(vector<int> tasks, int k){
	unordered_map<int, int> m; // task -> last time
	int cycle = 0;
	for(auto t : tasks){
		if(!m.count(t)){
			m[t] = cycle;
			cycle++;
		}
		else{
			// have run
			// a b c 
			int pastCycle = cycle - m[t];
			if(pastCycle <= k){
				// cannot put, put idle
				cycle = m[t] + k + 1;
				m[t] = cycle;
				cycle++;
			}
			else{
				m[t] = cycle;
				cycle++;
			}
		}
	}
	return cycle;
}

int main(int argc, char *argv[]) {
	int a = calcTime(vector<int>{1, 1, 2, 1, 2}, 2);
	cout<<a;
	return 0;
	
}
//
//
//class LRUCache {
//private:
//	list<pair<int, int> > cache; // task, time
//	unordered_map<int, list<pair<int, int> >::iterator> dict;
//	int capacity;
//public:
//	LRUCache(int capacity) {
//		this->capacity = capacity;
//	}
//	
//	int get(int key) {
//		if(!dict.count(key)) return -1;
//		auto it = dict[key];
//		cache.splice(cache.begin(), cache, it);
//		return it->second;
//	}
//	
//	void put(int key, int value) {
//		if(dict.count(key)){
//			dict[key]->second = value;
//			auto it = dict[key];
//			cache.splice(cache.begin(), cache, it);
//		}
//		else{
//			if(cache.size() == capacity){
//				// need to pop
//				auto toPop = cache.back();
//				cache.pop_back();
//				dict.erase(toPop.first);
//			}
//			cache.emplace_front(make_pair(key, value));
//			dict[key] = cache.begin();
//		}
//	}
//};
//

