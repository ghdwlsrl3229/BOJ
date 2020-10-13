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

int n, t;
vector<pair<ll, pll>> v; //(m, p, r)

ll cache[55][110000];

ll dp(int pos, int time) {
	if (pos == n) return 0;

	ll& ret = cache[pos][time];
	if (ret != -1) return ret;
	
	ret = 0;
	ll m = v[pos].fr, p = v[pos].sc.fr, r = v[pos].sc.sc;
	ret = max(ret, dp(pos + 1, time));
	if (time + r <= t) ret = max(ret, dp(pos + 1, time + r) + m - (time + r) * p);
	return ret;
}

void solve() {
	cin >> n >> t;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i].fr;
	for (int i = 0; i < n; i++) cin >> v[i].sc.fr;
	for (int i = 0; i < n; i++) cin >> v[i].sc.sc;
	sort(all(v), [](const pair<ll, pll>& a, const pair<ll, pll>& b) {
		if (a.sc.sc * b.sc.fr == b.sc.sc * a.sc.fr) return a.fr < b.fr;
		return a.sc.sc * b.sc.fr < b.sc.sc * a.sc.fr;
	});
	memset(cache, -1, sizeof(cache));
	cout << dp(0, 0) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if (0) {
		int T; cin >> T;
		while (T--) solve();
	}
	else {
		solve();
	}
	return 0;
}
