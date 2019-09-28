/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

void findSecretWord(vector<string>& wordlist, Master& master) {
	srand(time(NULL));
		for(int i = 0; i< 10; i++){
		string guess = wordlist[rand() % wordlist.size()];
		int x = master.guess(guess);
		vector<string> wordlist2;
		for(int i = 0; i < wordlist.size(); i++){
			if(match(guess, wordlist[i])) wordlist2.emplace_back(wordlist[i]);   
		}
	wordlist = wordlist2;
}
//只有与guess返回值相同的string里
//才有可能是res
//如何选择guess里面猜测的string？一共只有10次机会
//对于每个string 计算与他完全不同的string的个数
//找一个完全不同string个数最少的， 这样被能去掉更多string
//如果找数量多的，一堆string都跟他不同 如果 他不是答案，那些跟他不同的全部要进入下一轮

class Solution {
public:
	int match(string a, string b){
		int res = 0;
		for(int i = 0; i < a.size(); i++){
			if(a[i] == b[i]) res++;
		}
		return res;
	}
	void findSecretWord(vector<string>& wordlist, Master& master) {
		for(int i = 0; i < 10; i ++){
			unordered_map<string, int> freq;
			for(auto w1 : wordlist){
				for(auto w2 : wordlist){
					if(match(w1, w2) == 0){
						freq[w1]++;
					}
				}
			}
			pair<string, int> cur = make_pair(wordlist[0], freq[wordlist[0]]); // find the string that match with others most
			for(auto p  : freq){''
				if(p.second < cur.second){
					cur = p;
				}
			}
			cout<<cur.first<<endl;
			int x = master.guess(cur.first);
			if(x == 6) break;
			vector<string> tmp;
			for(auto w : wordlist){
				if(match(w, cur.first) == x){
					tmp.emplace_back(w);
				}    
			}
			wordlist = tmp;
		}
	}
};


