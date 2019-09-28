double myPow_rec(double x, int n) {
	if(n == 0) return 1;
	if(n == 1) return x;
	if(n == 2) return x*x;
	if(n < 0) return 1/x*myPow(1/x, -(n+1));
	else{
		if(n % 2 == 0) return myPow(myPow(x, n/2), 2);
		else return x * myPow(myPow(x, n/2), 2);
	}
}
double myPow(double x, int N) {
	///n = 5: 1   0   1
	///       x4  x2  x
	/// x5 =  x4 * x

	long n = N;
	if(n == 0) return 1;
	if(n < 0){
		n = -n;
		x = 1 / x;
	}
	
	double res = 1;
	double base = x;
	for(long i = n; i>0; i /= 2 ){
		if(i % 2 == 1){
			res *= base;    
		}    
		base *= base;
	}
	
	return res;
	
}