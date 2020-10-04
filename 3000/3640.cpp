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

const int MAX_V = 2200;
const int INF = 1000000000;

int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V]; 
int d[MAX_V][MAX_V];
vector<int> adj[MAX_V]; 

void addEdge(int from, int to, int cap, int cost) {
	c[from][to] = cap;
	c[to][from] = 0;
	adj[from].push_back(to);
	adj[to].push_back(from);
	d[from][to] = cost;
	d[to][from] = -cost;
}

pll MCMF(int S, int E, int K) {
	int total_cost = 0, total_flow = 0;
	while(K--) {
		int prev[MAX_V], dist[MAX_V];
		bool inQ[MAX_V] = { 0 };
		queue<int> Q;
		fill(prev, prev + MAX_V, -1);
		fill(dist, dist + MAX_V, INF);
		dist[S] = 0;
		inQ[S] = 1;
		Q.push(S);

		while (!Q.empty()) {
			int curr = Q.front();
			Q.pop();
			inQ[curr] = 0;
			for (int next : adj[curr]) {
				if (c[curr][next] - f[curr][next] > 0 && dist[curr] + d[curr][next] < dist[next]) {
					dist[next] = dist[curr] + d[curr][next];
					prev[next] = curr;

					if (!inQ[next]) {
						Q.push(next);
						inQ[next] = 1;
					}
				}
			}
		}
		if (prev[E] == -1) break;

		int flow = INF;
		for (int i = E; i != S; i = prev[i])
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);

		for (int i = E; i != S; i = prev[i]) {
			total_cost += flow * d[prev[i]][i];
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		total_flow += flow;
	}
	return { total_cost, total_flow };
}

void init(int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			c[i][j] = f[i][j] = d[i][j] = 0;
		}
		adj[i].clear();
	}
}

void solve() {
	int N, M;
	while (scanf("%d%d", &N, &M) > 0) {
		init(2 * N + 2);
		for (int i = 1; i <= N; i++) {
			addEdge(2 * i, 2 * i + 1, 1, 0);
		}
		for (int i = 0; i < M; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			addEdge(2 * a + 1, 2 * b, 1, c);
		}
		int S = 3, E = 2 * N;

		pll ans = MCMF(S, E, 2);
		cout << ans.fr << '\n';
	}
}

int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	if (0) {
		int T; cin >> T;
		while (T--) solve();
	}
	else {
		solve();
	}
	return 0;
}
