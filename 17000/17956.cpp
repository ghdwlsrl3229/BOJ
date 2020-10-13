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

typedef tuple<int, int, int, int> tll;

vector<tll> v;
int N, S1, S2;

ll dp[2][1100][1100];

void solve() {
	cin >> N >> S1 >> S2;
	for (int i = 0; i < N; i++) {
		int x, t, y, r;
		cin >> x >> t >> y >> r;
		v.push_back({ x, t, y, r });
	}

	sort(all(v));

	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)
			dp[0][i][j] = 1e15;
	dp[0][0][0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 1000; j++) {
			for (int k = 0; k <= 1000; k++) {
				int x, t, y, r;
				tie(x, t, y, r) = v[i - 1];
				dp[i % 2][j][k] = dp[(i - 1) % 2][j][k];
				if (j - x >= 0 && j - x < S1) dp[i % 2][j][k] = min(dp[i % 2][j][k], dp[(i - 1) % 2][j - x][k] + t);
				if (k - y >= 0) dp[i % 2][j][k] = min(dp[i % 2][j][k], dp[(i - 1) % 2][j][k - y] + r);
			}
		}
	}

	ll ans = 1e15;
	for (int i = S1; i <= 1000; i++) {
		for (int j = max(S1 + S2 - i, 0); j <= 1000; j++)
			ans = min(ans, dp[N%2][i][j]);
	}

	if (ans >= 1e15) cout << -1 << '\n';
	else cout << ans << '\n';
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
