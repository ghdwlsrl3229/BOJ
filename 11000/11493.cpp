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

const int MAX_V = 550;
const int INF = 1000000000;

int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V];
int d[MAX_V][MAX_V];
vector<int> adj[MAX_V];

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
				int temp = (f[curr][next] < 0 ? -1 : 1) * d[curr][next];
				if (c[curr][next] - f[curr][next] > 0 && dist[curr] + temp < dist[next]) {
					dist[next] = dist[curr] + temp;
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
			total_cost += (f[prev[i]][i] < 0 ? -flow : flow) * d[prev[i]][i];
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		total_flow += flow;
	}
	return { total_cost, total_flow };
}

vector<int> adj2[550];
bool vcolor[550], ccolor[550];

void init(int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			c[i][j] = f[i][j] = d[i][j] = 0;
		}
		adj[i].clear();
	}
}

void solve() {
	int N, M; cin >> N >> M;
	init(N + 2);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		c[a][b] = c[b][a] = INF;
		d[a][b] = d[b][a] = 1;
	}

	int S = N + 1, E = N + 2;
	for (int i = 1; i <= N; i++) {
		cin >> vcolor[i];
		if (vcolor[i] == 1) {
			//i->E
			c[i][E] = 1;
			c[E][i] = 0;
			adj[i].push_back(E);
			adj[E].push_back(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		cin >> ccolor[i];
		if (ccolor[i] == 1) {
			//S->i
			c[S][i] = 1;
			c[i][S] = 0;
			adj[i].push_back(S);
			adj[S].push_back(i);
		}
	}

	pll ans = MCMF(S, E);
	cout << ans.fr << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if (1) {
		int T; cin >> T;
		while (T--) solve();
	}
	else {
		solve();
	}
	return 0;
}
