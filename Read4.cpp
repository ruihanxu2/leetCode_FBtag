// only call read once:
// note that the case that fp length is not enough 
// can be resolved by if(iresult < 4) 
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
	// three cases: 
	// file ---- ---- ---- ---- ----
	// buff ----
	// n    -------
	// r = 4, n - res >= 4
	
	// file ---- ---- ---- ---- ----
	// buff ---- ---- ----
	// n    ---- ---- --
	// r = 4, n - res < 4
	
	// file ---- ---- --
	// buff ---- ---- --~~
	// n    ---- ---- ---- ----
	// r < 4, n - res >= r
	
	
	// file ---- ---- --
	// buff ---- ---- --~~
	// n    ---- ---- -
	// r < 4, n - res < r
	
	int read(char *buf, int n) {
		char tmp[4];
		int res = 0;
		while(res < n){
			int r = read4(tmp);
			memcpy(buf + res, tmp, min(n - res, r));
			res += min(n - res, r);
			if(r < 4) break;
		}
		return res;
	}
	
};
// --------------------------------------------------------------------------------
// call read multiple times:
// abcd read(buf, 1),read(buf, 2),read(buf, 1) ==> buf = "abcd"
//
//read(3), read(3)..
//we need to know the starting point of previous write
//we need a pointer, every time we write from tmp[pointer]
//when pointer is == 4 we read again, set pointer to 0;
//but the tmp maynot be of length 4 if the origin text is not long enough...
//maybe a read pointer as well?
//we read when wp == readpointer
//then, if we cannot read any more, we return

int read4(char *buf);

class Solution {
private: 
	int readPos = 0;
	int writePos = 0;
	char tmp[4];
public:
	/**
	 * @param buf Destination buffer
	 * @param n   Number of characters to read
	 * @return    The number of actual characters read
	 */
	
	int read(char *buf, int n) {
		int i = 0;
		while(i < n){
			if(writePos < readPos){
				buf[i] = tmp[writePos++];
				i++;
			}
			else{
				// wp == rp
				readPos = read4(tmp);
				writePos = 0;
				if(readPos == 0) return i;
			}
		}
		return n;
	}

};