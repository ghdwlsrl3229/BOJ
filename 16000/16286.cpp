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

ll w, n;
ll arr[550000];
ll psum[550000];
int dp[550000];

bool f(ll mid) {
	for (int i = 0; i < n; i++) {
		if (abs(w - psum[i + 1]) <= mid && psum[i + 1] <= w) dp[i] = 1;
		else dp[i] = 0;
	}

	int l = 0, r = 0, sum = dp[0];
	for (int i = 1; i < n; i++) {
		ll le = lower_bound(psum, psum + i + 1, max(psum[i + 1] - w - mid, psum[i + 1] - w)) - psum;
		ll ri = upper_bound(psum, psum + i + 1, psum[i + 1] - w + mid) - psum - 1;
		// [le - 1, ri - 1]에 1이 있는가?
		if (le <= ri) {
			while (r < ri - 1) r++, sum += dp[r];
			while (l < le - 1) sum -= dp[l], l++;
			if (sum) dp[i] |= 1;
		}
	}
	return dp[n - 1];
}

void solve() {
	cin >> w >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) psum[i + 1] = psum[i] + arr[i];

	ll lo = 0, hi = w;
	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		if (f(mid)) hi = mid;
		else lo = mid + 1;
	}
	cout << hi * hi << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//	int T; cin >> T;
	//	while (T--) solve();
	solve();
	return 0;
}