class Solution {
public:
	//M + N
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> s(nums1.begin(), nums1.end());
		vector<int> res; 
		for(auto& n : nums2){
			if(s.count(n)){
				s.erase(n);
				res.emplace_back(n);
			}
		}
		return res;
	}
};

class Solution2 {
public:
	//NlogN + MlogM + NLogM
	//good if nums1 short nums2 very long
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		vector<int> res;
		for(int i = 0; i < nums1.size(); i++){
			if(i > 0 && nums1[i]==nums1[i-1]) continue;
			auto it = lower_bound(nums2.begin(), nums2.end(), nums1[i]);
			if(it!=nums2.end()){
				int num2 = *it;
				if(num2 == nums1[i]){
				if(!res.empty() && res.back() == num2) continue;
				res.emplace_back(num2);
				}
			}
		}
		return res;
	}
};


//------------------------output not unique
class Solution__ {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		int p1 = 0;
		int p2 = 0;
		int n1 = nums1.size();
		int n2 = nums2.size();
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		
		vector<int> res;
		while(p1 < nums1.size() && p2< nums2.size()){
			if(nums1[p1] == nums2[p2]){
				res.emplace_back(nums1[p1]);
				p1++;
				p2++;
			}
			else if(nums1[p1] < nums2[p2]){
				p1++;
			}
			else{
				p2++;
			}
		}
		return res;
	}
};

class Solution_ {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		unordered_map<int, int> f1;
		for(auto n : nums1){
			f1[n]++;
		}

		for(auto n:nums2){
			if(f1.count(n) && f1[n] > 0){
				f1[n]--;
				res.emplace_back(n);
			}
		}
		return res;
	}
};

// bs
class Solution {
	int lowerbound(vector<int>& n, int target){
		int l = 0;
		int r = n.size();
		while(l < r){
			int mid = (l + r) / 2;
			if(n[mid] < target){
				l = mid + 1;
			}
			else{
				r = mid;
			}
		}
		return l;
	}
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size();
		int n2 = nums2.size();
		if(!n1||!n2) return vector<int>();
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int p = 0;
		vector<int> res;
		for(; p < nums1.size(); ){
			int num2Pos = lowerbound(nums2, nums1[p]);
			int count1 = 0;
			int count2 = 0;
			int i = p;
			while(i < nums1.size() && nums1[i] == nums1[p]){
				i++;
				count1++;
			}
			
			
			while(num2Pos < nums2.size() && nums2[num2Pos] == nums1[p]){
				num2Pos++;
				count2++;
			}
			res.insert(res.end(), min(count1, count2), nums1[p]);
			p = i;
		}
		return res;
	}
	
};