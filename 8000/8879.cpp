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

const ll INF = 1e9;
vector<ll> Dijkstra(int N, int s, vector<pll> edges[]) {
	vector<ll> dist(N, INF);
	dist[s] = 0;
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.push({ 0, s });
	while (pq.size()) {
		auto p = pq.top(); pq.pop();
		int i = p.second;
		ll d = p.first;
		if (d > dist[i]) continue;
		for (auto& e : edges[i]) {
			int j = e.first;
			ll d2 = d + e.second;
			if (d2 < dist[j]) {
				dist[j] = d2;
				pq.push({ d2, j });
			}
		}
	}
	return dist;
}

struct Edge {
	int to, c, f;
	Edge *dual;
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

const int MAX_V = 30000;
vector<Edge*> adj2[MAX_V];
ll edmond_karp(int S, int E) {
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
			for (Edge *e : adj2[curr]) {
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

		int flow = INF;
		for (int i = E; i != S; i = prev[i])
			flow = min(flow, path[i]->spare());
		for (int i = E; i != S; i = prev[i])
			path[i]->addFlow(flow);
		total += flow;
	}
	return total;
}

void addEdge(int s, int e, int w) {
	Edge* e1 = new Edge(e, w), *e2 = new Edge(s, 0);
	e1->dual = e2;
	e2->dual = e1;
	adj2[s].push_back(e1);
	adj2[e].push_back(e2);
}

int n, m, c;
vector<pll> adj[MAX_V];
vector<ll> dist;
int cars[MAX_V];
map<ll, vector<pll>> mp;
int S = 25001, E = 25002;

ll f(vector<pll>& v) {
	//TODO:
	//플로우 그래프를 만들고 에드몬드 카프 알고리즘을 돌린다.
	//이 때 최단거리를 이루는 간선만 살려서 만들어 놓고(default)
	//매 f함수 실행마다 소스에서 나오는 간선만 새로 만들고 제거해준다.
	for (int i = 1; i <= n; i++) {
		for (Edge* j : adj2[i]) {
			j->f = 0;
		}
	}

	for (pll p : v) {
		addEdge(S, p.fr, p.sc);
	}
	ll total = edmond_karp(S, E);
	for (pll p : v) {
		adj2[S].pop_back();
		adj2[p.fr].pop_back();
	}
	return total;
}

void solve() {
	cin >> n >> m >> c;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	for (int i = 0; i < c; i++) {
		int a; cin >> a;
		cars[a]++;
	}

	dist = Dijkstra(n + 1, 1, adj);
	for (int i = 1; i <= n; i++) {
		if (cars[i]) {
			mp[dist[i]].push_back({ i, cars[i] });
		}
	}

	addEdge(1, E, INF);
	for (int i = 1; i <= n; i++) {
		for (auto j : adj[i]) {
			if (dist[i] + j.sc == dist[j.fr]) {
				addEdge(j.fr, i, 1);
			}
		}
	}

	ll ans = 0;
	for (auto& i : mp) {
		ans += f(i.second);
	}
	cout << ans << '\n';
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
