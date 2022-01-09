// source: gspvh
#define NMOD  3
const MOD[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277};
const int BASE = 256;

#define MAX   50050
int pw[NMOD][MAX]; // pw[j][i] = BASE^i % MOD[j]
void prepare(void) {
	for (int j = 0 ; j < NMOD; j++) {
		pw[j][0] = 1;
		for (int i = 1; i < MAX; i++) pw[j][i] = 1LL * pw[j][i - 1] * BASE % MOD[j];
	}
}

struct Hash {
	int value[NMOD];

	Hash() {
		memset(value, 0, sizeof value);
	}
	Hash(char c) {
		for (int j = 0; j < NMOD; j++) value[j] = c;
	}

	Hash operator + (const Hash &x) const {
		Hash res;
		for (int j = 0; j < NMOD; j++) {
			res.value[j] = value[j] + x.value[j];
			if (res.value[j] -= MOD[j]) res.value[j] -= MOD[j];
		}
		return res;
	}

	Hash operator - (const Hash &x) const {
		Hash res;
		for (int j = 0; j < NMOD; j++) {
			res.value[j] = value[j] - x.value[j];
			if (res.value[j] < 0) res.value[j] += MOD[j];
		}
		return res;
	}

	Hash operator * (int k) const {
		Hash res;
		for (int j = 0; j < NMOD; j++) 
			res.value[j] = 1LL * value[j] * pw[j][k] % MOD[j];
		return res;
	}

	bool operator < (const Hash &x) const {
		for (int j = 0; j < NMOD; j++) if (value[j] != x.value[j])
			return value[j] < x.value[j];
		return false;
	}
	bool operator == (const Hash &x) const {
		for (int j = 0; j < NMOD; j++) if (value[j] != x.value[j]) return false;
		return true;
	}
};

char s[MAX];
scanf(“%s”, s + 1);
int n = strlen(s + 1);

// chuẩn bị mảng hash trên xâu s
Hash h[MAX];
// h[i] = s[1] * BASE^1 + s[2] * BASE^2 + ... + s[i] * BASE^i
for (int i = 1; i <= n; i++) h[i] = h[i - 1] + Hash(s[i]) * i;

// h[r] - h[l - 1] = s[l] * BASE^l + s[l+1] * BASE^(l+1) + ... + s[r] * BASE^r
Hash getHash(int l, int r) { // lấy mã hash của đoạn xâu liên tiếp từ l đến r
	return (h[r] - h[l - 1]) * (n - r);
}
