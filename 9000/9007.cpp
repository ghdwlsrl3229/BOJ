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
	ll k, n; cin >> k >> n;
	vector<ll> v[4];
	for (int i = 0; i < 4; i++) {
		v[i] = vector<ll>(n);
		for (int j = 0; j < n; j++) cin >> v[i][j];
	}
	vector<ll> v1, v2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			v1.push_back(v[0][i] + v[1][j]);
			v2.push_back(v[2][i] + v[3][j]);
		}
	sort(all(v2));

	ll ans = 1e18;
	for (int i = 0; i < v1.size(); i++) {
		int idx = lower_bound(all(v2), k - v1[i]) - v2.begin();
		for (int j = idx - 3; j < idx + 3; j++) {
			if (j < 0 || j >= v2.size()) continue;
			if (abs(ans - k) == abs(v1[i] + v2[j] - k)) ans = min(ans, v1[i] + v2[j]);
			else if (abs(ans - k) > abs(v1[i] + v2[j] - k)) ans = v1[i] + v2[j];
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) solve();
	return 0;
}
