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

	bool used[110] = { 0 };
	vector<int> ans;
	for (int i = n - 1; i >= 0; i--) {
		int cnt = 0;
		bool flag = 0;
		for (int j = 1; j <= n; j++) {
			if (!used[j]) cnt++;
			if (cnt == v[i] + 1) {
				used[j] = 1;
				ans.push_back(j);
				flag = 1;
				break;
			}
		}
		if (!flag) {
			cout << "IMPOSSIBLE\n";
			return;
		}
	}
	for (int i = n - 1; i >= 0; i--) cout << ans[i] << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) solve();
	return 0;
}
