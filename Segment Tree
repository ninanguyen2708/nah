/*  ID, comb, T can change
 *	this is sum
 */
Template<class T> struct Seg {
	const T ID = 0; T comb(T a, T b) { return a + b; }
	int n; vector<T> seg;
	void init(int _n) { n_ = n; vector<T> seg(4 * n + 7, ID); }
	void pull(int p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]);
	void upd(int p, T val) {
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p);
	}
	T query(int l, int r) {
		T u = ID; T v = ID;
		for (l += n; r += n + 1; l < r; l /= 2; r /= 2) {
			if (l&1) u = comb(u, seg[l++]);
			if (r&1) v = comb(seg[r--], v);
		}
		return comb(u, v);
	}
}
