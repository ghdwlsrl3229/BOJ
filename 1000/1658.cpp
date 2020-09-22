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

const int MAX_V = 110000;
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
	Edge *e1 = new Edge(v, w), *e2 = new Edge(u, 0);
	e1->dual = e2;
	e2->dual = e1;
	adj[u].push_back(e1);
	adj[v].push_back(e2);
}

Edge *path[MAX_V];
int prv[MAX_V];
int Edmond_Karp(int S, int E) {
	int total = 0;
	while (1) {
		memset(prv, -1, sizeof(prv));
		memset(path, 0, sizeof(path));
		queue<int> Q;
		Q.push(S);
		while (!Q.empty() && prv[E] == -1) {
			int curr = Q.front();
			Q.pop();
			for (Edge *e : adj[curr]) {
				int next = e->to;
				if (e->spare() > 0 && prv[next] == -1) {
					Q.push(next);
					prv[next] = curr;
					path[next] = e;
					if (next == E) break;
				}
			}
		}
		if (prv[E] == -1) break;

		int flow = INF;
		for (int i = E; i != S; i = prv[i])
			flow = min(flow, path[i]->spare());
		for (int i = E; i != S; i = prv[i])
			path[i]->addFlow(flow);
		total += flow;
	}
	return total;
}

int pighouse(int k, int day) {
	return 1000 * day + k;
}

void solve() {
	int N, M; cin >> M >> N;
	int S = 0, E = 1;
	for (int i = 0; i < M; i++) {
		int a; cin >> a;
		addEdge(S, pighouse(i, 1), a);
	}

	//손님의 노드번호를 2~N+1로 설정함
	bool opened[1100] = { 0 };
	for (int i = 2; i <= N + 1; i++) {
		int a, b; cin >> a;
		memset(opened, 0, sizeof(opened));

		for (int j = 0; j < a; j++) {
			int k; cin >> k;
			opened[k - 1] = 1;
			addEdge(pighouse(k - 1, i - 1), i, INF);
		}
		cin >> b;
		addEdge(i, E, b);

		vector<int> open_houses;
		for (int j = 0; j < M; j++) {
			if (opened[j]) open_houses.push_back(j);
			else addEdge(pighouse(j, i - 1), pighouse(j, i), INF);
		}
		if (i < N + 1) {
			for (int j : open_houses)
				for (int k : open_houses)
					addEdge(pighouse(j, i - 1), pighouse(k, i), INF);
		}
	}

	cout << Edmond_Karp(S, E) << '\n';
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
