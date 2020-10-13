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

int cnt[110000], cnt2[110000];

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		cnt[v[i]]++;
	}
	for (int i = 100000; i >= 1; i--) {
		if ((cnt[i] + cnt2[i]) % 2 == 1 && cnt[i] > 0) {
			cnt[i]--;
			cnt2[i - 1]++;
		}
	}
	vector<ll> vv;
	for (int i = 1; i <= 100000; i++) {
		for (int j = 0; j < (cnt[i] + cnt2[i]) / 2; j++)
			vv.push_back(i);
	}
	sort(all(vv), greater<int>());
	ll ans = 0;
	for (int i = 0; i < vv.size(); i += 2) {
		if (i + 1 < vv.size()) ans += vv[i] * vv[i + 1];
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
