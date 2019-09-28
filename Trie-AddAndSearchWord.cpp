class WordDictionary {
	struct TrieNode{
		bool isWord = false;
		vector<TrieNode*> children;
		TrieNode(): children(26, nullptr){}
		
		~TrieNode(){
			for(auto a : children){
				if(a) delete a;
			}
		}
		
	};
	TrieNode* root;
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new TrieNode();
	}
	~WordDictionary(){
		delete root;
	}
	/** Adds a word into the data structure. */
	void addWord(string word) {
		TrieNode* cur = root;
		for(auto c : word){
			if(!cur->children[c - 'a']){
				cur->children[c - 'a'] = new TrieNode();
			}
			cur = cur->children[c - 'a'];
		}
		cur->isWord = true;
	}
	
	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return dfs(word, 0, root);
	}
	
	bool dfs(string& word, int pos, TrieNode* cur){    
		if(cur == NULL) {
			return false;
		}
		//!!!!---!!!!!
		if(pos == word.size()) return cur->isWord;
		
		if(word[pos] == '.'){
			for(auto child:cur->children){
				if(dfs(word, pos + 1, child)) return true;
			}
		}
		else{
			return dfs(word, pos + 1, cur->children[word[pos] - 'a']);
		}
		return false;
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */