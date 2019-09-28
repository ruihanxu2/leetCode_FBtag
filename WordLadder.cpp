//BFS, push the word that is only one letter different from the parent
void pushNextWord(string word, unordered_set<string>& dict, queue<string>& q){
	for(int i = 0; i < word.size(); i++){
		char ch = word[i];
		for(int j = 0; j < 26; j++){
			word[i] = 'a' + j;
			if(dict.count(word)){
				q.emplace(word);
				dict.erase(word);
			}
		}
		word[i] = ch;
	}
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	unordered_set<string> dict(wordList.begin(), wordList.end());
	if(!dict.count(endWord)) return 0;
	queue<string> q;
	pushNextWord(beginWord, dict, q);
	int res = 2;
	while(!q.empty()){
		int n = q.size();
		for(int i = 0; i < n; i++){
			string cur = q.front();
			q.pop();
			if(cur == endWord) return res;
			pushNextWord(cur, dict, q);
		}
		res++;
	}
	return 0;
}

//bi-direction BFS
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end()), head, tail, *phead, *ptail;
		if (dict.find(endWord) == dict.end()) {
			return 0;
		}
		head.insert(beginWord);
		tail.insert(endWord);
		int ladder = 2;
		while (!head.empty() && !tail.empty()) {
			if (head.size() < tail.size()) {
				phead = &head;
				ptail = &tail;
			} else {
				phead = &tail;
				ptail = &head;
			}
			unordered_set<string> temp;
			for (auto it = phead -> begin(); it != phead -> end(); it++) {    
				string word = *it;
				for (int i = 0; i < word.size(); i++) {
					char t = word[i];
					for (int j = 0; j < 26; j++) {
						word[i] = 'a' + j;
						if (ptail -> find(word) != ptail -> end()) {
							return ladder;
						}
						if (dict.find(word) != dict.end()) {
							temp.insert(word);
							dict.erase(word);
						}
					}
					word[i] = t;
				}
			}
			ladder++;
			phead -> swap(temp);
		}
		return 0;
	}
};

//------------------------------------print all path-------------------------------------
//method1: BFS the path
// 与之前不同的是，path bfs必须整完了一层之后才能erase 这一层新加的node，否则会导致少解
class Solution {
private:
	vector<vector<string> > res;
	queue<vector<string> > q;
	
	unordered_set<string> visited;
	unordered_set<string> wordList;
	int minLen = INT_MAX;
	string endWord;
public:
	void findNext(string word, vector<string>& curPath){
		for(int i = 0; i < word.size(); i++){
			string next = word;
			for(char c = 'a'; c <= 'z'; c++){
				next[i] = c;
				if(wordList.count(next)){
					vector<string> newPath = curPath;
					newPath.emplace_back(next);
					visited.insert(next);
					if(next == endWord){
						res.emplace_back(newPath);
						minLen = newPath.size();
					}
					else{
						q.emplace(newPath);
					}
				}
			}
		}
	}
	vector<vector<string> > findLadders(string beginWord, string endword, vector<string>& wordlist) {
		q.emplace(vector<string>{beginWord});
		endWord = endword;
		wordList = unordered_set<string>(wordlist.begin(), wordlist.end());
		while(!q.empty()){
		   
			if(q.front().size() > minLen) return res;
			int n = q.size();
			for(auto s:visited) wordList.erase(s);
			visited.clear();
			for(int i = 0; i < n; i++){
				vector<string> curPath = q.front();
				q.pop();
				string lastWord = curPath.back();         
				//find next word;
				findNext(lastWord, curPath);      
			}
		}
		return res;
	}
};


//method2: use a map to record the parent and then backtrack;
class Solution {
	int curLen = INT_MAX;
	vector<vector<string> > res;
	vector<string> curPath;
	unordered_set<string> wordList;
	unordered_map<string, vector<string> > path;
public:
	
	void findNext(unordered_set<string>& nextLevel, string cur){
		for(int i = 0; i < cur.size(); i++){
			for(char c = 'a'; c <= 'z'; c++){
				string next = cur;
				next[i] = c;
				if(wordList.count(next)){
					
					nextLevel.insert(next);
					path[next].emplace_back(cur);
				}
			}
		}
	}
	
	void getPath(string start, string end){
		if(start == end){
			reverse(curPath.begin(), curPath.end());
			res.emplace_back(curPath);
			reverse(curPath.begin(), curPath.end());
		}
		for(string s : path[start]){
			curPath.emplace_back(s);
			getPath(s, end);
			curPath.pop_back();
		}
	}
	vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList_) {
		//dfs is too slow! should use bfs
		unordered_set<string> curLevel;
		unordered_set<string> nextLevel;
		curPath.emplace_back(endWord);
		for(auto& s : wordList_){
			wordList.insert(s);
		}
		
		curLevel.insert(beginWord);
		while(true){
			for(auto w:curLevel){
				wordList.erase(w);
			}
			for(auto w:curLevel){
				findNext(nextLevel, w);
			}
			if(nextLevel.empty()){
				return res;
			} 
			if(nextLevel.count(endWord)){
				getPath(endWord, beginWord);
				return res;
			}
			
			curLevel.clear();
			swap(curLevel, nextLevel);
			
		}
		return res;
		
	}
};
