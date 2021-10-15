// Des: calculate a^b (mod m) efficiently
long long binpow(long long a, long long b, long long m) {
	a %= m; // can remove m
	long long res = 1;
	while (b > 0) {
		if (b & 1) (res *= a) %= m;
		(a *= a) %= m;
		b >>= 1;
	}
	return res;
}
