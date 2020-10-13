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

int n, c;
vector<pair<pll, int>> v;

int cache[550][11000];

int dp(int pos, int rest) {
	if (pos == n) return 0;

	int &ret = cache[pos][rest];
	if (ret != -1) return ret;

	ret = 0;
	int d = v[pos].fr.fr, s = v[pos].fr.sc;
	ret = max(ret, dp(pos + 1, rest));
	if (rest >= d) ret = max(ret, dp(pos + 1, rest - s) + 1);
	
	return ret;
}

vector<int> ans;
void bt(int pos, int rest) {
	if (pos == n) return;

	int d = v[pos].fr.fr, s = v[pos].fr.sc;
	if (rest >= d) {
		if (dp(pos, rest) == dp(pos + 1, rest)) bt(pos + 1, rest);
		else {
			bt(pos + 1, rest - s);
			ans.push_back(v[pos].sc);
		}
	}
	else bt(pos + 1, rest);
}

void solve() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int d, s; cin >> d >> s;
		v.push_back({ {max(d, s), s}, i + 1 });
	}
	sort(all(v), [](const pair<pll, int>& a, const pair<pll, int>& b) {
		return a.fr.sc - a.fr.fr < b.fr.sc - b.fr.fr;
	});
	memset(cache, -1, sizeof(cache));
	cout << dp(0, c) << '\n';
	bt(0, c);
	reverse(all(ans));
	for (int i : ans) cout << i << ' ';
	cout << '\n';
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
