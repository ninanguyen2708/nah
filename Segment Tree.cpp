/*  ID, comb, T can change
 *	this is sum -> ID = 0
 *		min -> ID = 1e18
 */
template<class T> struct Seg { // comb(ID,b) = b
	const T ID = 0 /*ID{}*/; T comb(T a, T b) { return min(a,b); }
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(4 * n + 7,ID); }
	void pull(int p) { seg[p] = comb(seg[2 * p],seg[2 * p + 1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// min on interval [l, r]
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra, rb);
	}
};
/* ------------ 
 * Des: Number of Minimums on a Segment 
 * https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C
 */
template<class T> struct Seg { // 0-indexed
	const T ID = mp(2e9, 0); int n; vector<T> seg; 

	T comb(T a, T b) { 
		if (a.f < b.f) return a; 
		if (a.f > b.f) return b;
		if (a.f == b.f) return mp(a.f, a.s + b.s); 
	}
	
	void init(int _n) {
		for (n = 1; n < _n;) n *= 2;
		seg.assign(2 * n, ID);
	}

	void build(vi &a) {
		for (int i = 0; i < sz(a); i++) seg[i + sz(a)] = mp(a[i], 1);
		for (int i = n - 1; i > 0; --i) seg[i] = comb(seg[i >> 1], seg[i >> 1 | 1]);
	}

	void upd(int p, int val) {
		for (seg[p += n] = mp(val, 1); p > 1; p >>= 1) seg[p >> 1] = comb(seg[p], seg[p ^ 1]);
	}

	T query(int l, int r) {
		T ra = ID, rb;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		    if (l&1) ra = comb(ra, seg[l++]);
		    if (r&1) rb = comb(seg[--r], rb);
		}
		return comb(ra, rb);
	}
};

