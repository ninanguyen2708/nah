/* Des: String Hashing
 * Source: gspvh (i do edit a bit)
 * Accuracy: high(maybe)
 */
#define NMOD  3
const MOD[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277};
const int BASE = 256;

#define MAX   50050
int pw[NMOD][MAX]; // pw[j][i] = BASE^i % MOD[j] 

void prepare(void) {
	FOR(j, 0, NMOD) {
		pw[j][0] = 1;
		FOR(i, 1, MAX) pw[j][i] = 1LL * pw[j][i - 1] * BASE % MOD[j];
	}
}

struct Hash {
	int val[NMOD + 1];

	Hash() { mem(val, 0); }
	Hash(char c) { for (int j = 0; j < NMOD; j++) val[j] = c; }

	Hash operator + (const Hash &x) const {
		Hash res;
		for (int j = 0; j < NMOD; j++) {
			res.val[j] = val[j] + x.val[j];
			if (res.val[j] >= MOD[j]) res.val[j] -= MOD[j];
		} return res; }

	Hash operator - (const Hash &x) const {
		Hash res;
		for (int j = 0; j < NMOD; j++) {
			res.val[j] = val[j] - x.val[j];
			if (res.val[j] < 0) res.val[j] += MOD[j];
		} return res; }

	Hash operator * (int k) const {
		Hash res;
		for (int j = 0; j < NMOD; j++) 
			res.val[j] = 1LL * val[j] * pw[j][k] % MOD[j];
		return res; }

	bool operator < (const Hash &x) const {
		for (int j = 0; j < NMOD; j++) if (val[j] != x.val[j])
			return val[j] < x.val[j];
		return false; }
	bool operator == (const Hash &x) const {
		for (int j = 0; j < NMOD; j++) if (val[j] != x.val[j]) return false;
		return true; }
};

Hash findH(char b[], int l) {
	Hash tmp; FOR(i, 1, l + 1) tmp = tmp * 1 + Hash(b[i]);
	return tmp;
}

int n, q, pos[MAX]; Hash h[MAX]; 

char s[MAX];
scanf(“%s”, s + 1);
int n = strlen(s + 1);

// chuẩn bị mảng hash trên xâu s
Hash h[MAX];
// h[i] = s[1] * BASE^1 + s[2] * BASE^2 + ... + s[i] * BASE^i
// for (int i = 1; i <= n; i++) h[i] = h[i - 1] + Hash(s[i]) * i; : aH làm vầy này mà tui ko hỉu 
FOR(i, 1, n + 1) h[i] = h[i - 1] * 1 + Hash(a[i]);

// h[r] - h[l - 1] = s[l] * BASE^l + s[l+1] * BASE^(l+1) + ... + s[r] * BASE^r
Hash getHash(int l, int r) { // lấy mã hash của đoạn xâu liên tiếp từ l đến r
	return h[r] - h[l - 1] * (r - l + 1);
//	return (h[r] - h[l - 1]) * (n - r); : aH làm vầy này mà tui ko hỉu 
}

