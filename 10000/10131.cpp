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

ll c[550000]; //게임 설치 시간
ll dp[550000]; //서브트리의 크기
ll dp2[550000]; //서브트리의 ci + depth의 최댓값
vector<int> adj[550000];

void dfs(int nd, int prv = -1, int dep = 0) {
	dp[nd] = 1;
	for (int nxt : adj[nd]) {
		if (nxt == prv) continue;
		dfs(nxt, nd, dep + 1);
		dp[nd] += dp[nxt];
	}
}

ll cnt;
void dfs2(int nd, int prv = -1) {
	vector<pll> v;
	for (int nxt : adj[nd]) {
		if (nxt == prv) continue;
		dfs2(nxt, nd);
	}
	for (int nxt : adj[nd]) {
		if (nxt == prv) continue;
		v.push_back({ dp2[nxt] - 2 * (dp[nxt] - 1), nxt });
	}
	sort(v.rbegin(), v.rend());

	dp2[nd] = c[nd];
	if (v.size()) {
		ll sum = 0;
		for (pll p : v) {
			dp2[nd] = max(dp2[nd], 1 + dp2[p.sc] + sum);
			sum += 2 * dp[p.sc];
		}
	}
}

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	dfs2(1);

	ll ans = c[1] + 2 * (n - 1);
	ans = max(ans, dp2[1]);
	//for (int i = 1; i <= n; i++) cout << dp2[i] << ' ';
	//cout << '\n';
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
