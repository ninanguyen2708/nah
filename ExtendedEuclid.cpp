/* Other name: Euclidean
 * Des: return gcd(a, b); ax + by = c: combine this one and check c % gcd(a, b) != 0 -> no sol, 
 * otherwise return x_res = x * (c / g), y_res = y * (c / g)
 * find all sol of ax + by = c in range: https://ideone.com/DDmLxr (range: all posive num)
 */
ll euclid(ll a, ll b) {
	for (;b;swap(a,b)) {
		ll k = a/b;
		a -= k*b;
	}
	return a; // gcd(a,b)
}

// (1) ax + by = gcd(a, b) -> return x, y, gcd(a, b);
vi extendEuclid(ll a, ll b) {
	vi x = {1,0,a}, y = {0,1,b};
	// we know that 1*a+0*b=a and 0*a+1*b=b
	for (;y[2];swap(x,y)) { // run extended Euclidean algo
		ll k = x[2]/y[2];
		F0R(i,3) x[i] -= k*y[i]; // should implement to each one for faster
		// keep subtracting multiple of one equation from the other
	}
	return x; // x[0]*a+x[1]*b=x[2], x[2]=gcd(a,b)
}
