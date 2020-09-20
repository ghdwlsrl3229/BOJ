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

void solve() {
	int n, m, c1, c2; cin >> n >> m >> c1 >> c2;
	vector<int> p(n), q(m);
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < m; i++) cin >> q[i];
	sort(all(p));
	sort(all(q));

	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(all(q), p[i]) - q.begin();
		for (int j = idx - 1; j <= idx + 1; j++) {
			if (j < 0 || j >= m) continue;
			mp[abs(c1 - c2) + abs(p[i] - q[j])]++;
		}
	}
	auto ans = *mp.begin();
	cout << ans.first << ' ' << ans.second << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//	int T; cin >> T;
	//	while (T--) solve();
	solve();
	return 0;
}
