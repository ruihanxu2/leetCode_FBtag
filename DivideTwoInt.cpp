// Cannot use * / or %
int divide(int dividend_, int divisor_) {
	if(dividend_ == INT_MIN && divisor_ == -1){
		return INT_MAX;
	}
	int sign = (dividend_ > 0) ^ (divisor_ > 0) ? -1 : 1;
	long res = 0;
	long dividend = labs(dividend_);
	long divisor = labs(divisor_);
	while(dividend >= divisor){
		long tmp = divisor;
		long n = 1;
		while(tmp<<1 <= dividend){
			tmp <<= 1;
			n <<= 1;
		}
		res+=n;
		dividend-=tmp;
	}
	return sign * res;
}
//lc29