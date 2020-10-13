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
	vector<pair<pll, ll>> v;
	for (int i = 0; i < n; i++) {
		int t, s; cin >> t >> s;
		v.push_back({ {t, s}, i });
	}
	sort(all(v), [](const pair<pll, ll>& a, const pair<pll, ll>& b) {
		if (a.fr.fr * b.fr.sc == b.fr.fr * a.fr.sc) return a.sc < b.sc;
		return a.fr.fr * b.fr.sc < b.fr.fr * a.fr.sc;
	});
	for (int i = 0; i < n; i++) {
		cout << v[i].sc + 1 << ' ';
	}
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
