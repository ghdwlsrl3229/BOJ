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

const int MAX_V = 200000;
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

int R, C, cy, cx; 
int arr[330][330];
int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0, 0 };

int toInt(int y, int x) {
	return y * C + x;
}

void solve() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> arr[i][j];
	cin >> cy >> cx;

	int S = 180000, E = 180001;
	addEdge(S, 2 * toInt(cy, cx), INF, 0);
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			int cur = toInt(i, j);
			addEdge(2 * cur, 2 * cur + 1, arr[i][j], 0);
		}

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 0) continue;
			int cur = toInt(i, j);
			bool isout = 0;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= R || nx >= C) {
					isout = 1;
					continue;
				}
				if (arr[ny][nx] == 0) continue;

				int nxt = toInt(ny, nx);
				addEdge(2 * cur + 1, 2 * nxt, INF, 0);
			}
			if (isout) addEdge(2 * cur + 1, E, INF, 0);
		}

	ll ans = max_flow(S, E);
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
