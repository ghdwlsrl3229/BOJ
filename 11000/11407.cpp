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

const int MAX_V = 220;
const int INF = 1000000000;

struct Edge {
	int v, c, f, d;
	Edge *rev;
	Edge(int v, int c, int d) :v(v), c(c), d(d), f(0), rev(nullptr) {}
	int getFlow() { return c - f; }
	void addFlow(int f1) {
		f += f1;
		rev->f -= f1;
	}
};
vector<Edge*> edge[MAX_V];

void addEdge(int u, int v, int f, int d) {
	Edge *e1 = new Edge(v, f, d), *e2 = new Edge(u, 0, d*-1);
	e1->rev = e2;
	e2->rev = e1;
	edge[u].push_back(e1);
	edge[v].push_back(e2);
}

pll MCMF(int S, int E) {
	int total_cost = 0, total_flow = 0;
	while (1) {
		int prev[MAX_V], dist[MAX_V];
		bool inQ[MAX_V] = { 0 };
		Edge* path[MAX_V] = { 0 };
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
			for (auto next : edge[curr]) {
				if (next->getFlow() > 0 && dist[next->v] > dist[curr] + next->d) {
					dist[next->v] = dist[curr] + next->d;
					prev[next->v] = curr;
					path[next->v] = next;

					if (!inQ[next->v]) {
						Q.push(next->v);
						inQ[next->v] = 1;
					}
				}
			}
		}
		if (prev[E] == -1) break;

		int flow = INF;
		for (int i = E; i != S; i = prev[i])
			flow = min(flow, path[i]->getFlow());

		for (int i = E; i != S; i = prev[i]) {
			total_cost += flow * (path[i]->d);
			path[i]->addFlow(flow);
		}
		total_flow += flow;
	}
	return { total_cost, total_flow };
}


int c[110][110], d[110][110];

void solve() {
	int N, M; cin >> N >> M;
	
	int S = N + M, E = N + M + 1;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		addEdge(S, i, a, 0);
	}
	for (int i = 0; i < M; i++) {
		int a; cin >> a;
		addEdge(i + N, E, a, 0);
	}

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) 
			cin >> c[i][j];

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) 
			cin >> d[i][j];

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			addEdge(j, i + N, c[i][j], d[i][j]);

	pll ans = MCMF(S, E);
	cout << ans.sc << '\n';
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
