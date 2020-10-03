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

struct Edge {
	ll to, c, f;
	Edge *dual;
	Edge(ll to1, ll c1) : to(to1), c(c1), f(0), dual(nullptr) {}
	ll spare() {
		return c - f;
	}
	void addFlow(ll f1) {
		f += f1;
		dual->f -= f1;
	}
};

vector<Edge*> adj[MAX_V]; 

void addEdge(int from, int to, ll c1, ll c2) {
	Edge *e1 = new Edge(to, c1), *e2 = new Edge(from, c2);
	e1->dual = e2;
	e2->dual = e1;
	adj[from].push_back(e1);
	adj[to].push_back(e2);
}

ll max_flow(int S, int E) {
	ll total = 0;
	while (1) {
		int prev[MAX_V];
		Edge *path[MAX_V] = { 0 };
		fill(prev, prev + MAX_V, -1);
		queue<int> Q;
		Q.push(S);
		while (!Q.empty() && prev[E] == -1) {
			int curr = Q.front();
			Q.pop();
			for (Edge *e : adj[curr]) {
				int next = e->to;
				if (e->spare() > 0 && prev[next] == -1) {
					Q.push(next);
					prev[next] = curr;
					path[next] = e;
					if (next == E) break;
				}
			}
		}
		if (prev[E] == -1) break;

		ll flow = INF;
		for (int i = E; i != S; i = prev[i])
			flow = min(flow, path[i]->spare());
		for (int i = E; i != S; i = prev[i])
			path[i]->addFlow(flow);
		total += flow;
	}
	return total;
}

ll flow(int S, int E) {
	int prev[MAX_V];
	Edge *path[MAX_V] = { 0 };
	fill(prev, prev + MAX_V, -1);
	queue<int> Q;
	Q.push(S);
	while (!Q.empty() && prev[E] == -1) {
		int curr = Q.front();
		Q.pop();
		for (Edge *e : adj[curr]) {
			int next = e->to;
			if (e->spare() > 0 && prev[next] == -1) {
				Q.push(next);
				prev[next] = curr;
				path[next] = e;
				if (next == E) break;
			}
		}
	}
	if (prev[E] == -1) return 0;

	ll flow = INF;
	for (int i = E; i != S; i = prev[i])
		flow = min(flow, path[i]->spare());
	return flow;
}

int N, M, SS, EE;

void solve() {
	cin >> N >> M >> SS >> EE;
	int S = 402, E = 403;
	addEdge(S, 2 * SS, INF, 0);
	addEdge(2 * EE + 1, E, INF, 0);
	for (int i = 1; i <= N; i++) {
		int cost; cin >> cost;
		addEdge(2 * i, 2 * i + 1, cost, 0);
	}
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		addEdge(2 * a + 1, 2 * b, INF, 0);
		addEdge(2 * b + 1, 2 * a, INF, 0);
	}
	max_flow(S, E);

	vector<int> ans;
	for (int i = 1; i <= N; i++) {
		ll a = flow(S, 2 * i);
		ll b = flow(S, 2 * i + 1);
		if (a && !b) ans.push_back(i);
	}
	for (int i : ans) cout << i << ' ';
	cout << '\n';
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
