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
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	vector<int> v2;
	int bit = -1, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (bit != v[i]) bit = v[i], cnt++;
		else {
			bit = v[i];
			v2.push_back(cnt);
			cnt = 1;
		}
	}
	if (cnt != 0) v2.push_back(cnt);

//	for (int i : v2) cout << i << ' ';
//	cout << '\n';

	int ans = 0;
	for (int i = 0; i < v2.size(); i++) {
		int tmp = 0;
		for (int j = 0; j < 3 && i + j < v2.size(); j++) tmp += v2[i + j];
		ans = max(ans, tmp);
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
