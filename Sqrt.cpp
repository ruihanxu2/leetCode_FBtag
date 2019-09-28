
int mySqrt(int x) {
	int left = 0;
	int right = x;
	int res = 0;
	// newton: r = r - f(r)/f'(r);
	// f(r) = r^2 - x;
	long r = x;
	while(r*r > x){
		r = (r + x / r) / 2;
	}
	return r;
	
	 // method 2:
	while(left <= right){
		int mid = left+(right - left) / 2;
		if(pow(mid, 2) > x){
			right = mid - 1;
		}
		else if(pow(mid, 2) < x) {
			left = mid + 1;
			res = mid;
		}
		else{
			return mid;
		}
	}
	return res;
	
}