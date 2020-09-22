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

const int MAX_V = 440;
const int INF = 1e9;

int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V];
vector<int> adj[MAX_V];

void solve() {
	int N, P; cin >> N >> P;
	for (int i = 0; i < P; i++) {
		int a, b; cin >> a >> b;
		c[a][b] = 1;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int total = 0, S = 1, E = 2;
	while (1) {
		int prev[MAX_V];
		memset(prev, -1, sizeof(prev));
		queue<int> q;
		q.push(S);
		while (q.size() && prev[E] == -1) {
			int cur = q.front();
			q.pop();
			for (int nxt : adj[cur]) {
				if (c[cur][nxt] - f[cur][nxt] > 0 && prev[nxt] == -1) {
					q.push(nxt);
					prev[nxt] = cur;
					if (nxt == E) break;
				}
			}
		}

		if (prev[E] == -1) break;

		int flow = INF;
		for (int i = E; i != S; i = prev[i])
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);

		for (int i = E; i != S; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}

		total += flow;
	}
	cout << total << "\n";
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
