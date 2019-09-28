/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};
*/
class SolutionDFS {
	unordered_map<Node*, Node*> m; // original graph and cloned graph;
public:
	Node* cloneGraph(Node* node) {
		if(!node) return NULL;
		if(!m.count(node)){
			Node* newNode = new Node(node->val);
			m[node] = newNode;
			for(auto nei : node->neighbors){
				newNode->neighbors.emplace_back(cloneGraph(nei));
			}
		}
		return m[node];
		
	}
};

class Solution {
public:
	Node* cloneGraph(Node* node) {
		queue<Node*> q;
		unordered_map<Node*, Node*> m;
		m[node] = new Node(node->val);
		
		q.emplace(node);
		while(!q.empty()){
			Node* cur = q.front();
			q.pop();
			for(auto* nei : cur->neighbors){
				if(!m.count(nei)){
					m[nei] = new Node(nei->val);
					q.emplace(nei);
				}
				m[cur]->neighbors.emplace_back(m[nei]);
			}
		}
		return m[node];
	}
};