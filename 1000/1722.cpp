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

ll fact[21];

void solve(int tc) {
	int N; cin >> N;
	int type; cin >> type;

	fact[0] = 1;
	for (int i = 1; i <= 20; i++) fact[i] = fact[i - 1] * i;

	if (type == 1) {
		ll k; cin >> k;
		k--;
		vector<int> v, v2;
		for (int i = 1; i <= N; i++) v.push_back(i);
		for (int i = 1; i <= N; i++) {
			int idx = k / fact[N - i] % v.size();
			v2.push_back(v[idx]);
			v.erase(v.begin() + idx);
		}
		for (int i : v2) cout << i << ' ';
		cout << '\n';
	}
	else {
		vector<int> v(N), v2;
		for (int i = 0; i < N; i++) cin >> v[i];
		for (int i = 0; i < N; i++) v2.push_back(i + 1);

		ll ans = 1;
		for (int i = 1; i <= N; i++) {
			ans += fact[N - i] * (lower_bound(all(v2), v[i - 1]) - v2.begin());
			v2.erase(lower_bound(all(v2), v[i - 1]));
		}
		cout << ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if (0) {
		int T; cin >> T;
		for (int i = 1; i <= T; i++) solve(i);
	}
	else {
		solve(0);
	}
	return 0;
}
