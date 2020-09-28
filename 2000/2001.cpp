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

int n, m, k;
int jewel[110];
vector<pll> adj[110];

bool reachable[110][1 << 14];

void bfs() {
	queue<pll> q;
	q.push({ 1, 0 });
	reachable[1][0] = 1;

	while (q.size()) {
		int cur, bit;
		tie(cur, bit) = q.front();
		q.pop();

		int cnt1 = 0, cnt2 = 0, bit2 = 0;
		for (int i = 0; i < k; i++) if (bit & (1 << i)) cnt1++;
		if (jewel[cur] != -1 && cur != 1) {
			bit2 = bit | (1 << jewel[cur]);
			for (int i = 0; i < k; i++) if (bit2 & (1 << i)) cnt2++;
		}

//		cout << cur << ' ' << cnt1 << '\n';

		for (auto nxt : adj[cur]) {
			if (!reachable[nxt.fr][bit] && cnt1 <= nxt.sc) {
				reachable[nxt.fr][bit] = 1;
				q.push({ nxt.fr, bit });
			}
			if (jewel[cur] != -1 && !reachable[nxt.fr][bit2] && cnt2 <= nxt.sc) {
				reachable[nxt.fr][bit2] = 1;
				q.push({ nxt.fr, bit2 });
			}
		}
	}
}

void solve() {
	cin >> n >> m >> k;
	memset(jewel, -1, sizeof(jewel));
	for (int i = 0; i < k; i++) {
		int a; cin >> a;
		jewel[a] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	bfs();

	int mx = 0;
	for (int i = 0; i < (1 << k); i++) {
		if (reachable[1][i]) {
			int cnt = 0;
			for (int j = 0; j < k; j++) if (i & (1 << j)) cnt++;
			mx = max(mx, cnt);
		}
	}
	cout << mx + (jewel[1] == -1 ? 0 : 1) << '\n';
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
