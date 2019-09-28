class Solution_ {
public:
	vector<vector<int>> points;
	struct Compare{
		int distance(const vector<int>& point){
			return point[0] * point[0] + point[1] * point[1];
		}
		bool operator()(const vector<int>& a, const vector<int>& b){
			return distance(a) < distance(b);
		}
	};
	vector<vector<int>> kClosest(vector<vector<int>>& Points, int K) {
		points = Points;
		nth_element(points.begin(), points.begin() + K, points.end(), Compare());
		return vector<vector<int>>(points.begin(), points.begin() + K);
	}
};
class Solution_implementQuickSort {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& Points, int K) {
		points = Points;
		kthSmallest(0, points.size() - 1, K);
		return vector<vector<int>>(points.begin(), points.begin() + K);
	}
private:
	int dist(int idx){
		return points[idx][0] * points[idx][0] + points[idx][1] * points[idx][1];
	}
	vector<vector<int>> points;
	int partition(int l, int r) {
		//similar to the move zero problem
		int x = dist(r);
		int firstElementLargerThanX = l;
		for (int j = l; j <= r - 1; j++) { 
			if (dist(j) <= x) { 
				swap(points[firstElementLargerThanX], points[j]); 
				firstElementLargerThanX++; 
			} 
		} 
		swap(points[firstElementLargerThanX], points[r]); 
		return firstElementLargerThanX; 
	} 
	int kthSmallest(int l, int r, int k) { 
		if (k > 0 && k <= r - l + 1) { 
			int index = partition(l, r); 
			// if (index - l == k - 1) 
			//     return points[index]; 
			int leftLen = index - l + 1;
			if (leftLen > k ) {
				return kthSmallest(l, index - 1, k); 
			}
			else{
				return kthSmallest(index + 1, r, k - leftLen); 
			}
			
		} 
		return INT_MAX; 
	} 

};

class Solution_MaxPQ {
public:
	struct Compare{
		int distance(const vector<int>& point){
			return point[0] * point[0] + point[1] * point[1];
		}
		bool operator()(const vector<int>& a, const vector<int>& b){
			return distance(a) < distance(b);
		}
	};
	
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
		for(auto point : points){
			pq.emplace(point);
			if(pq.size() > K){
				pq.pop();
			}
		}
		vector<vector<int> > res;
		while(!pq.empty()){
			res.emplace_back(pq.top());
			pq.pop();
		}
		return res;
	}
};
