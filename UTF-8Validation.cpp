class Solution {
public:
	bool validUtf8(vector<int>& data) {
		int cnt = 0;
		for (int d : data) {
			if (cnt == 0) {
				if (d >> 5 == 0b110)
					cnt = 1;
				else if (d >> 4 == 0b1110)
					cnt = 2;
				else if (d >> 3 == 0b11110)
					cnt = 3;
				else if (d >> 7)
					return false;
			}
			else {
				if (d >> 6 != 0b10)
					return false;
				cnt--;
			}
		}
		return cnt == 0;
	}
	bool validUtf8_(vector<int>& data) {
		int numOfBytesToProcess = 0;
		int mask1 = 1 << 7;
		int mask2 = 1 << 6;
		
		for(int n : data){
			
			if(numOfBytesToProcess == 0){
				int mask = mask1;
				while((n & mask) != 0){
					numOfBytesToProcess++;
					mask = mask >> 1;
				}
				if(numOfBytesToProcess == 0){
					continue;
				}
				if(numOfBytesToProcess == 1 || numOfBytesToProcess > 4){
					return false;
				}
			}
			else{
				if(!((n & mask1) != 0 && (n & mask2) == 0)) return false;
			}
			numOfBytesToProcess--;
		}
		return numOfBytesToProcess == 0;
	}
};