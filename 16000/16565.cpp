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

int N;
const int mod = 10007;
ll cache[15][2][60];
ll fact[5];

ll nCk(int n, int k) {
	ll ret = fact[n] / fact[n - k] / fact[k];
	return ret % mod;
}

ll dp(int num, bool flag, int pick) { 
	if (num == 13) {
		if (pick != N) return 0;
		if (flag) return 1;
		return 0;
	}

	ll& ret = cache[num][flag][pick];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i <= 4; i++) {
		if (pick + i <= N) {
			if (i < 4) ret = (ret + nCk(4, i) * dp(num + 1, flag, pick + i) % mod) % mod;
			else ret = (ret + dp(num + 1, 1, pick + i) % mod) % mod;
		}
	}
	return ret;
}

void solve(int tc) {
	cin >> N;
	memset(cache, -1, sizeof(cache));
	fact[0] = 1;
	for (int i = 1; i < 5; i++) fact[i] = fact[i - 1] * i;
	cout << dp(0, 0, 0) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if (0) {
		int T; cin >> T;
		for (int i = 1; i <= T; i++) solve(i);
	}
	else {
		solve(0);
	}
	return 0;
}
