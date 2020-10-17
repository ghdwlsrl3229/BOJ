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

const int mod = 1e9 + 7;

int N;
int h[11000];
ll dp[2][11000];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> h[i];
	if (h[0] == -1) h[0] = 0;
	if (h[N - 1] == -1) h[N - 1] = 0;
	if (h[0] != 0 || h[N - 1] != 0) {
		cout << 0 << '\n';
		return;
	}
	dp[0][0] = 1;
	for (int i = 1; i < N; i++) {
		if (h[i] == -1) {
			for (int j = 0; j <= N; j++) {
				dp[i % 2][j] = dp[(i - 1) % 2][j];
				if (j - 1 >= 0) dp[i%2][j] = (dp[i % 2][j] + dp[(i - 1)%2][j - 1]) % mod;
				if (j + 1 <= N) dp[i%2][j] = (dp[i % 2][j] + dp[(i - 1)%2][j + 1]) % mod;
			}
		}
		else {
			for (int j = 0; j <= N; j++) {
				if (j == h[i]) {
					dp[i%2][j] = dp[(i - 1)%2][j];
					if (j - 1 >= 0) dp[i % 2][j] = (dp[i % 2][j] + dp[(i - 1) % 2][j - 1]) % mod;
					if (j + 1 <= N) dp[i % 2][j] = (dp[i % 2][j] + dp[(i - 1) % 2][j + 1]) % mod;
				}
				else dp[i%2][j] = 0;
			}
		}
	}
	cout << dp[(N - 1)%2][0] << '\n';
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
