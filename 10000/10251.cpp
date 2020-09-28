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

ll M, N, L, G;
ll dp[110][110][220][2]; //(y, x, 방향전환 횟수, 방향(0=오른쪽, 1=아래))
ll garo[110][110], sero[110][110];

void solve() {
	cin >> N >> M >> L >> G;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M - 1; j++)
			cin >> garo[i][j];
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < M; j++)
			cin >> sero[i][j];

	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= M; j++)
			for (int k = 0; k <= 2 * min(N, M); k++)
				dp[i][j][k][0] = dp[i][j][k][1] = 1e18;
	dp[0][0][0][0] = dp[0][0][0][1] = 0;
	
	for (int k = 0; k <= 2 * min(N, M); k++) 
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= M; j++) {	
				if (j - 1 >= 0) {
					dp[i][j][k][0] = min(dp[i][j][k][0], dp[i][j - 1][k][0] + garo[i][j - 1]);
					if (k - 1 >= 0) dp[i][j][k][0] = min(dp[i][j][k][0], dp[i][j - 1][k - 1][1] + garo[i][j - 1]);
				}
				if (i - 1 >= 0) {
					dp[i][j][k][1] = min(dp[i][j][k][1], dp[i - 1][j][k][1] + sero[i - 1][j]);
					if (k - 1 >= 0) dp[i][j][k][1] = min(dp[i][j][k][1], dp[i - 1][j][k - 1][0] + sero[i - 1][j]);
				}
			}

	ll ans = 1e18;
	for (int i = 0; i <= 2 * min(N, M); i++) {
		if (dp[N-1][M-1][i][0] <= G || dp[N - 1][M - 1][i][1] <= G) ans = min(ans, i + L * (N + M - 2));
	}
	if (ans == 1e18) cout << -1 << '\n';
	else cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
