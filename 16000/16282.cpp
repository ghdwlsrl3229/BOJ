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

bool chk(int split, ll n) {
	ll tmp = split + 1;
	for (int i = 0; i <= split; i++, tmp *= 2) {
		n -= tmp;
	}
	return n <= 0;
}

void solve() {
	ll n;
	cin >> n;

	int ans = 1e9;
	for (int i = 1; i <= 60; i++) {
		if (n - i <= 0) continue;
		if (chk(i, n - i)) {
			ans = i;
			break;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//	int T; cin >> T;
	//	while (T--) solve();
	solve();
	return 0;
}
