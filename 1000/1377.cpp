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
	int n; cin >> n;
	int a[550000];
	vector<pll> v;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v.push_back({ a[i], i });
	}
	sort(all(v));

	ll ans = 1;
	for (int i = 0; i < n; i++) {
		if (i <= v[i].sc) ans = max(ans, v[i].sc - i + 1);
	}
	cout << ans << '\n';
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
