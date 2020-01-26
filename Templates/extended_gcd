int ainv, binv;
void extgcd(int a, int b){ 
	if(b == 0) {
		hcf = a;
		ainv = 1;
		binv = 0;
	} 
	else{
		extgcd(b, a%b);
		int temp = ainv;
		ainv = binv;
		binv = temp - (a/b)*binv; 
	} 
}

// a * x + M * y = 1 
// => ainv = modular inverse of a, with mod M, (a and M shold be co prime, M can be non prime)
