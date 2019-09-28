// use sweepline.
// if entry point and the point is higher than the current heightes, it is a key val. 
// Then put it to the heights

// if leaving point and it  higher than the current heightest except itself, that heightest is a key val. (remove from the ds first)


class Solution {
	struct Compare{
	   bool operator()(const vector<int>& a, const vector<int>& b){
		   if(a[0] == b[0]) return a[1] > b[1]; 
		   // put entry point in front of leaving point
		   return a[0] < b[0];
	   }
	}compare;
	
	multiset<int> heights;
	int maxHeights(){
		if(heights.empty()) return 0;
		return *heights.rbegin();
	}
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		vector<vector<int> > lines;
		for(auto& b : buildings){
			lines.emplace_back(vector<int>{b[0], b[2]}); 
			// entry point : x, height
			lines.emplace_back(vector<int>{b[1], -b[2]});
			// leaving point : x, -height
		}
		sort(lines.begin(), lines.end(), compare);
		vector<vector<int> > res;
		for(const auto& line : lines){
			int x = line[0];
			bool entryPoint = line[1] > 0;
			int h = abs(line[1]);
			if(entryPoint){
				if(h > maxHeights()){
					res.emplace_back(line);
				}
				heights.insert(h);
			}
			else{//leaving point
				heights.erase(heights.find(h));
				if(h > maxHeights()){
					res.emplace_back(vector<int>{x, maxHeights()});
				}
			}
		}
		return res;
		
	}
};