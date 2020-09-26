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
pll arr[255];
ll dp[255][125000];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].fr >> arr[i].sc;
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= 125000; j++) 
			dp[i][j] = 1e9;

	dp[0][62500] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 125000; j++) {
			if (j + arr[i - 1].sc <= 125000) dp[i][j] = min(dp[i][j], dp[i - 1][j + arr[i - 1].sc] + arr[i - 1].sc);
			if (j - arr[i - 1].fr >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - arr[i - 1].fr] + arr[i - 1].fr);
		}
	}

	ll ans = 1e9;
	for (int i = 0; i <= 125000; i++)
		ans = min(ans, (dp[N][i] + abs(i - 62500)) / 2);
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
