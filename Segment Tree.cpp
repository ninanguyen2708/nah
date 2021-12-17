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
/* ------original------ 
 * Des: Number of Minimums on a Segment 
 * https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C
 */
template<class T> struct Seg { //[0, n]
	const T ID = mp(2e9, 0); int size; vector<T> seg; //*
	T comb(T a, T b) { //*
		if (a.f < b.f) return a; 
		if (a.f > b.f) return b;
		if (a.f == b.f) return mp(a.f, a.s + b.s); 
	}
	void init(int _n) {
		size = 1; while (size < _n) size *= 2;
		seg.assign(2 * size, ID);
	}
	void build(vi &a, int x, int Lx, int Rx) {
		if (Rx - Lx == 1) { if (Lx < sz(a)) seg[x] = mp(a[Lx], 1); return; }
		int m = (Lx + Rx) >> 1;
		build(a, 2 * x + 1, Lx, m);
		build(a, 2 * x + 2, m, Rx);
		seg[x] = comb(seg[2 * x + 1], seg[2 * x + 2]);
	}
	void upd(int i, int val, int x, int Lx, int Rx) {
		if (Rx - Lx == 1) { seg[x] = mp(val, 1); return; }
		int m = (Lx + Rx) >> 1;
		if (i < m) 	upd(i, val, 2 * x + 1, Lx, m);
		else 		upd(i, val, 2 * x + 2, m, Rx);
		seg[x] = comb(seg[2 * x + 1], seg[2 * x + 2]);
	}
	T query(int l, int r, int x, int Lx, int Rx) {
		if (r <= Lx) return ID; if (l >= Rx) return ID;
		if (l <= Lx && Rx <= r) return seg[x];
		int m = (Lx + Rx) >> 1;
		T s1 = query(l, r, 2 * x + 1, Lx, m);
		T s2 = query(l, r, 2 * x + 2, m, Rx);
		return comb(s1, s2);
	}
	void build(vector<int> &a) { build(a, 0, 0, size); }
	void upd(int i, int val) { upd(i, val, 0, 0, size); }
	T query(int l, int r) { return query(l, r, 0, 0, size); }
}; 
int n, m; vi a; Seg<pi> seg;
