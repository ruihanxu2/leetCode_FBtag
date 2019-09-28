class Solution {
public:
	int minAreaRect(vector<vector<int>>& points) {
		unordered_map<int , unordered_set<int> > m; // x, {y0, y1, y2...}
		for(auto& p : points){
			m[p[0]].insert(p[1]);
		}
		int n = points.size();
		int res = INT_MAX;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				if(points[i][0] != points[j][0] && points[i][1] != points[j][1]){
					
					if(m[points[i][0]].count(points[j][1]) && m[points[j][0]].count(points[i][1])){
						int a = abs((points[i][1] - points[j][1]) * (points[j][0] - points[i][0]));
						res = min(res, a);
					}
				}
			}
		}
		return res == INT_MAX ? 0 : res;
	}
};


class Solution {
public:
	int minAreaRect(vector<vector<int>>& points) 
	{
		int n = points.size();
		map<int, vector<int>> rows;
		
		for (int i = 0; i < n; i++) 
		{
			rows[points[i][0]].push_back(points[i][1]);
		}
		
		for (auto iter1 = rows.begin(); iter1 != rows.end(); iter1++) 
		{
			if (iter1->second.size() >= 2) {
				sort(iter1->second.begin(), iter1->second.end());;
			}
		}

		int ans = INT32_MAX;

		for (auto iter1 = rows.begin(); iter1 != rows.end(); iter1++) 
		{
			if (iter1->second.size() < 2) {
				continue;
			}
			auto iter2 = iter1;
			iter2++;
			for ( ;iter2 != rows.end(); iter2++) 
			{
				if (iter2->second.size() < 2) {
					continue;
				}

				vector<int>& cols1 = iter1->second;
				vector<int>& cols2 = iter2->second;
				int n1 = cols1.size();
				int n2 = cols2.size();
				int i = 0;
				int j = 0;

				int lastSeenCol = -1;

				while (i < n1 && j < n2) 
				{
					if (cols1[i] < cols2[j]) {
						i++;
					}
					else if (cols2[j] < cols1[i]) {
						j++;
						
					} else {
						if (lastSeenCol != -1) {
							int newAns = (cols1[i] - lastSeenCol) * (iter2->first - iter1->first);
							if (newAns < ans) {
								ans = newAns;
							}
						}

						lastSeenCol = cols1[i];
						i++;
						j++;
					}
				} // while
			}
		} // for

		return ans == INT32_MAX ? 0 : ans;
	}
};