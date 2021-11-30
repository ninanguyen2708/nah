//------onedimension------
tcT> struct BIT {
	int N; V<T> data;
	void init(int _N) { N = _N; data.rsz(N); }
	void add(int p, T x) { for (++p;p<=N;p+=p&-p) data[p-1] += x; }
	T sum(int l, int r) { return sum(r+1)-sum(l); }
	T sum(int r) { T s = 0; for(;r;r-=r&-r)s+=data[r-1]; return s; }
	int lower_bound(T sum) {
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1<<25; pw; pw >>= 1) {
			int npos = pos+pw;
			if (npos <= N && data[npos-1] < sum)
				pos = npos, sum -= data[pos-1];
		}
		return pos;
	}
};
//------multi dimension------
template<class T, int ...Ns> struct BIT {
	T val = 0; void upd(T v) { val += v; }
	T query() { return val; }
};
template<class T, int N, int ...Ns> struct BIT<T, N, Ns...> {
	BIT<T, Ns...> bit[N + 1];
	template<typename... Args> void upd(int pos, Args... args) { assert(pos > 0); 		for (; pos <= N; pos += pos&-pos) bit[pos].upd(args...); }
	template<typename...Args> T sum(int r, Args... args) {
		T res = 0; for (; r; r -= r&-r) res += bit[r].query(args...);
		return res; }
	template<typename... Args> T query(int l, int r, Args... args) {
		return sum(r, args...) - sum (l - 1, args...); }
};
 
BIT<ll, MX> b;

for (int i = 0; i < q; i++) {
		int t, p, v; cin >> t >> p >> v;
		if (t == 1) b.upd(p, v - x[p]), x[p] = v;
		else cout << b.query(p, v) << endl;
	}
//
