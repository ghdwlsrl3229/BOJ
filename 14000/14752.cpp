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

int n;
pll arr[11000]; //(point, width)
ll psum[11000];
int dp[11000][11000];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i].fr;
	for (int i = 0; i < n; i++) cin >> arr[i].sc;
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) psum[i + 1] = psum[i] + arr[i].sc;
	for (int i = 0; i <= n; i++) for (int j = 0; j <= i; j++) dp[i][j] = 1e9;
	dp[0][0] = 0;

	for (int i = 1; i < n; i++) {
		dp[i][i] = i;
		for (int j = 0; j < i; j++) {
			int stked = arr[j].fr + psum[i + 1] - psum[j + 1];
			if (stked <= arr[i].fr) dp[i][i] = min(dp[i][i], dp[i - 1][j]);
		}
		for (int j = 0; j < i; j++) {
			int stked = arr[j].fr + psum[i] - psum[j + 1];
			int a = (stked <= arr[i].fr && arr[i].fr <= stked + arr[i].sc) ? 0 : 1;
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + a);
		}
	}

	int ans = n - 1;
	for (int i = 0; i < n; i++) ans = min(ans, dp[n - 1][i]);
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