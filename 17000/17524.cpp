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

int n, k;
int w[110];

vector<pll> v;
ll f(int a, int b) {
	if (b > a) return -1;
	return 30 + (v[a].fr - v[b].fr) * v[a].sc;
}

ll f2(int ti1, int ti2, int ti3) {
	int s1 = 0, s2 = 0, s3 = 0;
	for (int i = 0; i < v.size(); i++) {
		int dt1 = f(i, ti1);
		int dt2 = f(i, ti2);
		int dt3 = f(i, ti3);
		if (i >= ti1 && dt1 <= s1) continue;
		if (i >= ti2 && dt2 <= s2) continue;
		if (i >= ti3 && dt3 <= s3) continue;

		if (i >= ti3) s3 = max(s3, dt3);
		else if (i >= ti2) s2 = max(s2, dt2);
		else s1 = max(s1, dt1);
	}
	return s1 + s2 + s3;
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		w[a] = max(w[a], b);
	}
	for (int i = 40; i <= 100; i++) if (w[i] > 0) v.push_back({ i, w[i] });

	ll ans = 2e18;
	ans = f2(0, 100, 100);
	if (k >= 2) {
		for (int i = 1; i < v.size(); i++) 
			ans = min(ans, f2(0, i, 100));
	}
	if (k >= 3) {
		for (int i = 1; i < v.size(); i++)
			for (int j = i + 1; j < v.size(); j++)
				ans = min(ans, f2(0, i, j));
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
