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

const int MAX_V = 880;
const int INF = 1e9;

int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V];
vector<int> adj[MAX_V];

void solve() {
	int N, P; cin >> N >> P;
	//정점분할
	for (int i = 1; i <= N; i++) {
		int u = 2 * i, v = u + 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
		c[u][v] = 1;
	}

	//양방향 간선임을 주의해서 구현해야함.
	for (int i = 0; i < P; i++) {
		int a, b; cin >> a >> b;
		c[2 * a + 1][2 * b] = 1;
		c[2 * b + 1][2 * a] = 1;
		adj[2 * b + 1].push_back(2 * a);
		adj[2 * b].push_back(2 * a + 1);
		adj[2 * a + 1].push_back(2 * b);
		adj[2 * a].push_back(2 * b + 1);
	}

	int total = 0, S = 1*2+1, E = 2*2;
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
