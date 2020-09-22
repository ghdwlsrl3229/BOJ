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
	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int t; cin >> t;
		while (t--) {
			int a; cin >> a;
			adj[a + 200].push_back(i);
			adj[i].push_back(a + 200);
			c[i][a + 200] = 1;
		}
	}

	int total = 0, S = 401, E = 402;
	for (int i = 1; i <= N; i++) {
		adj[S].push_back(i);
		adj[i].push_back(S);
		c[S][i] = 1;
	}
	for (int i = 201; i <= M + 200; i++) {
		adj[i].push_back(E);
		adj[E].push_back(i);
		c[i][E] = 1;
	}

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
	cout << total << '\n';
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
