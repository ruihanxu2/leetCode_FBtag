class Solution {
	struct Node{
		int val; //nums[i][j]
		int i; //ith list
		int j; //jth num
		Node(int a, int b, int c): val(a), i(b), j(c){}
	};
	
	struct Compare{
		bool operator()(const Node& a, const Node& b){
			return a.val > b.val;
		}
		
	};
public:
	vector<int> smallestRange(vector<vector<int>>& nums) {
		//if(nums.size() == 1) return vector<int>{nums[0][0], nums[0][0]};
		priority_queue<Node, vector<Node>, Compare> pq;// min heap
		vector<int> res(2);
		int range = INT_MAX;
		Node maxNode(INT_MIN, -1, -1);
		for(int i = 0; i < nums.size(); i++){
			if(!nums[i].empty()){
				Node tmp(nums[i][0], i, 0);
				pq.emplace(tmp);
				if(tmp.val > maxNode.val){
					maxNode = tmp;
				}
			}
		}

		while(1){
			Node minNode = pq.top();
			pq.pop();
			int curRange = maxNode.val - minNode.val;
			if(curRange < range){
				res[0] = minNode.val;
				res[1] = maxNode.val;
				range = curRange;
			}
			int i = minNode.i;
			int j = minNode.j;
			if(j == nums[i].size() - 1) break;
			
			Node nextNode(nums[i][j + 1], i, j + 1);
			pq.emplace(nextNode);
			if(nextNode.val > maxNode.val){
				maxNode = nextNode;
			}
		}
		return res;
	}
};