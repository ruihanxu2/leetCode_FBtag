class AutocompleteSystem_ {
	struct Info{
		string s;
		int times;
		Info(string s_, int times_) : s(s_), times(times_) {};
		
	};
	struct TrieNode{
		int times = 0;
		vector<TrieNode* > branches;
		TrieNode() : branches(27, 0){};
		~TrieNode(){
			for(int i = 0; i < 27; i++){
				if(branches[i] != NULL){
					delete branches[i];
				}
			}
		}
	};
	int getBranch(char c){
		return c == ' ' ? 26 : c - 'a';
	}
	void insert(TrieNode* node, const string& sentence, int times){
		for(int i = 0; i < sentence.size(); i++){
			if(!node->branches[getBranch(sentence[i])])
				node->branches[getBranch(sentence[i])] = new TrieNode();
			node = node->branches[getBranch(sentence[i])];
		}
		node->times += times;
	}
	vector<Info> search(TrieNode* node){
		vector<Info> res;
		for(int i = 0; i < cur.size(); i++){
			if(!node->branches[getBranch(cur[i])]) return res;
			node = node->branches[getBranch(cur[i])];
		}
		traverse(cur, node, res);
		return res;
	}
	void traverse(string s, TrieNode* node, vector<Info>& res){
		if(node->times > 0) res.emplace_back(Info(s, node->times));
		for(int i = 0; i < 26; i++){
			char next = 'a' + i;
			if(node->branches[i]){
				traverse(s + next, node->branches[i], res);
			}
		}
		if(node->branches[26]){
			traverse(s + ' ', node->branches[26], res);
		}
		
	}
	
	TrieNode* root;
	string cur;
	
	
public:
	AutocompleteSystem_(vector<string>& sentences, vector<int>& times) {
		root = new TrieNode();
		for(int i = 0; i < sentences.size(); i++){
			insert(root, sentences[i], times[i]);
		}
	}
	
	vector<string> input(char c) {
		vector<string> res;
		if(c == '#'){
			insert(root, cur, 1);
			cur = "";
		}
		else{
			cur += c;
			vector<Info > tmp = search(root);
			sort(tmp.begin(), tmp.end(), [](const Info& a, const Info& b){
				if(a.times == b.times) return a.s < b.s;
				return a.times > b.times;
			});
			for(int i = 0; i < min(3, (int)tmp.size()); i++){
				res.emplace_back(tmp[i].s);
			}
		}
		return res;
	}
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

class AutocompleteSystem {
	struct Info{
		string s;
		int times;
		Info(string s_, int times_) : s(s_), times(times_) {};
		
	};
	struct TrieNode{
		int times = 0;
		vector<TrieNode* > branches;
		TrieNode() : branches(27, 0){};
		~TrieNode(){
			for(int i = 0; i < 27; i++){
				if(branches[i] != NULL){
					delete branches[i];
				}
			}
		}
	};
	int getBranch(char c){
		return c == ' ' ? 26 : c - 'a';
	}
	void insert(TrieNode* node, const string& sentence, int times){
		for(int i = 0; i < sentence.size(); i++){
			if(!node->branches[getBranch(sentence[i])])
				node->branches[getBranch(sentence[i])] = new TrieNode();
			node = node->branches[getBranch(sentence[i])];
		}
		node->times += times;
	}
	vector<Info> search(){
		vector<Info> res;
		if(!curNode) return res;
		
		traverse(cur, curNode, res);
		return res;
	}
	void traverse(string s, TrieNode* node, vector<Info>& res){
		if(node->times > 0) res.emplace_back(Info(s, node->times));
		for(int i = 0; i < 26; i++){
			char next = 'a' + i;
			if(node->branches[i]){
				traverse(s + next, node->branches[i], res);
			}
		}
		if(node->branches[26]){
			traverse(s + ' ', node->branches[26], res);
		}
		
	}
	
	TrieNode* root;
	TrieNode* curNode;
	string cur;
	
	
public:
	AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
		root = new TrieNode();
		for(int i = 0; i < sentences.size(); i++){
			insert(root, sentences[i], times[i]);
		}
		curNode = root;
	}
	
	vector<string> input(char c) {
		vector<string> res;
		if(c == '#'){
			insert(root, cur, 1);
			cur = "";
			curNode = root;
		}
		else{
			cur += c;
			if(curNode) curNode = curNode->branches[getBranch(c)];
			else{
				return res;
			}
			vector<Info > tmp = search();
			sort(tmp.begin(), tmp.end(), [](const Info& a, const Info& b){
				if(a.times == b.times) return a.s < b.s;
				return a.times > b.times;
			});
			for(int i = 0; i < min(3, (int)tmp.size()); i++){
				res.emplace_back(tmp[i].s);
			}
		}
		return res;
	}
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */