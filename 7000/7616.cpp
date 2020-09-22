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

const int MAX_V = 11000;
const int INF = 1e9;

struct Edge {
	int to, c, f;
	Edge* dual;
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

void addEdge(int u, int v, int w) {
	Edge *e1 = new Edge(v * 2, 1), *e2 = new Edge(u * 2, 1);
	e1->dual = e2;
	e2->dual = e1;
	adj[u * 2 + 1].push_back(e1);
	adj[v * 2 + 1].push_back(e2);
}

int Edmond_Karp(int S, int E) {
	int total = 0;
	while (1) {
		int prev[MAX_V];
		Edge* path[MAX_V] = { 0 };
		memset(prev, -1, sizeof(prev));
		queue<int> q;
		q.push(S);
		while (q.size() && prev[E] == -1) {
			int cur = q.front();
			q.pop();
			for (Edge* e : adj[cur]) {
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

void Edmond_Karp2(int S, int E, int K) {
	while(K--){
		int prev[MAX_V];
		Edge* path[MAX_V] = { 0 };
		memset(prev, -1, sizeof(prev));
		queue<int> q;
		q.push(S);
		while (q.size() && prev[E] == -1) {
			int cur = q.front();
			q.pop();
			for (Edge* e : adj[cur]) {
				int nxt = e->to;
				if (e->f > 0 && prev[nxt] == -1) {
					q.push(nxt);
					prev[nxt] = cur;
					path[nxt] = e;
					if (nxt == E) break;
				}
			}
		}
		if (prev[E] == -1) break;
		
		vector<int> tmp;
		for (int i = E; i != S; i = prev[i]) {
			path[i]->addFlow(-1);
			if (i / 2 != prev[i] / 2) tmp.push_back(i / 2);

		}
		tmp.push_back(1);

		reverse(all(tmp));
		for (int i = 0; i < tmp.size(); i++) printf("%d ", tmp[i]);
		printf("\n");
	}
	printf("\n");
}

void solve() {
	for (int tc = 1;; tc++){
		int K, N;
		scanf("%d%d", &K, &N);
		if (K == 0 && N == 0) break;
		for (int i = 1; i <= 2 * N + 1; i++) adj[i].clear();
		for (int i = 1; i <= N; i++) {
			Edge* e1 = new Edge(i * 2 + 1, 1), *e2 = new Edge(i * 2, 0);
			e1->dual = e2;
			e2->dual = e1;
			adj[i * 2 + 1].push_back(e2);
			adj[i * 2].push_back(e1);
		}
		for (int i = 1; i <= N; i++) {
			int j; char c;
			while (1) {
				scanf("%d%c", &j, &c);
				addEdge(i, j, 1);
				if (c == '\n') break;
			}
		}

		int S = 1, E = 2;
		int total = Edmond_Karp(2 * S + 1, 2 * E);

		printf("Case %d:\n", tc);
		if (total < K) {
			cout << "Impossible\n\n";
			continue;
		}

		Edmond_Karp2(2 * S + 1, 2 * E, K);
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
