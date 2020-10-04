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

const int MAX_V = 900;
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

pll MCMF(int S, int E) {
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

void solve() {
	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		while (a--) {
			int b, c; cin >> b >> c;
			addEdge(i, b + N, 1, c);
		}
	}
	int S = N + M + 1, E = N + M + 2;
	for (int i = 1; i <= N; i++) addEdge(S, i, 1, 0);
	for (int i = N + 1; i <= N + M; i++) addEdge(i, E, 1, 0);

	pll ans = MCMF(S, E);
	cout << ans.sc << '\n';
	cout << ans.fr << "\n";
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
