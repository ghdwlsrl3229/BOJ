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

const int MAX_V = 1100;
const int INF = 1000000000;

int c[MAX_V][MAX_V]; //용량
int f[MAX_V][MAX_V]; //유량
int d[MAX_V][MAX_V]; //비용
vector<int> adj[MAX_V]; //인접 리스트

void addEdge(int from, int to, int cap, int cost) {
	c[from][to] = cap;
	c[to][from] = 0;
	adj[from].push_back(to);
	adj[to].push_back(from);
	d[from][to] = cost;
	d[to][from] = -cost;
}

pair<int, int> MCMF(int S, int E) {
	int total_cost = 0, total_flow = 0;
	while (1) {
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
				int tmp = f[curr][next] < 0 ? -d[curr][next] : d[curr][next];
				if (c[curr][next] - f[curr][next] > 0 && dist[curr] + tmp < dist[next]) {
					dist[next] = dist[curr] + tmp;
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
			total_cost += flow * (f[prev[i]][i] < 0 ? -d[prev[i]][i] : d[prev[i]][i]);
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		total_flow += flow;
	}
	return { total_cost, total_flow };
}


void solve() {
	int N, M; cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, w; cin >> a >> b >> w;
		c[a][b] = c[b][a] = 1;
		d[a][b] = d[b][a] = w;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int S = N + 1, E = N + 2;
	addEdge(S, 1, 2, 0);
	addEdge(N, E, 2, 0);
	pll ans = MCMF(S, E);
	cout << ans.fr << '\n';
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
