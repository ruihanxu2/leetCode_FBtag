bool knows(int a, int b);

class Solution {
public:
	int findCelebrity(int n) {
		int candid = 0;
		for(int i = 1; i < n; i++){
			if(knows(i, candid)); // i 不可能是名人
			if(!knows(i, candid)) candid = i;
			// 有人不认识他？不可能是名人
			//get rid of all the person that is not full known by every one
			// but the one left may 1. know someone 2..not full know by everyone
		}
		for(int i = 0; i < n; i++){
			if(i != candid &&(!knows(i, candid) ||knows(candid, i))){
				return -1;
			}
		}
		return candid;
	}
};