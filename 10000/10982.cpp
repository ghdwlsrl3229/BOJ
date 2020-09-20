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

int N;
pll arr[1100];
ll dp[2][220000];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].fr >> arr[i].sc;
	for (int j = 0; j <= 200000; j++) dp[0][j] = dp[1][j] = 1e9;

	dp[0][100000] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 200000; j++) {
			dp[i % 2][j] = 1e9;
			if (j + arr[i - 1].sc <= 200000) dp[i % 2][j] = min(dp[i % 2][j], dp[(i - 1) % 2][j + arr[i - 1].sc] + arr[i - 1].sc);
			if (j - arr[i - 1].fr >= 0) dp[i % 2][j] = min(dp[i % 2][j], dp[(i - 1) % 2][j - arr[i - 1].fr] + arr[i - 1].fr);
		}
	}

	ll ans = 1e9;
	for (int i = 0; i <= 200000; i++) 
		ans = min(ans, (dp[N%2][i] + abs(i - 100000)) / 2);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if (1) {
		int T; cin >> T;
		while (T--) solve();
	}
	else {
		solve();
	}
	return 0;
}
