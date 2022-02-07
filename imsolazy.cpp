#include <bits/stdc++.h>

#define _ << " 3 " >>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pli> vli;
typedef vector<pil> vil;

#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define REP(i, n) FOR (i, 0, (n))
#define BAC(i, a, b) for (ll i = (a - 1); i >= (b); --i)
#define TRACE(x) cout << #x << ": "
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define mem(i, a) memset(i, a, sizeof i)
#define el printf("\n")
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize
#define tcT template<class T

const int dx[]{1, 0, -1, 0}, dy[]{0, 1, 0, -1};
const int MOD = 998244353; // 1000000007
const ll INF = 1e18;
const int oo = 1000000007;
const int MX = 100001;
const ld PI = 4 * atan((ld)1);

tcT> bool maximize(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
tcT> bool minimize(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
tcT> pw(T a, T b, T m) {
	T res = 1; a = a % m;
	while (b > 0) {
		if (b&1) res = (res * a) % m;
		a = (a * a) % m; b >>= 1; 
	} return res;
}

void solve() {
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("name.inp", "r", stdin);
//	freopen("name.out", "w", stdout);
	solve();
	return 0;
}
