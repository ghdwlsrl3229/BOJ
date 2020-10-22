#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
#define ll long long
#define fr first
#define sc second
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()

ll d, t;

const int MOD = 31991;
const int SZ = 51;
struct matrix {
	ll val[SZ][SZ];
	matrix() {
		for (int i = 0; i < d; i++)
			for (int j = 0; j < d; j++)
				val[i][j] = 0;
	}
};

matrix operator*(const matrix& a, const matrix& b) {
	matrix ret;
	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++)
			for (int k = 0; k < d; k++) {
				ret.val[i][j] += a.val[i][k] * b.val[k][j];
				ret.val[i][j] %= MOD;
			}
	return ret;
}

matrix I;
matrix pow(matrix& a, ll b) {
	matrix ret = I;
	while (b) {
		if (b & 1) ret = ret * a;
		b >>= 1;
		a = a * a;
	}
	return ret;
}

void solve() {
	cin >> d >> t;
	for (int i = 0; i < d; i++) I.val[i][i] = 1;
	matrix A;
	for (int i = 0; i < d; i++) A.val[d - 1][i] = 1;
	for (int i = 0; i < d - 1; i++) A.val[i][i + 1] = 1;

	ll base[51] = { 0 };
	base[0] = 1;
	for (int i = 1; i < d; i++) {
		for (int j = max(0LL, i - d); j < i; j++) base[i] += base[j];
		base[i] %= MOD;
	}

	ll ans = 0;
	if (t - d + 1 >= 0) {
		matrix An = pow(A, t - d + 1);

		for (int i = 0; i < d; i++)
			ans = (ans + base[i] * An.val[d - 1][i]) % MOD;
	}
	else ans = base[t];
	cout << ans << '\n';

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
//	int T; cin >> T;
//	while (T--) solve();
	solve();
	return 0;
}
