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

const int MAX_V = 330;
const int INF = 1e9;

struct Edge {
	int to, c, f;
	Edge *dual; //역방향 간선
	Edge() : Edge(-1, 0) {}
	Edge(int to1, int c1) : to(to1), c(c1), f(0), dual(nullptr) {}
	int spare() {
		return c - f;
	}
	void addFlow(int f1) {
		f += f1;
		dual->f -= f1;
	}
};

vector<Edge*> adj[MAX_V];

int edmond_karp(int S, int E) {
	int total = 0;
	while (1) {
		int prev[MAX_V];
		Edge *path[MAX_V] = { 0 }; //경로상의 간선 저장
		memset(prev, -1, sizeof(prev));
		queue<int> q;
		q.push(S);

		while (q.size() && prev[E] == -1) {
			int cur = q.front();
			q.pop();
			for (Edge * e : adj[cur]) {
				int nxt = e->to;
				if (e->spare() > 0 && prev[nxt] == -1) {
					q.push(nxt);
					prev[nxt] = cur;
					path[nxt] = e;
					if (nxt == E) break;
				}
			}
		}
		if (prev[E] == -1) break;

		int flow = INF;
		for (int i = E; i != S; i = prev[i])
			flow = min(flow, path[i]->spare());
		for (int i = E; i != S; i = prev[i])
			path[i]->addFlow(flow);
		total += flow;
	}
	return total;
}

void solve() {
	int N, M; cin >> N >> M;

	for (int i = 1; i <= N; i++) adj[i].clear();

	for (int i = 0; i < M; i++) {
		int f, t, b; cin >> f >> t >> b;
		Edge *e1 = new Edge(t, b), *e2 = new Edge(f, 0);
		e1->dual = e2;
		e2->dual = e1;
		adj[t].push_back(e2);
		adj[f].push_back(e1);
	}

	edmond_karp(1, N);
//	cout << total << '\n';

	vector<pair<int, Edge*>> full_edges;
	for (int i = 1; i <= N; i++)
		for (auto& e : adj[i])
			if (e->c > 0 && e->spare() == 0)
				full_edges.push_back({ i, e });

	int cnt = 0;
	for (auto e : full_edges) {
		int S = e.first, E = e.second->to;
		int prev[MAX_V];
		Edge *path[MAX_V] = { 0 }; //경로상의 간선 저장
		memset(prev, -1, sizeof(prev));
		queue<int> q;
		q.push(S);

		while (q.size() && prev[E] == -1) {
			int cur = q.front();
			q.pop();
			for (Edge * e : adj[cur]) {
				int nxt = e->to;
				if (e->spare() > 0 && prev[nxt] == -1) {
					q.push(nxt);
					prev[nxt] = cur;
					path[nxt] = e;
					if (nxt == E) break;
				}
			}
		}
		if (prev[E] == -1) cnt++;
	}
	cout << cnt << "\n";
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
