class Solution {
public:
	vector<vector<int>> verticalOrder(TreeNode* root) {
		map<int, vector<int> > m; // pos , val
		queue<pair<TreeNode*, int> > q;
		vector<vector<int>> res;
		if(root) q.push({root, 0});
		while(!q.empty()){
			auto cur = q.front();
			q.pop();
			m[cur.second].emplace_back(cur.first->val);
			if(cur.first->left) q.push({cur.first->left, cur.second - 1});
			if(cur.first->right) q.push({cur.first->right, cur.second + 1 });
		}
		for(auto& p : m){
			res.emplace_back(p.second);
		}
		return res;
	}
};

//LC987 有顺序要求
class Solution {
public:
	struct Info{
		int level;
		int val;
		Info(int a , int b) : level(a), val(b){}
	};
	struct Compare{
		bool operator()(const Info& a, const Info& b){
			if(a.level!=b.level) return a.level < b.level;
			return a.val<b.val;
		}
	}compare;
	
	void dfs(TreeNode* node, map<int, vector<Info> >& location, int level, int pos){
		if(!node) return;
		location[pos].emplace_back(Info(level, node->val));
		dfs(node->left, location, level + 1, pos - 1);
		dfs(node->right, location, level + 1, pos + 1);
		
	}
	
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		map<int, vector<Info> > location;
		dfs(root, location, 0 , 0);
		vector<vector<int>> res;
		for(auto& p : location){
			
			sort(p.second.begin(), p.second.end(), compare);
			vector<int> tmp;
			for(auto i : p.second){
				tmp.emplace_back(i.val);
			}
			res.emplace_back(tmp);
		}
		return res;
	}
};